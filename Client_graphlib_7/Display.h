#ifndef Display_h
#define Display_h

#include <iostream>
#include "stdio.h"
#include <stdlib.h>


#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <windows.h>
#include <fstream>

#include "GraphicsLib.h"

using namespace std;

int hexToRGB(uint16_t hexValue)
{
    unsigned r = (hexValue & 0xF800) >> 11;
    unsigned g = (hexValue & 0x07E0) >> 5;
    unsigned b = hexValue & 0x001F;

    r = (r * 255) / 31;
    g = (g * 255) / 63;
    b = (b * 255) / 31;

    return (r << 16) | (g << 8) | b;
}


class Display : public GraphicsLib
{
public:
    Display(uint_least16_t w, uint_least16_t h, int PORT = 777, string SERVERADDR = "127.0.0.1") : GraphicsLib(w, h)
    
    {

        my_sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (my_sock == INVALID_SOCKET)
        {
            printf("socket() error: %d\n", WSAGetLastError());
            WSACleanup();
        }

        HOSTENT* hst;

        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT);

        if (inet_addr(SERVERADDR.c_str()))
            dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR.c_str());
        else
            if (hst = gethostbyname(SERVERADDR.c_str()))
                dest_addr.sin_addr.s_addr = ((unsigned long**)hst->h_addr_list)[0][0];
            else
            {
                printf("Unknown host: %d\n", WSAGetLastError());
                closesocket(my_sock);
                WSACleanup();
            }
    
 


    };

    void fillScreen(uint_least16_t color) {

        int hexcolor = hexToRGB(color);

        snprintf(buffer, buffer_length, "clear_display: %06x", hexcolor);
        sendCommand(buffer);
    };

    void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) {
        int hexcolor = hexToRGB(color);
        snprintf(buffer, buffer_length, "draw_pixel: %i %i %06x", x0, y0, hexcolor);
        sendCommand(buffer);
    };

    void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color) {
        int hexcolor = hexToRGB(color);
        snprintf(buffer, buffer_length, "draw_line: %i %i %i %i %06x", x0, y0, x1, y1, hexcolor);
        sendCommand(buffer);
    };

    void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) {
        int hexcolor = hexToRGB(color);
        snprintf(  buffer, buffer_length, "draw_rectangle: %i %i %i %i %06x", x0, y0, w, h, hexcolor);
        sendCommand(buffer);
    };

    void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) {
        int hexcolor = hexToRGB(color);
        snprintf(  buffer, buffer_length, "fill_rectangle: %i %i %i %i %06x", x0, y0, w, h, hexcolor);
        sendCommand(buffer);
    };

    void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) {
        int hexcolor = hexToRGB(color);
        snprintf( buffer, buffer_length, "draw_ellipse: %i %i %i %i %06x", x0, y0, r_x, r_y, hexcolor);
        sendCommand(buffer);
    };

    void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) {
        int hexcolor = hexToRGB(color);
        snprintf( buffer, buffer_length, "fill_ellipse: %i %i %i %i %06x", x0, y0, r_x, r_y, hexcolor);
        sendCommand(buffer);
    };


    int_least16_t drawChar(int_least16_t x, int_least16_t y, char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) 
    {
        return 0;
    }

    int_least16_t drawChar(int_least16_t x, int_least16_t y, unsigned char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size)  
    {
        return 0;
    }
       
    int_least16_t drawText(int_least16_t x, int_least16_t y, const char* s, uint_least16_t color, uint_least16_t bg, uint_least8_t size) 
        {
            setlocale(LC_ALL, "RUS");
            int hexcolor = hexToRGB(color);
            snprintf(buffer, buffer_length, "draw_text: %i %i %06x %i %i %s", x, y, hexcolor, bg, size, s);
            sendCommand(buffer);
            return 0;
        }
    
        void loadSprite(uint_least8_t index, int_least16_t width, int_least16_t height, char* data) 
        {
            
            snprintf(buffer, buffer_length, "load_sprite: %i %i %i %s", index, width, height, data);
            sendCommand(buffer);
          
            Send_sprite(data);
          
          
            
        }

        void showSprite(uint_least8_t index, uint_least16_t x, uint_least16_t y) 
        {
            snprintf(buffer, buffer_length, "show_sprite: %i %i %i", index, x, y );
            sendCommand(buffer);
        }


        void setOrientation(uint_least8_t orientation)
        {
            snprintf(buffer, buffer_length, "set_orientation: %i", orientation);
            sendCommand(buffer);
        }

        void getWidth()
        {
            snprintf(buffer, buffer_length, "get_width:");
            sendCommand(buffer);
            Recv();
        }

        void getHeight()
        {
            snprintf(buffer, buffer_length, "get_height:");
            sendCommand(buffer);
            Recv();
           
        }

        /*
        void getSize(uint_least16_t w, uint_least16_t h)
        {
            snprintf(buffer, buffer_length, "get_size: %i %i", w,h);
            sendCommand(buffer);

        }
        */

        void Recv()
        {
            char buff2[1000];

            sockaddr_in server_addr;
            int server_addr_size = sizeof(server_addr);
            int n;
         

            
                 n = recvfrom(my_sock, &buff2[0], sizeof(buff2) - 1, 0, (sockaddr*)&server_addr, &server_addr_size);
                if (n == SOCKET_ERROR)
                {
                    printf("recvfrom() error: % d \n", WSAGetLastError());
                    closesocket(my_sock);
                    WSACleanup();
                }
                buff2[n] = 0;
                printf("Server: %s\n", &buff2[0]);
        }

        void Send_sprite(char* data)
        {
            WSADATA wsaData;
            int winsock_result = WSAStartup(MAKEWORD(2, 2), &wsaData);

            SOCKET client_socket;
            client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

            if (client_socket == INVALID_SOCKET)
            {
                WSACleanup();
            }

            string  ip_address = "127.0.0.1";
            int port = 6666;

            SOCKADDR_IN client;
            client.sin_family = AF_INET;
            client.sin_port = htons(port);
            client.sin_addr.s_addr = inet_addr(ip_address.c_str());

            if (bind(client_socket, (SOCKADDR*)&client, sizeof(client)) == SOCKET_ERROR)
            {
                closesocket(client_socket);
                WSACleanup();
            }

            SOCKADDR_IN server;
            int server_sizeof = sizeof(server);

            int const buffer_size = 1024;
            char buffer[buffer_size];

            if (recvfrom(client_socket, buffer, buffer_size, 0, (SOCKADDR*)&server, &server_sizeof) == SOCKET_ERROR)
            {
                closesocket(client_socket);
                WSACleanup();
 
            }
            else
            {
                FILE* file;
                file = fopen(data, "rb");
               
                if (file == NULL)
                {
                    std::cout << "Не удалось открыть файл." << std::endl;
                }
                fseek(file, 0, SEEK_END);
                int file_size = ftell(file);

                size_t reading_size;
                int part = 0;

                while ((part * buffer_size) < file_size)
                {
                    fseek(file, (part * buffer_size), SEEK_SET);
                    reading_size = fread(buffer, 1, buffer_size, file);

                    if (sendto(client_socket, buffer, reading_size, 0, (SOCKADDR*)&server, server_sizeof) == SOCKET_ERROR)
                    {
                        fclose(file);
                        closesocket(client_socket);
                        WSACleanup();
                        exit(1);
                    }
                    part++;
                }
                std::cout << " Отправлено " << part << " частей по " << buffer_size << " байт." << std::endl;

                strcpy(buffer, "QUIT");
                if (sendto(client_socket, buffer, buffer_size, 0, (SOCKADDR*)&server, server_sizeof) == SOCKET_ERROR)
                {
                    fclose(file);
                    closesocket(client_socket);
                    WSACleanup();
                }
                fclose(file);
            }
            closesocket(client_socket);
            WSACleanup();
        }


private:
    static const unsigned char buffer_length = 1000;
    char buffer[buffer_length];

    sockaddr_in dest_addr;
    SOCKET my_sock;

    void sendCommand(const char* command) {
        std::cout << "sendCommand: " << command << std::endl;
        sendto(my_sock, &command[0], strlen(&command[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    }
};

#endif 

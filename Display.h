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
            int hexcolor = hexToRGB(color);
            snprintf(buffer, buffer_length, "draw_text: %i %i %06x %i %i %s", x, y, hexcolor, bg, size, s);
            sendCommand(buffer);
            return 0;
        }
        void loadSprite(uint_least8_t index, int_least16_t width, int_least16_t height, char* data) 
        {}
        void showSprite(uint_least8_t index, uint_least16_t x, uint_least16_t y) 
        {}


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

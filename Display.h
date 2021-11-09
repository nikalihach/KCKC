#ifndef Display_h
#define Display_h

#include <iostream>
#include "stdio.h"
#include <stdlib.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <windows.h>
#define PORT 777
#define SERVERADDR "127.0.0.1"


#include "GraphicsLib.h"

class Display : public GraphicsLib
{
public:
    Display(uint_least16_t w, uint_least16_t h) : GraphicsLib(w, h) 
    
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

        if (inet_addr(SERVERADDR))
            dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
        else
            if (hst = gethostbyname(SERVERADDR))
                dest_addr.sin_addr.s_addr = ((unsigned long**)hst->h_addr_list)[0][0];
            else
            {
                printf("Unknown host: %d\n", WSAGetLastError());
                closesocket(my_sock);
                WSACleanup();
            }
    };

    void fillScreen(uint_least32_t color) {

        snprintf(buffer, buffer_length, "clear_display: %06x", color);
        sendCommand(buffer);
    };

    void drawPixel(int_least16_t x0, int_least16_t y0, uint_least32_t color) {
        snprintf(buffer, buffer_length, "draw_pixel: %i %i %06x", x0, y0, color);
        sendCommand(buffer);
    };

    void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least32_t color) {
        snprintf(
            buffer, buffer_length, "draw_line: %i %i %i %i %06x", x0, y0, x1, y1, color
        );
        sendCommand(buffer);
    };

    void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least32_t color) {
        snprintf(
            buffer, buffer_length, "draw_rectangle: %i %i %i %i %06x", x0, y0, w, h, color
        );
        sendCommand(buffer);
    };

    void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least32_t color) {
        snprintf(
            buffer, buffer_length, "fill_rectangle: %i %i %i %i %06x", x0, y0, w, h, color
        );
        sendCommand(buffer);
    };

    void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least32_t color) {
        snprintf(
            buffer, buffer_length, "draw_ellipse: %i %i %i %i %06x", x0, y0, r_x, r_y, color
        );
        sendCommand(buffer);
    };

    void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least32_t color) {
        snprintf(
            buffer, buffer_length, "fill_ellipse: %i %i %i %i %06x", x0, y0, r_x, r_y, color
        );
        sendCommand(buffer);
    };

private:
    static const unsigned char buffer_length = 50;
    char buffer[buffer_length];

    sockaddr_in dest_addr;
    SOCKET my_sock;

    void sendCommand(const char* command) {
        std::cout << "sendCommand: " << command << std::endl;
        sendto(my_sock, &command[0], strlen(&command[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    }
};

#endif 

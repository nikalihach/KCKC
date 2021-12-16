#pragma once
#include <string>
using namespace std;

bool HEX(string str);
int Ñonverting(char* str);
void Parse(char* buff, struct Command* com);


struct Command {
    string name;
    int r, g, b = 9999999;
    int first = 9999999;
    int second = 9999999;
    int third = 9999999;
    int fourth = 9999999;
    int success = 9999999;
    int x, y, font_number, size = 9999999;

    char text[100];
};


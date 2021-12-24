#include <iostream>
#include <string>

using namespace std;

#include "Parser.h"
bool HEX(string str)
{

    if (str.size() != 6)
    {
        System::Windows::Forms::MessageBox::Show("Error: size "+ str.size());
        return false;

    }
    else
        for (int i = 0; i < str.size(); i++)
        {
            if ((str[i] > 'f') || (str[i] < '0') || ((str[i] > '9') && (str[i] < 'A')) || ((str[i] > 'F') && (str[i] < 'a')))
            {
                return false;
                System::Windows::Forms::MessageBox::Show("Error no hex ");
            }
        }
    return true;
}

int Сonverting(char* str)
{
    long lnum;
    int num;
    char* end;

    lnum = strtol(str, &end, 10);
    if (end == str)
    {
        System::Windows::Forms::MessageBox::Show("Error: string ");
        return 9999999;

    }

    if ((lnum < -32768) || (lnum > 32768))
    {
        System::Windows::Forms::MessageBox::Show("Error:size ");
        return 9999999;
    }

    num = (int)lnum;
    return num;
}


void Parse(char* buff, struct Command* com)
{
    int k;
    char* arr[100];
    char* str;
    char* next_token1 = NULL;
    str = strtok_s(buff, ",;:", &next_token1);
    k = 0;
    while (str != NULL)
    {
        arr[k] = str;
        k++;
        str = strtok_s(NULL, " ,.", &next_token1);
    }

    int num;
    char* end;
    int error = 0;

    com->name = arr[0];
    if (com->name == "draw_text")//6+text
    {
        
        com->x = Сonverting(arr[1]);
        if (com->x == 9999999)
        {
            error = 1;
        }
        
        com->y = Сonverting(arr[2]);
        if (com->y == 9999999)
        {
            error = 1;
        }

        if (!HEX(arr[3]))
        {
            cout << "ERROR: Неправильный параметр color" << endl;
            error = 1;
        }

        num = strtol(arr[3], &end, 16);
        com->r = num / 0x10000;
        com->g = (num / 0x100) % 0x100;
        com->b = num % 0x100;

        com->font_number = stoi(arr[4], 0, 10);

        if (com->font_number < 0 || com->font_number> 65535)
        {
            cout << "Error: значение параметра font_number за диапазоном допустимых значений " << endl;
            error = 1;
        }

        com->size = stoi(arr[5], 0, 10);

        if (com->size < 0 || com->size> 65535)
        {
            cout << "Error: значение параметра lenght за диапазоном допустимых значений " << endl;
            error = 1;
        }

        string s;
       
        for (int i = 6; i <k; i++)
        {
            s = s + arr[i]+ " ";
        }
        strncpy(com->text, s.c_str(), 44);

        if (error == 1)
        {
            com->success = 0;
        }
        else
        com->success = 1;
    }

    else {
        switch (k)
        {
       
        case 2:
            com->name = arr[0];

            if (com->name == "clear_display")
            {
                if (!HEX(arr[1]))
                {
                    System::Windows::Forms::MessageBox::Show("Error: Неправильный параметр color ");
                    error = 1;
                    com->success = 0;
                }
                if (error == 1)break;


                num = strtol(arr[1], &end, 16);

                com->r = num / 0x10000;
                com->g = (num / 0x100) % 0x100;
                com->b = num % 0x100;

                com->success = 1;
                cout << "Принято" << endl;
                break;
            }

            else
            {
                System::Windows::Forms::MessageBox::Show("Error: Неправильная команда ");
                com->success = 0;
                break;
            }

        case 4:
            com->name = arr[0];

            if (com->name == "draw_pixel")
            {
                com->first = Сonverting(arr[1]);
                if (com->first == 9999999)
                {
                    error = 1;
                    com->success = 0;
                }
                if (error == 1) break;

                com->second = Сonverting(arr[2]);
                if (com->second == 9999999)
                {
                    error = 1;
                    com->success = 0;
                }
                if (error == 1) break;

                //color
                if (!HEX(arr[3]))
                {
                    System::Windows::Forms::MessageBox::Show("Error: Неправильный параметр color ");
                    error = 1;
                    com->success = 0;
                }
                if (error == 1)break;

                num = strtol(arr[3], &end, 16);

                com->r = num / 0x10000;
                com->g = (num / 0x100) % 0x100;
                com->b = num % 0x100;

                com->success = 1;
                cout << "Принято" << endl;
                break;
            }

            else
            {
                System::Windows::Forms::MessageBox::Show("Error: Неправильная команда ");
                com->success = 0;
                break;
            }

        case 6:

            com->name = arr[0];


            if (com->name == "draw_line" || com->name == "draw_rectangle" || com->name == "fill_rectangle" || com->name == "draw_ellipse" || com->name == "fill_ellipse")
            {
                // System::Windows::Forms::MessageBox::Show ("Норм " );

            }
            else {
                System::Windows::Forms::MessageBox::Show("Error: Неправильное название команды ");
                com->success = 0;
                error = 1;
            }
            if (error == 1)break;

            com->first = Сonverting(arr[1]);
            if (com->first == 9999999)
            {
                error = 1;
                com->success = 0;
            }
            if (error == 1) break;

            com->second = Сonverting(arr[2]);
            if (com->second == 9999999)
            {
                error = 1;
                com->success = 0;
            }
            if (error == 1) break;

            com->third = Сonverting(arr[3]);
            if (com->third == 9999999)
            {
                error = 1;
                com->success = 0;
            }
            if (error == 1) break;

            com->fourth = Сonverting(arr[4]);
            if (com->fourth == 9999999)
            {
                error = 1;
                com->success = 0;
            }
            if (error == 1) break;


            if (HEX(arr[5]) == false)
            {
                System::Windows::Forms::MessageBox::Show("Error: Неправильный параметр color ... ");
                error = 1;
                com->success = 0;
            }
            if (error == 1)break;


            num = strtol(arr[5], &end, 16);
            com->r = num / 0x10000;
            com->g = (num / 0x100) % 0x100;
            com->b = num % 0x100;

            com->success = 1;
            cout << "Принято" << endl;
            break;

        default:

            com->success = 0;
            System::Windows::Forms::MessageBox::Show("Error: Неправильноe количество параметров ");
            cout << "Error: Неправильноe количество параметров" << endl;
            break;
        }
    }
}

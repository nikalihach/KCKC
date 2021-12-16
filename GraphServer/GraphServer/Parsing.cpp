

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

int Ñonverting(char* str)
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
    str = strtok_s(buff, " ,.;:", &next_token1);
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


    switch (k)
    {
    case 2:
        com->name = arr[0];
        if (com->name != "clear_display")
        {
            System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíîå íàçâàíèå êîìàíäû ");
            com->success = 0;
            error = 1;
        }
        if (error == 1)break;

        if (!HEX(arr[1]))
        {
            System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíûé ïàðàìåòð color ");
            error = 1;
            com->success = 0;
        }
        if (error == 1)break;


        num = strtol(arr[1], &end, 16);

        com->r = num / 0x10000;
        com->g = (num / 0x100) % 0x100;
        com->b = num % 0x100;

        com->success = 1;
        cout << "Ïðèíÿòî" << endl;
        break;

    case 4:
        com->name = arr[0];
        if (com->name != "draw_pixel")
        {
            System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíîå íàçâàíèå êîìàíäû ");
            com->success = 0;
            error = 1;
        }
        if (error == 1)break;

        cout << arr[1] << endl;

        com->first = Ñonverting(arr[1]);
        if (com->first == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        com->second = Ñonverting(arr[2]);
        if (com->second == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        //color
        if (!HEX(arr[3]))
        {
            System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíûé ïàðàìåòð color ");
            error = 1;
            com->success = 0;
        }
        if (error == 1)break;

        num = strtol(arr[3], &end, 16);

        com->r = num / 0x10000;
        com->g = (num / 0x100) % 0x100;
        com->b = num % 0x100;

        com->success = 1;
        cout << "Ïðèíÿòî" << endl;
        break;

    case 6:

        com->name = arr[0];
     

        if (com->name == "draw_line" || com->name == "draw_rectangle" || com->name == "fill_rectangle" || com->name == "draw_ellipse" || com->name == "fill_ellipse")
        {
           // System::Windows::Forms::MessageBox::Show ("Íîðì " );
          
        }
        else{
            System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíîå íàçâàíèå êîìàíäû ");
            com->success = 0;
            error = 1;
        }
        if (error == 1)break;

        com->first = Ñonverting(arr[1]);
        if (com->first == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        com->second = Ñonverting(arr[2]);
        if (com->second == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        com->third = Ñonverting(arr[3]);
        if (com->third == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        com->fourth = Ñonverting(arr[4]);
        if (com->fourth == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

      
        if (HEX(arr[5])==false)
        {
            System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíûé ïàðàìåòð color ... ");
            error = 1;
            com->success = 0;
        }
        if (error == 1)break;


        num = strtol(arr[5], &end, 16);
        com->r = num / 0x10000;
        com->g = (num / 0x100) % 0x100;
        com->b = num % 0x100;

        com->success = 1;
        cout << "Ïðèíÿòî" << endl;
        break;

    case 7:

        com->name = arr[0];

        if (com->name != "draw_text")
        {
            cout << "ERROR: Íåïðàâèëüíîå íàçâàíèå êîìàíäû" << endl;
            com->success = 0;
            error = 1;
        }
        if (error == 1)break;

        com->x = Ñonverting(arr[1]);
        if (com->x == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        com->y = Ñonverting(arr[2]);
        if (com->y == 9999999)
        {
            error = 1;
            com->success = 0;
        }
        if (error == 1) break;

        if (!HEX(arr[3]))
        {
            cout << "ERROR: Íåïðàâèëüíûé ïàðàìåòð color" << endl;
            error = 1;
            com->success = 0;
        }
        if (error == 1)break;

        num = strtol(arr[3], &end, 16);
        com->r = num / 0x10000;
        com->g = (num / 0x100) % 0x100;
        com->b = num % 0x100;

        com->font_number = stoi(arr[4], 0, 10);

        if (com->font_number < 0 || com->font_number> 65535)
        {
            cout << "Error: çíà÷åíèå ïàðàìåòðà font_number çà äèàïàçîíîì äîïóñòèìûõ çíà÷åíèé " << endl;
            error = 1;
            com->success = 0;
        }
        if (error == 1)break;

        com->size = stoi(arr[5], 0, 10);

        if (com->size < 0 || com->size> 65535)
        {
            cout << "Error: çíà÷åíèå ïàðàìåòðà lenght çà äèàïàçîíîì äîïóñòèìûõ çíà÷åíèé " << endl;
            error = 1;
            com->success = 0;
        }
        if (error == 1)break;

        strncpy(com->text, arr[6], 44);
        

        com->success = 1;
        cout << "Ïðèíÿòî" << endl;
        break;

    default:
        com->success = 0;
        System::Windows::Forms::MessageBox::Show("Error: Íåïðàâèëüíîe êîëè÷åñòâî ïàðàìåòðîâ ");
        cout << "Error: Íåïðàâèëüíîe êîëè÷åñòâî ïàðàìåòðîâ" << endl;
        break;
    }
}



#include <iostream>
#include <string>
#include "MyForm.h"

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
        str = strtok_s(NULL, " ,", &next_token1);
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
        strncpy(com->text, s.c_str(), 100);

        if (error == 1)
        {
            com->success = 0;
        }
        else
        com->success = 1;
    }

    else if (com->name == "load_sprite")
    {
            com->index = Сonverting(arr[1]);

            if (com->index < 0 || com->index>255)
            {
                cout << "Error: значение параметра index за диапазоном допустимых значений " << endl;
                error = 1;
                com->success = 0;
            }
           
            com->width = Сonverting(arr[2]);
            com->height = Сonverting(arr[3]);

            strncpy(com->data, arr[4], 100);
           
            string buff;
            for (int i = 0; i < k; i++)
            {
                buff= buff + arr[i] + " ";
            }

            strncpy(com->buffer, buff.c_str(), 100);

          


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
        case 1:
            com->name = arr[0];

            if (com->name == "get_width")
            {
                com->success = 1;
                cout << "Принято" << endl;
                break;
            }

            else if (com->name == "get_height")
            {
                com->success = 1;
                cout << "Принято" << endl;
                break;
            }

            else
            {
                System::Windows::Forms::MessageBox::Show("1. Error: Неправильная команда ");
              
                com->success = 0;
                break;
            }

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

            else if (com->name == "set_orientation")
            {

                com->orientation = stoi(arr[1], 0, 10);

                if (com->orientation < 0 || com->orientation> 65535)
                {
                    System::Windows::Forms::MessageBox::Show("Error");
                    cout << "Error: значение параметра orientation за диапазоном допустимых значений " << endl;
                    error = 1;
                    com->success = 0;
                }
                if (error == 1)break;

                com->success = 1;
                cout << "Принято" << endl;
                break;
            }

            else
            {
                System::Windows::Forms::MessageBox::Show("2. Parser error: Неправильная команда ");
                com->success = 0;
                break;
            }

            /*
        case 3:

            com->name = arr[0];


            if (com->name == "get_size")
            {
                com->width = stoi(arr[1], 0, 10);

                if (com->width < 0 || com->width> 65535)
                {
                    System::Windows::Forms::MessageBox::Show("Error");
                    cout << "Error: значение параметра width за диапазоном допустимых значений " << endl;
                    error = 1;
                    com->success = 0;
                }
                if (error == 1)break;

                com->height = stoi(arr[2], 0, 10);

                if (com->height < 0 || com->height> 65535)
                {
                    System::Windows::Forms::MessageBox::Show("Error");
                    cout << "Error: значение параметра height за диапазоном допустимых значений " << endl;
                    error = 1;
                    com->success = 0;
                }
                if (error == 1)break;

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
            */

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
            
            else if (com->name == "show_sprite")
            {
                com->index = Сonverting(arr[1]);

                if (com->index < 0 || com->index>255)
                {
                    cout << "Error: значение параметра index за диапазоном допустимых значений " << endl;
                    error = 1;
                    com->success = 0;
                }
                if (error == 1) break;

                com->x = Сonverting(arr[2]);
                com->y = Сonverting(arr[3]);

                com->success = 1;
                cout << "Принято" << endl;
                break;

            }

            else
            {
                System::Windows::Forms::MessageBox::Show("4. Error: Неправильная команда ");
                com->success = 0;
                break;
            }

        case 5:
            /*
            com->name = arr[0];

            if (com->name == "load_sprite")
            {

                com->index = Сonverting(arr[1]);

                if (com->index < 0 || com->index>255)
                {
                    cout << "Error: значение параметра index за диапазоном допустимых значений " << endl;
                    error = 1;
                    com->success = 0;
                }
                if (error == 1) break;

                com->width = Сonverting(arr[2]);
                com->height = Сonverting(arr[3]);

                //System::Windows::Forms::MessageBox::Show(strlen(arr[4]).ToString());


                strncpy(com->data, arr[4], 44);
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
            */

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

        /*case 7:

            com->name = arr[0];

            if (com->name != "draw_text")
            {
                cout << "ERROR: Неправильное название команды" << endl;
                com->success = 0;
                error = 1;
            }
            if (error == 1)break;

            com->x = Сonverting(arr[1]);
            if (com->x == 9999999)
            {
                error = 1;
                com->success = 0;
            }
            if (error == 1) break;

            com->y = Сonverting(arr[2]);
            if (com->y == 9999999)
            {
                error = 1;
                com->success = 0;
            }
            if (error == 1) break;

            if (!HEX(arr[3]))
            {
                cout << "ERROR: Неправильный параметр color" << endl;
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
                cout << "Error: значение параметра font_number за диапазоном допустимых значений " << endl;
                error = 1;
                com->success = 0;
            }
            if (error == 1)break;

            com->size = stoi(arr[5], 0, 10);

            if (com->size < 0 || com->size> 65535)
            {
                cout << "Error: значение параметра lenght за диапазоном допустимых значений " << endl;
                error = 1;
                com->success = 0;
            }
            if (error == 1)break;

            System::Windows::Forms::MessageBox::Show(strlen(arr[6]).ToString());

            strncpy(com->text, arr[6], 44);


            com->success = 1;
            cout << "Принято" << endl;
            break;
            */

        default:

            com->success = 0;
            System::Windows::Forms::MessageBox::Show("6. Error: Неправильноe количество параметров ");
            cout << "Error: Неправильноe количество параметров" << endl;
            break;
        }
    }
}

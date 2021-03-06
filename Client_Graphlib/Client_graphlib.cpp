#include "Display.h"

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;


int main()
{
	
	setlocale(LC_ALL, "RUS");
	printf("Client\n");

	char buff[1000];

	if (WSAStartup(0x202, (WSADATA*)&buff[0]))
	{
		printf("WSAStartup error : % d \n", WSAGetLastError());
	}

	SOCKET my_sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (my_sock == INVALID_SOCKET)
	{
		printf("socket() error: % d \n", WSAGetLastError());
		WSACleanup();
	}

	
	Display display = Display(700, 500);
	int x = 10;
	int y = 10;
	int lenght = 10;
	
	display.fillScreen(stoi("ffff", 0, 16));
	
	 display.drawText(10, 20, "АБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ", stoi("3A9F", 0, 16), 1, 20);
	 //display.drawText(10, 60, "АБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ", stoi("3A9F", 0, 16), 2, 20);
	 

	/*
	while (1)
	{
		
		int selection;
		char Color[4];
		int color;
		int x0, x1, y0, y1, w, h, rx, ry;
		
		
		cout << endl;
		cout << "Выберите команду для отправки:" << endl;
			cout << "1. fillScreen: color" << endl;
			cout << "2. drawPixel: x0, y0, color" << endl;
			cout << "3. drawLine: x0, y0, x1, y1, color" << endl;
			cout << "4. drawRect: x0, y0, w, h, color" << endl;
			cout << "5. fillRect: x0, y0, w, h, color" << endl;
			cout << "6. drawEllipse: x0, y0, rx, ry, color" << endl;
			cout << "7. fillEllipse: x0, y0, rx, ry, color" << endl;
			cout << "\nВведите номер команды: ";
		    cin >> selection;

			switch (selection)
			{
			case 1:
				
				cout << "Подготовка команды 'fillScreen':"<<endl;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;

				color = stoi(Color, 0, 16);

				//uint_least16_t [0; 65535]
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}

				else
				display.fillScreen(color);

				break;

			case 2:
				cout << "Подготовка команды 'drawPixel':" << endl;
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;

				color = stoi(Color, 0, 16);
				
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}
				else

				display.drawPixel(x0, y0, color);
				break;

			case 3: 
				cout << "Подготовка команды 'drawLine':" << endl; 
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите парметр x1:";
				cin >> x1;
				cout << "Введите парметр y1:";
				cin >> y1;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;
				color = stoi(Color, 0, 16);
				cout <<"Цвет: " <<color <<" Размер "<<sizeof(color)<< endl;
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}

				else
				display.drawLine(x0, y0, x1, y1, color);
				break;

			case 4: 
				cout << "Подготовка команды 'drawRect':" << endl;
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите парметр w:";
				cin >> w;
				cout << "Введите парметр h:";
				cin >> h;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;
				color = stoi(Color, 0, 16);
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}
				else
				display.drawRect(x0, y0, w, h, color);
				break;

			case 5:
				cout << "Подготовка команды 'fillRect'" << endl; 
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите парметр w:";
				cin >> w;
				cout << "Введите парметр h:";
				cin >> h;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;
				color = stoi(Color, 0, 16);
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}
				else
				display.fillRect(x0, y0, w, h, color);
				break;
				
			case 6:
				cout << "Подготовка команды 'drawEllipse'" << endl; 
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите парметр rx:";
				cin >> rx;
				cout << "Введите парметр ry:";
				cin >> ry;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;
				color = stoi(Color, 0, 16);

				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}
				else
				display.drawEllipse(x0, y0, rx, ry, color);
				break;
				
			case 7:
				cout << "Подготовка команды 'fillEllipse'" << endl; 
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите парметр rx:";
				cin >> rx;
				cout << "Введите парметр ry:";
				cin >> ry;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;
				color = stoi(Color, 0, 16);
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}

				else

				display.fillEllipse(x0, y0, rx, ry, color);

				break;


			default:
				cout << "Ошибка: Введен не правильный номер команды" << endl;
				break;
			}
	}
	*/

	return 0;
}

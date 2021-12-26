#define _CRT_SECURE_NO_WARNINGS
#include "Display.h"

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <Windows.h> 

using namespace std;


int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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



	Display display = Display(600, 600);
	

	
	//display.getSize(display.getWidth(), display.getHeight());

	//display.fillScreen(stoi("ffff", 0, 16));
	//display.drawPixel(20,60, stoi(" 5FFB", 0, 16));
   

	//display.drawLine(10, 60, 30,40, stoi("F9A6", 0, 16));
	//display.drawRect(30, 140, 100, 80, stoi("F9A6", 0, 16));
	//display.fillRect(20, 260, 100, 50, stoi("5FFB", 0, 16));
	//display.drawEllipse(200, 50, 100, 80, stoi("749F", 0, 16));
	//display.fillEllipse(200, 200, 100, 80, stoi("749F", 0, 16));
	//display.drawText(100, 120, "Добро_пожаловать", stoi("5568", 0, 16), 1, 20);

	//display.setOrientation(2);
	//display.setOrientation(0);
	//display.setOrientation(1);
	
	/*
	int x = 300;
	int y = 10;
	int speed = 0;

	while (1)
	{
		if (speed % 3000 == 0)
		{
			display.fillScreen(stoi("ffff", 0, 16));
			display.drawText(x, y, "Добро пожаловать", 0000, 1, 20);
			x = x - 20;

			if (x == 0)
			{
				x = 600;
			}
		}
		speed++;
		cout << speed << endl;
	}
	*/
	
	
	while (1)
	{
		
		int selection;
		char Color[4];
		int color;
		int x0, x1, y0, y1, w, h, rx, ry;
		string str;
		char s[100];
		int bg, size;
		int orientation;
		int index;
		char data[1000];
		
		cout << endl;
		cout << "Выберите команду для отправки:" << endl;
			cout << "1. fillScreen: color" << endl;
			cout << "2. drawPixel: x0, y0, color" << endl;
			cout << "3. drawLine: x0, y0, x1, y1, color" << endl;
			cout << "4. drawRect: x0, y0, w, h, color" << endl;
			cout << "5. fillRect: x0, y0, w, h, color" << endl;
			cout << "6. drawEllipse: x0, y0, rx, ry, color" << endl;
			cout << "7. fillEllipse: x0, y0, rx, ry, color" << endl;
			cout << "8. drawText: x0, y0, s, color, bg, size" << endl;
			cout << "9. setOrientation: orientation" << endl;
			//cout << "?. getSize:" << endl;
			cout << "10. getWidth:" << endl;
			cout << "11. getHeight:" << endl;
			cout << "12. loadSprite: index, width, height, data" << endl;
			cout << "13. showSprite: index, x, y " << endl;
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

			case 8:
				setlocale(LC_ALL, "RUS");
				cout << "Подготовка команды 'drawText'" << endl;
				cout << "Введите парметр x0:";
				cin >> x0;
				cout << "Введите парметр y0:";
				cin >> y0;
				cout << "Введите параметр color (формат 0х0000):";
				cin >> Color;
				cout << "Введите параметр font_number:";
				cin >> bg;
				cout << "Введите параметр size: ";
				cin >> size;
				cout << "Введите парметр s:";
				gets_s(s);
				getline(cin, str);
				strncpy(s, str.c_str(), 100);

				color = stoi(Color, 0, 16);
				if (color < 0 || color> 65535)
				{
					cout << "Error: значение параметра color за диапазоном допустимых значений " << endl;
				}

				else

					display.drawText(x0, y0, s, color, bg, size);

				break;
			
			case 9:
				cout << "Подготовка команды 'setOrientation'" << endl;
				cout << "Введите парметр orientation:";
				cin >> orientation;
				display.setOrientation(orientation);
				break;
				
			//case 10:
			//	cout << "Подготовка команды 'getSize'" << endl;
			//	display.getSize(display.getWidth(), display.getHeight());
			//	break;
					
			case 10:
				cout << "Подготовка команды 'getWidth'" << endl;
				display.getWidth();

				break;
				
			case 11:
				cout << "Подготовка команды 'getHeight'" << endl;
				display.getHeight();
				
				break;

			case 12:
				cout << "Подготовка команды 'loadSprite'" << endl;
				cout << "Введите парметр index:";
				cin >> index;
				cout << "Введите парметр width:";
				cin >> w;
				cout << "Введите парметр height:";
				cin >> h;
				cout << "Введите парметр data:";
				cin >> data;
				display.loadSprite(index, w, h, data);
				break;

			case 13:
				cout << "Подготовка команды 'showSprite'" << endl;
				
				cout << "Введите парметр index:";
				cin >> index;
				cout << "Введите парметр x:";
				cin >> x0;
				cout << "Введите парметр y:";
				cin >> y0;
				display.showSprite(index, x0, y0);
				break;

			default:
				cout << "Ошибка: Введен не правильный номер команды" << endl;
				break;
			}



	}
	



	return 0;
}

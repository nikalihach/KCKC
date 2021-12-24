#pragma once
#include "Parser.h"

#include <iostream>
#include <stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#define PORT 777

namespace GraphServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			Thread^ ServerThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::Server));

			ServerThread->IsBackground = true;
			ServerThread->Start();
			
			Thread::Sleep(20);

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(564, 447);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отобразить\r\n команду";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 449);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Получена команда:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(215, 447);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(343, 25);
			this->textBox1->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(177, 94);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(343, 256);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void clear_display(int r, int g, int b)
		{
			Graphics^ gr = this->CreateGraphics();
			gr->Clear(Color::FromArgb(r, g, b));
		}

		void draw_pixel(int x0, int y0, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			Graphics^ gr = this->CreateGraphics();
			gr->FillRectangle(aBrush, x0, y0, 1, 1);
		}

		void draw_line(int x0, int y0, int x1, int y1, int r, int g, int b)
		{
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			Graphics^ gr = this->CreateGraphics();
			gr->DrawLine(color, x0, y0, x1, y1);
			
		}

		void draw_rectangle(int x0, int y0, int w, int h, int r, int g, int b)
		{
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			Graphics^ gr = this->CreateGraphics();
			gr->DrawRectangle(color, x0, y0, w, h);
		}

		void fill_rectangle(int x0, int y0, int w, int h, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			Graphics^ gr = this->CreateGraphics();
			gr->FillRectangle(aBrush, x0, y0, w, h);
		}

		void draw_ellipse(int x0, int y0, int rx, int ry, int r, int g, int b)
		{
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			Graphics^ gr = this->CreateGraphics();
			gr->DrawEllipse(color, x0, y0, rx, ry);
		}

		void fill_ellipse(int x0, int y0, int rx, int ry, int r, int g, int b)
		{

			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			Graphics^ gr = this->CreateGraphics();
			gr->FillEllipse(aBrush, x0, y0, rx, ry);
		}

		void draw_text(int x, int y, int r, int g, int b, int font_number, int size, char* text)
		{

			switch (font_number)
			{
			case 1:

				for (int i = 0; i < strlen(text); i++)
				{
					if (text[i] == 'А' || text[i] == 'а')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + (size / 2), y, r, g, b);
						draw_line(x + (size / 2), y, x + (size / 2), y + size, r, g, b);
						draw_line(x, y + (size / 2), x + (size / 2), y + (size / 2), r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'Б' || text[i] == 'б')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'В' || text[i] == 'в')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.75, y + size / 2, r, g, b);
						draw_line(x + size * 0.75, y + size / 2, x + size * 0.75, y + size, r, g, b);
						draw_line(x + size * 0.75, y + size, x, y + size, r, g, b);
						x=x + size*0.7 + size / 2;
					}

					if (text[i] == 'Г' || text[i] == 'г')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'Д' || text[i] == 'д')
					{
						draw_line(x, y + size / 2, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size, y + size / 2, r, g, b);
						draw_line(x + size, y + size / 2, x + size, y + size, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size * 0.25, y, r, g, b);
						draw_line(x + size * 0.25, y, x + size * 0.75, y, r, g, b);
						draw_line(x + size * 0.75, y, x + size * 0.75, y + size / 2, r, g, b);
						x = x + size * 0.75 + size / 2;
					}

					if (text[i] == 'Е' || text[i] == 'е')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ё' || text[i] == 'ё')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size * 0.15, y - size * 0.25, x + size * 0.15, y - size * 0.15, r, g, b);
						draw_line(x + size * 0.45, y - size * 0.25, x + size * 0.45, y - size * 0.15, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ж' || text[i] == 'ж')
					{
						draw_line(x, y, x + size, y + size, r, g, b);
						draw_line(x, y + size, x + size, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size*0.8 + size / 2;
					}

					if (text[i] == 'З' || text[i] == 'з')
					{
						draw_line(x + size * 0.10, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size * 0.75, y + size / 2, r, g, b);
						draw_line(x + size * 0.75, y + size / 2, x + size * 0.75, y + size, r, g, b);
						draw_line(x + size * 0.75, y + size, x, y + size, r, g, b);
						x = x + size *0.75 + size / 2;
					}

					if (text[i] == 'И' || text[i] == 'и')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Й' || text[i] == 'й')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x + size * 0.20, y - size * 0.15, x + size * 0.30, y - size * 0.10, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'К' || text[i] == 'к')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.25, y + size / 2, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Л' || text[i] == 'л')
					{
						draw_line(x, y + size, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size, y + size, r, g, b);
						x = x + size  + size / 2;
					}

					if (text[i] == 'М' || text[i] == 'м')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x + size, y, r, g, b);
						draw_line(x + size, y, x + size, y + size, r, g, b);
						x = x + size + size / 2;
					}

					if (text[i] == 'Н' || text[i] == 'н')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'О' || text[i] == 'о')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'П' || text[i] == 'п')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Р' || text[i] == 'р')
					{

						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						x = x + size / 2 + size / 2;

					}

					if (text[i] == 'С' || text[i] == 'с')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size * 0.20, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y + size * 0.80, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Т' || text[i] == 'т')
					{
						draw_line(x, y, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						x = x + size *0.8 + size / 2;
					}

					if (text[i] == 'У' || text[i] == 'у')
					{
						draw_line(x, y, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.4, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Ф' || text[i] == 'ф')
					{
						draw_line(x, y, x, y + size / 2, r, g, b);
						draw_line(x, y, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size / 2, r, g, b);
						draw_line(x + size * 0.8, y + size / 2, x, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Х' || text[i] == 'х')
					{
						draw_line(x, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Ц' || text[i] == 'ц')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y, r, g, b);
						draw_line(x, y + size, x + size * 0.7, y + size, r, g, b);
						draw_line(x + size * 0.7, y + size, x + size * 0.7, y + size * 1.2, r, g, b);
						x = x + size * 0.6 + size / 2;
					}

					if (text[i] == 'Ч' || text[i] == 'ч')
					{
						draw_line(x, y, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ш' || text[i] == 'ш')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Щ' || text[i] == 'щ')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.8, y + size, x + size, y + size, r, g, b);
						draw_line(x + size, y + size, x + size, y + size * 1.1, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Ъ' || text[i] == 'ъ')
					{
						draw_line(x, y, x + size * 0.4, y, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.4, y + size, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.8, y + size, x + size * 0.8, y + size / 2, r, g, b);
						draw_line(x + size * 0.8, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Ы' || text[i] == 'ы')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.6, y, x + size * 0.6, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ь' || text[i] == 'ь')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.4, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Э' || text[i] == 'э')
					{
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ю' || text[i] == 'ю')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y + size, x + size * 0.8, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}


					if (text[i] == 'Я' || text[i] == 'я')
					{
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == ' ' )
					{
						
						x = x + size;
					}
				}

				break;

			case 2:

				for (int i = 0; i < strlen(text); i++)
				{
					if (text[i] == 'А' || text[i] == 'а')
					{

						draw_line(x, y + size, x + size / 3, y, r, g, b);
						draw_line(x + size / 3, y, x + size / 2, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);

						x = x + (size / 2) + size / 2;
					}
					if (text[i] == 'Б' || text[i] == 'б')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size * 0.75, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size * 0.75, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'В' || text[i] == 'в')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x + size / 2, y + size * 0.25, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size * 0.75, r, g, b);
						draw_line(x + size / 2, y + size * 0.75, x, y + size, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'Г' || text[i] == 'г')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'Д' || text[i] == 'д')
					{
						draw_line(x, y + size / 2, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size, y + size / 2, r, g, b);
						draw_line(x + size, y + size / 2, x + size, y + size, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size * 0.75, y + size / 2, r, g, b);
						x = x + size + size / 2;
					}

					if (text[i] == 'Е' || text[i] == 'е')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size * 0.75, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ё' || text[i] == 'ё')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size * 0.75, r, g, b);
						draw_line(x + size * 0.15, y - size * 0.25, x + size * 0.15, y - size * 0.15, r, g, b);
						draw_line(x + size * 0.45, y - size * 0.25, x + size * 0.45, y - size * 0.15, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ж' || text[i] == 'ж')
					{
						draw_line(x, y, x + size, y + size, r, g, b);
						draw_line(x, y + size, x + size, y, r, g, b);
						draw_line(x + size / 2, y + size * 0.10, x + size / 2, y + size * 0.9, r, g, b);
						x = x + size + size / 2;
					}

					if (text[i] == 'З' || text[i] == 'з')
					{
						draw_line(x + size * 0.10, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size * 0.75, y + size / 2, r, g, b);
						draw_line(x + size * 0.75, y + size / 2, x + size * 0.75, y + size, r, g, b);
						draw_line(x + size * 0.75, y + size, x, y + size, r, g, b);
						draw_line(x, y, x, y + size * 0.10, r, g, b);
						draw_line(x, y + size, x, y + size * 0.90, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'И' || text[i] == 'и')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.40, y, r, g, b);
						draw_line(x + size * 0.40, y, x + size * 0.40, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Й' || text[i] == 'й')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.40, y, r, g, b);
						draw_line(x + size * 0.40, y, x + size * 0.40, y + size, r, g, b);
						draw_line(x + size * 0.10, y - size * 0.15, x + size * 0.30, y - size * 0.15, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'К' || text[i] == 'к')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Л' || text[i] == 'л')
					{
						draw_line(x, y + size, x + size * 0.30, y, r, g, b);
						draw_line(x + size * 0.30, y, x + size * 0.60, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'М' || text[i] == 'м')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size * 0.30, y + size / 2, r, g, b);
						draw_line(x + size * 0.30, y + size / 2, x + size * 0.60, y, r, g, b);
						draw_line(x + size * 0.60, y, x + size * 0.60, y + size, r, g, b);
						x = x + size / 2 + size / 2;

					}

					if (text[i] == 'Н' || text[i] == 'н')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size * 0.30, x + size / 2, y + size * 0.30, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;

					}

					if (text[i] == 'О' || text[i] == 'о')
					{
						draw_line(x, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size, y + size / 2, r, g, b);
						draw_line(x + size, y + size / 2, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size / 2, r, g, b);
						x = x + size  + size / 2;
					}

					if (text[i] == 'П' || text[i] == 'п')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Р' || text[i] == 'р')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x + size / 2, y + size * 0.25, x, y + size / 2, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == 'С' || text[i] == 'с')
					{
						draw_line(x, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size, y + size * 0.2, r, g, b);
						draw_line(x + size, y + size * 0.80, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size / 2, r, g, b);
						x = x + size  + size / 2;
					}

					if (text[i] == 'Т' || text[i] == 'т')
					{
						draw_line(x, y, x + size * 0.5, y, r, g, b);
						draw_line(x + size * 0.25, y, x + size * 0.25, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'У' || text[i] == 'у')
					{
						draw_line(x, y, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x, y + size, r, g, b);
						x = x + size * 0.7 + size / 2;
					}

					if (text[i] == 'Ф' || text[i] == 'ф')
					{
						draw_line(x, y + size * 0.25, x + size * 0.4, y, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.8, y + size * 0.25, r, g, b);
						draw_line(x + size * 0.8, y + size * 0.25, x + size * 0.4, y + size * 0.5, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x, y + size * 0.25, x + size * 0.4, y + size / 2, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == 'Х' || text[i] == 'х')
					{
						draw_line(x, y, x + size * 0.6, y + size, r, g, b);
						draw_line(x + size * 0.6, y, x, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == 'Ц' || text[i] == 'ц')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size * 0.7, y + size, r, g, b);
						draw_line(x + size * 0.7, y + size, x + size * 0.7, y + size * 1.2, r, g, b);
						x = x + size * 0.6 + size / 2;
					}

						if (text[i] == 'Ч' || text[i] == 'ч')
						{
							draw_line(x, y, x, y + size / 2, r, g, b);
							draw_line(x, y + size / 2, x + size / 4, y + size * 0.7, r, g, b);
							draw_line(x + size / 4, y + size * 0.7, x + size / 2, y + size / 2, r, g, b);
							draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == 'Ш' || text[i] == 'ш')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x + size * 0.4, y + size * 0.25, x + size * 0.4, y + size, r, g, b);
							draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
							draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == 'Щ' || text[i] == 'щ')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x + size * 0.4, y + size * 0.25, x + size * 0.4, y + size, r, g, b);
							draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
							draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
							draw_line(x + size * 0.8, y + size, x + size, y + size, r, g, b);
							draw_line(x + size, y + size, x + size, y + size * 1.1, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == 'Ъ' || text[i] == 'ъ')
						{
							draw_line(x, y, x + size * 0.4, y, r, g, b);
							draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
							draw_line(x + size * 0.4, y + size / 2, x + size * 0.8, y + size * 0.75, r, g, b);
							draw_line(x + size * 0.8, y + size * 0.75, x + size * 0.4, y + size, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == 'Ы' || text[i] == 'ы')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x, y + size / 2, x + size * 0.4, y + size * 0.75, r, g, b);
							draw_line(x, y + size, x + size * 0.4, y + size * 0.75, r, g, b);
							draw_line(x + size * 0.6, y, x + size * 0.6, y + size, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == 'Ь' || text[i] == 'ь')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x, y + size / 2, x + size * 0.4, y + size * 0.75, r, g, b);
							draw_line(x, y + size, x + size * 0.4, y + size * 0.75, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == 'Э' || text[i] == 'э')
						{
							draw_line(x, y, x + size / 4, y - size * 0.2, r, g, b);
							draw_line(x + size / 4, y - size * 0.2, x + size / 2, y, r, g, b);
							draw_line(x + size / 2, y + size, x + size / 4, y + size * 1.2, r, g, b);
							draw_line(x + size / 4, y + size * 1.2, x, y + size, r, g, b);
							draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
							draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == 'Ю' || text[i] == 'ю')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
							draw_line(x + size * 0.4, y + size / 2, x + size * 0.6, y, r, g, b);
							draw_line(x + size * 0.6, y, x + size * 0.8, y + size / 2, r, g, b);
							draw_line(x + size * 0.8, y + size / 2, x + size * 0.6, y + size, r, g, b);
							draw_line(x + size * 0.6, y + size, x + size * 0.4, y + size / 2, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == 'Я' || text[i] == 'я')
						{
							draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
							draw_line(x + size / 2, y, x, y + size * 0.25, r, g, b);
							draw_line(x, y + size * 0.25, x + size / 2, y + size / 2, r, g, b);
							draw_line(x + size / 2, y + size / 2, x, y + size, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == ' ')
						{

							x = x +  size;
						}
				}
				break;

				default: 
					MessageBox::Show("Нет такого шрифта");
					break;
			}
		}
		

		String^ buffer;

		void Server()
		{

			char buff[1024];


			if (WSAStartup(0x202, (WSADATA*)&buff[0]))
			{
				WSACleanup();
			}

			SOCKET my_sock;
			my_sock = socket(AF_INET, SOCK_DGRAM, 0);
			if (my_sock == INVALID_SOCKET)
			{
				MessageBox::Show("Ошибка", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				WSACleanup();
			}

			sockaddr_in local_addr;
			local_addr.sin_family = AF_INET;
			local_addr.sin_addr.s_addr = INADDR_ANY;
			local_addr.sin_port = htons(PORT);

			if (bind(my_sock, (sockaddr*)&local_addr, sizeof(local_addr)) == -1)
			{
				MessageBox::Show("Ошибка", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				closesocket(my_sock);
				WSACleanup();
			}

			while (1)
			{

				sockaddr_in client_addr;
				int client_addr_size = sizeof(client_addr);
				int bsize = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
				if (bsize == SOCKET_ERROR)
				{
					MessageBox::Show("Ошибка", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				}
				HOSTENT* hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);

				buff[bsize] = 0;
				buffer = gcnew String(buff);

				struct Command one;

				Parse(buff, &one);
				
				if (one.success == 1)
				{
					Drawing(&one);
				}
			
			}
		}

		void Drawing(struct Command* com)
		{
			if (com->name == "clear_display")
			{
				clear_display(com->r, com->g, com->b);
			}

			else if (com->name == "draw_pixel")
			{
				draw_pixel(com->first, com->second, com->r, com->g, com->b);
			}
			else if (com->name == "draw_line")
			{
				draw_line(com->first, com->second, com->third, com->fourth, com->r, com->g, com->b);
			}
			else if (com->name == "draw_rectangle" )
			{
				draw_rectangle(com->first, com->second, com->third, com->fourth, com->r, com->g, com->b);
			}
			else if (com->name == "fill_rectangle" )
			{
				fill_rectangle(com->first, com->second, com->third, com->fourth, com->r, com->g, com->b);
			}
			else if (com->name == "draw_ellipse" )
			{
				draw_ellipse(com->first, com->second, com->third, com->fourth, com->r, com->g, com->b);
			}

			else if (com->name == "fill_ellipse" )
			{
				fill_ellipse(com->first, com->second, com->third, com->fourth, com->r, com->g, com->b);
			}

			else if (com->name == "draw_text")
			{
				draw_text(com->x, com->y, com->r, com->g, com->b, com->font_number, com->size, com->text);
			}

		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			textBox1->Text = buffer;
			

	}

	
};
}

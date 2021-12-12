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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//

			Thread^ ServerThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::Server));

			ServerThread->IsBackground = true;
			ServerThread->Start();
			
			Thread::Sleep(20);

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
			this->button1->Text = L"����������\r\n �������";
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
			this->label1->Text = L"�������� �������:";
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
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

		void draw_text(int x, int y, int r, int g, int b, int font_number, int lenght, char* text)
		{

			switch (font_number)
			{
			case 1:

				for (int i = 0; i < strlen(text); i++)
				{
					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + (lenght / 2), y, r, g, b);
						draw_line(x + (lenght / 2), y, x + (lenght / 2), y + lenght, r, g, b);
						draw_line(x, y + (lenght / 2), x + (lenght / 2), y + (lenght / 2), r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght / 2, r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght * 0.75, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.75, y + lenght / 2, x + lenght * 0.75, y + lenght, r, g, b);
						draw_line(x + lenght * 0.75, y + lenght, x, y + lenght, r, g, b);
						x=x + lenght*0.7 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght / 2, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght, y + lenght / 2, r, g, b);
						draw_line(x + lenght, y + lenght / 2, x + lenght, y + lenght, r, g, b);
						draw_line(x + lenght * 0.25, y + lenght / 2, x + lenght * 0.25, y, r, g, b);
						draw_line(x + lenght * 0.25, y, x + lenght * 0.75, y, r, g, b);
						draw_line(x + lenght * 0.75, y, x + lenght * 0.75, y + lenght / 2, r, g, b);
						x = x + lenght * 0.75 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght * 0.15, y - lenght * 0.25, x + lenght * 0.15, y - lenght * 0.15, r, g, b);
						draw_line(x + lenght * 0.45, y - lenght * 0.25, x + lenght * 0.45, y - lenght * 0.15, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght*0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x + lenght * 0.10, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.25, y + lenght / 2, x + lenght * 0.75, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.75, y + lenght / 2, x + lenght * 0.75, y + lenght, r, g, b);
						draw_line(x + lenght * 0.75, y + lenght, x, y + lenght, r, g, b);
						x = x + lenght *0.75 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght * 0.20, y - lenght * 0.15, x + lenght * 0.30, y - lenght * 0.10, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght * 0.25, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.25, y + lenght / 2, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght * 0.25, y + lenght / 2, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght, y + lenght, r, g, b);
						x = x + lenght  + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y + lenght / 2, x + lenght, y, r, g, b);
						draw_line(x + lenght, y, x + lenght, y + lenght, r, g, b);
						x = x + lenght + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{

						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght / 2, r, g, b);
						x = x + lenght / 2 + lenght / 2;

					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght * 0.20, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x + lenght / 2, y + lenght * 0.80, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.8, y, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						x = x + lenght *0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.4, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.8, y, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.4, y + lenght, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght / 2, r, g, b);
						draw_line(x, y, x + lenght * 0.8, y, r, g, b);
						draw_line(x + lenght * 0.8, y, x + lenght * 0.8, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.8, y + lenght / 2, x, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.8, y + lenght, r, g, b);
						draw_line(x + lenght * 0.8, y, x, y + lenght, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x + lenght / 2, y, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.7, y + lenght, r, g, b);
						draw_line(x + lenght * 0.7, y + lenght, x + lenght * 0.7, y + lenght * 1.2, r, g, b);
						x = x + lenght * 0.6 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.8, y, x + lenght * 0.8, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.8, y + lenght, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.8, y, x + lenght * 0.8, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.8, y + lenght, r, g, b);
						draw_line(x + lenght * 0.8, y + lenght, x + lenght, y + lenght, r, g, b);
						draw_line(x + lenght, y + lenght, x + lenght, y + lenght * 1.1, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.4, y, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght, x + lenght * 0.8, y + lenght, r, g, b);
						draw_line(x + lenght * 0.8, y + lenght, x + lenght * 0.8, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.8, y + lenght / 2, x + lenght * 0.4, y + lenght / 2, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght * 0.4, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.6, y, x + lenght * 0.6, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght * 0.4, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.4, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght / 2, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght * 0.4, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x + lenght * 0.8, y, x + lenght * 0.8, y + lenght, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.8, y, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght, x + lenght * 0.8, y + lenght, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}


					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x, y, x, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '_' )
					{
						
						x = x + 1.5* lenght;
					}
				}

				break;

			case 2:

				for (int i = 0; i < strlen(text); i++)
				{
					if (text[i] == '�' || text[i] == '�')
					{

						draw_line(x, y + lenght, x + lenght / 3, y, r, g, b);
						draw_line(x + lenght / 3, y, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);

						x = x + (lenght / 2) + lenght / 2;
					}
					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght * 0.75, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght * 0.75, r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y + lenght * 0.25, r, g, b);
						draw_line(x + lenght / 2, y + lenght * 0.25, x, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght * 0.75, r, g, b);
						draw_line(x + lenght / 2, y + lenght * 0.75, x, y + lenght, r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght / 2, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght, y + lenght / 2, r, g, b);
						draw_line(x + lenght, y + lenght / 2, x + lenght, y + lenght, r, g, b);
						draw_line(x + lenght * 0.25, y + lenght / 2, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght * 0.75, y + lenght / 2, r, g, b);
						x = x + lenght + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y + lenght * 0.25, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght * 0.75, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y + lenght * 0.25, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght * 0.75, r, g, b);
						draw_line(x + lenght * 0.15, y - lenght * 0.25, x + lenght * 0.15, y - lenght * 0.15, r, g, b);
						draw_line(x + lenght * 0.45, y - lenght * 0.25, x + lenght * 0.45, y - lenght * 0.15, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght, y, r, g, b);
						draw_line(x + lenght / 2, y + lenght * 0.10, x + lenght / 2, y + lenght * 0.9, r, g, b);
						x = x + lenght + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x + lenght * 0.10, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.25, y + lenght / 2, x + lenght * 0.75, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.75, y + lenght / 2, x + lenght * 0.75, y + lenght, r, g, b);
						draw_line(x + lenght * 0.75, y + lenght, x, y + lenght, r, g, b);
						draw_line(x, y, x, y + lenght * 0.10, r, g, b);
						draw_line(x, y + lenght, x, y + lenght * 0.90, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.40, y, r, g, b);
						draw_line(x + lenght * 0.40, y, x + lenght * 0.40, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.40, y, r, g, b);
						draw_line(x + lenght * 0.40, y, x + lenght * 0.40, y + lenght, r, g, b);
						draw_line(x + lenght * 0.10, y - lenght * 0.15, x + lenght * 0.30, y - lenght * 0.15, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y, r, g, b);
						draw_line(x, y + lenght / 2, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght, x + lenght * 0.30, y, r, g, b);
						draw_line(x + lenght * 0.30, y, x + lenght * 0.60, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght * 0.30, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.30, y + lenght / 2, x + lenght * 0.60, y, r, g, b);
						draw_line(x + lenght * 0.60, y, x + lenght * 0.60, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;

					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght * 0.30, x + lenght / 2, y + lenght * 0.30, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;

					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght / 2, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght, y + lenght / 2, r, g, b);
						draw_line(x + lenght, y + lenght / 2, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x, y + lenght / 2, r, g, b);
						x = x + lenght  + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y, x + lenght / 2, y + lenght * 0.25, r, g, b);
						draw_line(x + lenght / 2, y + lenght * 0.25, x, y + lenght / 2, r, g, b);
						x = x + (lenght / 2) + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght / 2, x + lenght / 2, y, r, g, b);
						draw_line(x + lenght / 2, y, x + lenght, y + lenght * 0.2, r, g, b);
						draw_line(x + lenght, y + lenght * 0.80, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x, y + lenght / 2, r, g, b);
						x = x + lenght  + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.5, y, r, g, b);
						draw_line(x + lenght * 0.25, y, x + lenght * 0.25, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.4, y + lenght / 2, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.8, y, r, g, b);
						draw_line(x + lenght * 0.4, y + lenght / 2, x, y + lenght, r, g, b);
						x = x + lenght * 0.7 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + lenght * 0.25, x + lenght * 0.4, y, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.8, y + lenght * 0.25, r, g, b);
						draw_line(x + lenght * 0.8, y + lenght * 0.25, x + lenght * 0.4, y + lenght * 0.5, r, g, b);
						draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
						draw_line(x, y + lenght * 0.25, x + lenght * 0.4, y + lenght / 2, r, g, b);
						x = x + lenght * 0.8 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + lenght * 0.6, y + lenght, r, g, b);
						draw_line(x + lenght * 0.6, y, x, y + lenght, r, g, b);
						x = x + lenght / 2 + lenght / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + lenght, r, g, b);
						draw_line(x, y + lenght, x + lenght / 2, y + lenght, r, g, b);
						draw_line(x + lenght / 2, y + lenght, x + lenght / 2, y + lenght / 2, r, g, b);
						draw_line(x, y + lenght, x + lenght * 0.7, y + lenght, r, g, b);
						draw_line(x + lenght * 0.7, y + lenght, x + lenght * 0.7, y + lenght * 1.2, r, g, b);
						x = x + lenght * 0.6 + lenght / 2;
					}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + lenght / 2, r, g, b);
							draw_line(x, y + lenght / 2, x + lenght / 4, y + lenght * 0.7, r, g, b);
							draw_line(x + lenght / 4, y + lenght * 0.7, x + lenght / 2, y + lenght / 2, r, g, b);
							draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
							x = x + lenght / 2 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + lenght, r, g, b);
							draw_line(x + lenght * 0.4, y + lenght * 0.25, x + lenght * 0.4, y + lenght, r, g, b);
							draw_line(x + lenght * 0.8, y, x + lenght * 0.8, y + lenght, r, g, b);
							draw_line(x, y + lenght, x + lenght * 0.8, y + lenght, r, g, b);
							x = x + lenght * 0.8 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + lenght, r, g, b);
							draw_line(x + lenght * 0.4, y + lenght * 0.25, x + lenght * 0.4, y + lenght, r, g, b);
							draw_line(x + lenght * 0.8, y, x + lenght * 0.8, y + lenght, r, g, b);
							draw_line(x, y + lenght, x + lenght * 0.8, y + lenght, r, g, b);
							draw_line(x + lenght * 0.8, y + lenght, x + lenght, y + lenght, r, g, b);
							draw_line(x + lenght, y + lenght, x + lenght, y + lenght * 1.1, r, g, b);
							x = x + lenght * 0.8 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x + lenght * 0.4, y, r, g, b);
							draw_line(x + lenght * 0.4, y, x + lenght * 0.4, y + lenght, r, g, b);
							draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.8, y + lenght * 0.75, r, g, b);
							draw_line(x + lenght * 0.8, y + lenght * 0.75, x + lenght * 0.4, y + lenght, r, g, b);
							x = x + lenght * 0.8 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + lenght, r, g, b);
							draw_line(x, y + lenght / 2, x + lenght * 0.4, y + lenght * 0.75, r, g, b);
							draw_line(x, y + lenght, x + lenght * 0.4, y + lenght * 0.75, r, g, b);
							draw_line(x + lenght * 0.6, y, x + lenght * 0.6, y + lenght, r, g, b);
							x = x + lenght / 2 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + lenght, r, g, b);
							draw_line(x, y + lenght / 2, x + lenght * 0.4, y + lenght * 0.75, r, g, b);
							draw_line(x, y + lenght, x + lenght * 0.4, y + lenght * 0.75, r, g, b);
							x = x + lenght / 2 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x + lenght / 4, y - lenght * 0.2, r, g, b);
							draw_line(x + lenght / 4, y - lenght * 0.2, x + lenght / 2, y, r, g, b);
							draw_line(x + lenght / 2, y + lenght, x + lenght / 4, y + lenght * 1.2, r, g, b);
							draw_line(x + lenght / 4, y + lenght * 1.2, x, y + lenght, r, g, b);
							draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
							draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght / 2, r, g, b);
							x = x + lenght / 2 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + lenght, r, g, b);
							draw_line(x, y + lenght / 2, x + lenght * 0.4, y + lenght / 2, r, g, b);
							draw_line(x + lenght * 0.4, y + lenght / 2, x + lenght * 0.6, y, r, g, b);
							draw_line(x + lenght * 0.6, y, x + lenght * 0.8, y + lenght / 2, r, g, b);
							draw_line(x + lenght * 0.8, y + lenght / 2, x + lenght * 0.6, y + lenght, r, g, b);
							draw_line(x + lenght * 0.6, y + lenght, x + lenght * 0.4, y + lenght / 2, r, g, b);
							x = x + lenght * 0.8 + lenght / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x + lenght / 2, y, x + lenght / 2, y + lenght, r, g, b);
							draw_line(x + lenght / 2, y, x, y + lenght * 0.25, r, g, b);
							draw_line(x, y + lenght * 0.25, x + lenght / 2, y + lenght / 2, r, g, b);
							draw_line(x + lenght / 2, y + lenght / 2, x, y + lenght, r, g, b);
							x = x + lenght / 2 + lenght / 2;
						}

						if (text[i] == '_')
						{

							x = x + 1.5 * lenght;
						}
				}
				break;

				default: 
					MessageBox::Show("��� ������ ������");
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
				MessageBox::Show("������", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				WSACleanup();
			}

			sockaddr_in local_addr;
			local_addr.sin_family = AF_INET;
			local_addr.sin_addr.s_addr = INADDR_ANY;
			local_addr.sin_port = htons(PORT);

			if (bind(my_sock, (sockaddr*)&local_addr, sizeof(local_addr)) == -1)
			{
				MessageBox::Show("������", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
					MessageBox::Show("������", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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
				draw_text(com->x, com->y, com->r, com->g, com->b, com->font_number, com->lenght, com->text);
			}

		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			textBox1->Text = buffer;

	}

	};
}

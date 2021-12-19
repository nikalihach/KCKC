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

	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;




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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1924, 1055);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(1429, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(343, 25);
			this->textBox1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1226, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 22);
			this->label2->TabIndex = 5;
			this->label2->Text = L"�������� �������:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1778, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 37);
			this->button1->TabIndex = 4;
			this->button1->Text = L"����������\r\n �������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		Bitmap^ Img1;
		Bitmap^ Img2;
		Graphics^ gr;

		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

			
			Img1 = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = Img1;
			gr = Graphics::FromImage(Img1);
			
		
		}
			  
		
	

		void clear_display(int r, int g, int b)
		{
			
			 //gr = this->CreateGraphics();
			gr->Clear(Color::FromArgb(r, g, b));
		}

		void draw_pixel(int x0, int y0, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			 //gr = this->CreateGraphics();
			gr->FillRectangle(aBrush, x0, y0, 1, 1);

		}

		void draw_line(int x0, int y0, int x1, int y1, int r, int g, int b)
		{
		
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			//Graphics^ gr = this->CreateGraphics();
			//gr = pictureBox1->CreateGraphics();
			gr->DrawLine(color, x0, y0, x1, y1);

		}

		void draw_rectangle(int x0, int y0, int w, int h, int r, int g, int b)
		{
			
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			 //gr = this->CreateGraphics();
			gr->DrawRectangle(color, x0, y0, w, h);
		
		}

		void fill_rectangle(int x0, int y0, int w, int h, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			 //gr = this->CreateGraphics();
			gr->FillRectangle(aBrush, x0, y0, w, h);
		}

		void draw_ellipse(int x0, int y0, int rx, int ry, int r, int g, int b)
		{
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			// gr = this->CreateGraphics();
			gr->DrawEllipse(color, x0, y0, rx, ry);
		}

		void fill_ellipse(int x0, int y0, int rx, int ry, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			// gr = this->CreateGraphics();
			gr->FillEllipse(aBrush, x0, y0, rx, ry);
		}

		void draw_text(int x, int y, int r, int g, int b, int font_number, int size, char* text)
		{
			switch (font_number)
			{
			case 1:

				for (int i = 0; i < strlen(text); i++)
				{
					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + (size / 2), y, r, g, b);
						draw_line(x + (size / 2), y, x + (size / 2), y + size, r, g, b);
						draw_line(x, y + (size / 2), x + (size / 2), y + (size / 2), r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
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

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size / 2, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size, y + size / 2, r, g, b);
						draw_line(x + size, y + size / 2, x + size, y + size, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size * 0.25, y, r, g, b);
						draw_line(x + size * 0.25, y, x + size * 0.75, y, r, g, b);
						draw_line(x + size * 0.75, y, x + size * 0.75, y + size / 2, r, g, b);
						x = x + size * 0.75 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size * 0.15, y - size * 0.25, x + size * 0.15, y - size * 0.15, r, g, b);
						draw_line(x + size * 0.45, y - size * 0.25, x + size * 0.45, y - size * 0.15, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size, y + size, r, g, b);
						draw_line(x, y + size, x + size, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size*0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x + size * 0.10, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size * 0.75, y + size / 2, r, g, b);
						draw_line(x + size * 0.75, y + size / 2, x + size * 0.75, y + size, r, g, b);
						draw_line(x + size * 0.75, y + size, x, y + size, r, g, b);
						x = x + size *0.75 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x + size * 0.20, y - size * 0.15, x + size * 0.30, y - size * 0.10, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.25, y + size / 2, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size, y + size, r, g, b);
						x = x + size  + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x + size, y, r, g, b);
						draw_line(x + size, y, x + size, y + size, r, g, b);
						x = x + size + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{

						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						x = x + size / 2 + size / 2;

					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size * 0.20, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y + size * 0.80, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						x = x + size *0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.4, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size / 2, r, g, b);
						draw_line(x, y, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size / 2, r, g, b);
						draw_line(x + size * 0.8, y + size / 2, x, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y, r, g, b);
						draw_line(x, y + size, x + size * 0.7, y + size, r, g, b);
						draw_line(x + size * 0.7, y + size, x + size * 0.7, y + size * 1.2, r, g, b);
						x = x + size * 0.6 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.8, y + size, x + size, y + size, r, g, b);
						draw_line(x + size, y + size, x + size, y + size * 1.1, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.4, y, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.4, y + size, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.8, y + size, x + size * 0.8, y + size / 2, r, g, b);
						draw_line(x + size * 0.8, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.6, y, x + size * 0.6, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.4, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y + size, x + size * 0.8, y + size, r, g, b);
						x = x + size * 0.8 + size / 2;
					}


					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x + size / 2, y + size / 2, x, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '_' )
					{
						
						x = x + 1.5* size;
					}
				}

				break;

			case 2:

				for (int i = 0; i < strlen(text); i++)
				{
					if (text[i] == '�' || text[i] == '�')
					{

						draw_line(x, y + size, x + size / 3, y, r, g, b);
						draw_line(x + size / 3, y, x + size / 2, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);

						x = x + (size / 2) + size / 2;
					}
					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size * 0.75, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size * 0.75, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x + size / 2, y + size * 0.25, x, y + size / 2, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size * 0.75, r, g, b);
						draw_line(x + size / 2, y + size * 0.75, x, y + size, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size / 2, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size, y + size / 2, r, g, b);
						draw_line(x + size, y + size / 2, x + size, y + size, r, g, b);
						draw_line(x + size * 0.25, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size * 0.75, y + size / 2, r, g, b);
						x = x + size + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size * 0.75, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size * 0.75, r, g, b);
						draw_line(x + size * 0.15, y - size * 0.25, x + size * 0.15, y - size * 0.15, r, g, b);
						draw_line(x + size * 0.45, y - size * 0.25, x + size * 0.45, y - size * 0.15, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size, y + size, r, g, b);
						draw_line(x, y + size, x + size, y, r, g, b);
						draw_line(x + size / 2, y + size * 0.10, x + size / 2, y + size * 0.9, r, g, b);
						x = x + size + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
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

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.40, y, r, g, b);
						draw_line(x + size * 0.40, y, x + size * 0.40, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size * 0.40, y, r, g, b);
						draw_line(x + size * 0.40, y, x + size * 0.40, y + size, r, g, b);
						draw_line(x + size * 0.10, y - size * 0.15, x + size * 0.30, y - size * 0.15, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x, y + size / 2, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size, x + size * 0.30, y, r, g, b);
						draw_line(x + size * 0.30, y, x + size * 0.60, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size * 0.30, y + size / 2, r, g, b);
						draw_line(x + size * 0.30, y + size / 2, x + size * 0.60, y, r, g, b);
						draw_line(x + size * 0.60, y, x + size * 0.60, y + size, r, g, b);
						x = x + size / 2 + size / 2;

					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size * 0.30, x + size / 2, y + size * 0.30, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;

					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size, y + size / 2, r, g, b);
						draw_line(x + size, y + size / 2, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size / 2, r, g, b);
						x = x + size  + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y, x + size / 2, y + size * 0.25, r, g, b);
						draw_line(x + size / 2, y + size * 0.25, x, y + size / 2, r, g, b);
						x = x + (size / 2) + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size / 2, x + size / 2, y, r, g, b);
						draw_line(x + size / 2, y, x + size, y + size * 0.2, r, g, b);
						draw_line(x + size, y + size * 0.80, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x, y + size / 2, r, g, b);
						x = x + size  + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.5, y, r, g, b);
						draw_line(x + size * 0.25, y, x + size * 0.25, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.4, y + size / 2, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x + size * 0.8, y, r, g, b);
						draw_line(x + size * 0.4, y + size / 2, x, y + size, r, g, b);
						x = x + size * 0.7 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y + size * 0.25, x + size * 0.4, y, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.8, y + size * 0.25, r, g, b);
						draw_line(x + size * 0.8, y + size * 0.25, x + size * 0.4, y + size * 0.5, r, g, b);
						draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
						draw_line(x, y + size * 0.25, x + size * 0.4, y + size / 2, r, g, b);
						x = x + size * 0.8 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x + size * 0.6, y + size, r, g, b);
						draw_line(x + size * 0.6, y, x, y + size, r, g, b);
						x = x + size / 2 + size / 2;
					}

					if (text[i] == '�' || text[i] == '�')
					{
						draw_line(x, y, x, y + size, r, g, b);
						draw_line(x, y + size, x + size / 2, y + size, r, g, b);
						draw_line(x + size / 2, y + size, x + size / 2, y + size / 2, r, g, b);
						draw_line(x, y + size, x + size * 0.7, y + size, r, g, b);
						draw_line(x + size * 0.7, y + size, x + size * 0.7, y + size * 1.2, r, g, b);
						x = x + size * 0.6 + size / 2;
					}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + size / 2, r, g, b);
							draw_line(x, y + size / 2, x + size / 4, y + size * 0.7, r, g, b);
							draw_line(x + size / 4, y + size * 0.7, x + size / 2, y + size / 2, r, g, b);
							draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x + size * 0.4, y + size * 0.25, x + size * 0.4, y + size, r, g, b);
							draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
							draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x + size * 0.4, y + size * 0.25, x + size * 0.4, y + size, r, g, b);
							draw_line(x + size * 0.8, y, x + size * 0.8, y + size, r, g, b);
							draw_line(x, y + size, x + size * 0.8, y + size, r, g, b);
							draw_line(x + size * 0.8, y + size, x + size, y + size, r, g, b);
							draw_line(x + size, y + size, x + size, y + size * 1.1, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x + size * 0.4, y, r, g, b);
							draw_line(x + size * 0.4, y, x + size * 0.4, y + size, r, g, b);
							draw_line(x + size * 0.4, y + size / 2, x + size * 0.8, y + size * 0.75, r, g, b);
							draw_line(x + size * 0.8, y + size * 0.75, x + size * 0.4, y + size, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x, y + size / 2, x + size * 0.4, y + size * 0.75, r, g, b);
							draw_line(x, y + size, x + size * 0.4, y + size * 0.75, r, g, b);
							draw_line(x + size * 0.6, y, x + size * 0.6, y + size, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x, y + size / 2, x + size * 0.4, y + size * 0.75, r, g, b);
							draw_line(x, y + size, x + size * 0.4, y + size * 0.75, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x + size / 4, y - size * 0.2, r, g, b);
							draw_line(x + size / 4, y - size * 0.2, x + size / 2, y, r, g, b);
							draw_line(x + size / 2, y + size, x + size / 4, y + size * 1.2, r, g, b);
							draw_line(x + size / 4, y + size * 1.2, x, y + size, r, g, b);
							draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
							draw_line(x + size / 2, y + size / 2, x, y + size / 2, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x, y, x, y + size, r, g, b);
							draw_line(x, y + size / 2, x + size * 0.4, y + size / 2, r, g, b);
							draw_line(x + size * 0.4, y + size / 2, x + size * 0.6, y, r, g, b);
							draw_line(x + size * 0.6, y, x + size * 0.8, y + size / 2, r, g, b);
							draw_line(x + size * 0.8, y + size / 2, x + size * 0.6, y + size, r, g, b);
							draw_line(x + size * 0.6, y + size, x + size * 0.4, y + size / 2, r, g, b);
							x = x + size * 0.8 + size / 2;
						}

						if (text[i] == '�' || text[i] == '�')
						{
							draw_line(x + size / 2, y, x + size / 2, y + size, r, g, b);
							draw_line(x + size / 2, y, x, y + size * 0.25, r, g, b);
							draw_line(x, y + size * 0.25, x + size / 2, y + size / 2, r, g, b);
							draw_line(x + size / 2, y + size / 2, x, y + size, r, g, b);
							x = x + size / 2 + size / 2;
						}

						if (text[i] == '_')
						{

							x = x + 1.5 * size;
						}
				}
				break;

				default: 
					MessageBox::Show("��� ������ ������");
					break;
			}
		}
		
		void set_orientation(int orientation)
		{
			MessageBox::Show("tyta");
			switch (orientation)
			{
			case 0:
				Img1->RotateFlip(RotateFlipType::RotateNoneFlipNone);
				pictureBox1->Image = Img1;
			
				
				break;
			case 1:
				Img1->RotateFlip(RotateFlipType::Rotate90FlipNone);
				pictureBox1->Image = Img1;
				break;
			case 2:
				Img1->RotateFlip(RotateFlipType::Rotate180FlipNone);
				pictureBox1->Image = Img1;
				break;

			case 3:
				Img1->RotateFlip(RotateFlipType::Rotate270FlipNone);
				pictureBox1->Image = Img1;
				break;

			default:
				break;

			}
			
		}

	

		void get_size(int width, int height)
		{
			Img2 = gcnew Bitmap(Img1,width, height);
			pictureBox1->Image = Img2;

			
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
				draw_text(com->x, com->y, com->r, com->g, com->b, com->font_number, com->size, com->text);
			}
			
			else if (com->name == "set_orientation")
			{
				set_orientation(com->orientation);
			}

			else if (com->name == "get_size")
			{
				get_size(com->width, com->height);
			}


		}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = buffer;
}

};
}

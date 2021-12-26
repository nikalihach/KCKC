#pragma once
#include "Parser.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
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
			//Img1 = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			//Img1 = gcnew Bitmap(600, 600);
			//gr = Graphics::FromImage(Img1);
			Img1 = gcnew Bitmap(600, 600);
			gr = Graphics::FromImage(Img1);


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
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1443, 857);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(0, 784);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1443, 21);
			this->textBox1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(0, 805);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 22);
			this->label2->TabIndex = 5;
			this->label2->Text = L"�������� �������:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(0, 827);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(1443, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"����������\r\n �������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1443, 857);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			  
			   Bitmap^ Img1;
			   Graphics^ gr;
			   
		

			   void set_orientation(int orientation)
			   {

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

			  
			   /*
			   void get_size(int width, int height)
			   {
				   Img1 = gcnew Bitmap(Img1,width, height);
				   pictureBox1->Image = Img1;
				   gr = Graphics::FromImage(Img1);
			   }
			   */

			   int get_width()
			   {
				   int  width = Img1->Width;
				 //MessageBox::Show("get_width", width.ToString());
				   return width;
				 
			   }

			   int get_height() 
			   {
				   int height = Img1->Height;
				   //MessageBox::Show("get_height", height.ToString());
				   return height;
			   }

			   int Width, Height;

			   void load_sprite(int index, int width, int height, char* data)
			   {
				   //MessageBox::Show("load_sprite");
				   String^ Index = index.ToString();
				   String^ Data  = gcnew String(data);

				   imageList1->Images->Add(Index, Image::FromFile(Data));
				  
				  Width = width;
				   Height = height;
				  
			   }

			   void show_sprite(int index, int x, int y)
			   {
				   //MessageBox::Show("show_sprite");
				   String^ Index = index.ToString();
				   int ind  = imageList1->Images->IndexOfKey(Index);
				   Image^ img = imageList1->Images[ind];
				  
				   gr->DrawImage(img, x, y, Width, Height);
				   pictureBox1->Image = Img1;

			   }


		void clear_display(int r, int g, int b)
		{
			
			 //gr = this->CreateGraphics();
			Color aColor = Color::FromArgb(r, g, b);
			gr->Clear(aColor);

			pictureBox1->Image = Img1;
			

		}

		void draw_pixel(int x0, int y0, int r, int g, int b)
		{
			
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			 //gr = this->CreateGraphics();
			gr->FillRectangle(aBrush, x0, y0, 1, 1);
			pictureBox1->Image = Img1;
		}

		void draw_line(int x0, int y0, int x1, int y1, int r, int g, int b)
		{
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			//Graphics^ gr = this->CreateGraphics();
			//gr = pictureBox1->CreateGraphics();
			gr->DrawLine(color, x0, y0, x1, y1);
			pictureBox1->Image = Img1;
		
		}

		void draw_rectangle(int x0, int y0, int w, int h, int r, int g, int b)
		{
			
		
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			 //gr = this->CreateGraphics();
			gr->DrawRectangle(color, x0, y0, w, h);
			pictureBox1->Image = Img1;
		}

		void fill_rectangle(int x0, int y0, int w, int h, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^  aBrush = gcnew SolidBrush(aColor);
			 //gr = this->CreateGraphics();
			gr->FillRectangle(aBrush, x0, y0, w, h);
			pictureBox1->Image = Img1;
		}

		void draw_ellipse(int x0, int y0, int rx, int ry, int r, int g, int b)
		{
			Pen^ color = gcnew Pen(Color::FromArgb(r, g, b));
			// gr = this->CreateGraphics();
			gr->DrawEllipse(color, x0, y0, rx, ry);
			pictureBox1->Image = Img1;
		}

		void fill_ellipse(int x0, int y0, int rx, int ry, int r, int g, int b)
		{
			Color aColor = Color::FromArgb(r, g, b);
			SolidBrush^ aBrush = gcnew SolidBrush(aColor);
			// gr = this->CreateGraphics();
			gr->FillEllipse(aBrush, x0, y0, rx, ry);
			pictureBox1->Image = Img1;
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

					if (text[i] == ' ' )
					{
						
						x = x +  size;
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

						if (text[i] == ' ')
						{

							x = x +  size;
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

			char buff[20000];
			char buff2[1000];
			
			int const buffer_size = 1024;
			char buffer2[buffer_size];

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

			string ip = "127.0.0.1";

			sockaddr_in local_addr;
			local_addr.sin_family = AF_INET;
			local_addr.sin_addr.s_addr = inet_addr(ip.c_str());
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

				 if (one.name == "get_width")
				{
					 one.width = get_width();
					snprintf(buff2, 100, "Width: %i", one.width);
					sendto(my_sock, &buff2[0], strlen(&buff2[0]), 0, (sockaddr*)&client_addr, sizeof(client_addr));

				}

				  if (one.name == "get_height")
				 {
					 one.height = get_height();
					 snprintf(buff2, 100, "Height: %i", one.height);
					 sendto(my_sock, &buff2[0], strlen(&buff2[0]), 0, (sockaddr*)&client_addr, sizeof(client_addr));
				 }

				  if (one.name == "load_sprite")
				  {
					  Get_sprite(one.data);
					  load_sprite(one.index, one.width, one.height, one.data);
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

			else if (com->name == "show_sprite")
			{
				show_sprite(com->index, com->x, com->y);
			}

			
			/*
			else if (com->name == "get_size")
			{
				get_size(com->width, com->height);
			}
			*/


		}


		void Get_sprite(char* data)
		{
			WSADATA wsaData;
			int winsock_result = WSAStartup(MAKEWORD(2, 2), &wsaData);

			SOCKET server_socket;
			server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

			if (server_socket == INVALID_SOCKET)
			{
				WSACleanup();
			}

			string ip_address = "127.0.0.1";
			int port = 6666;

			SOCKADDR_IN client;
			client.sin_family = AF_INET;
			client.sin_port = htons(port);
			client.sin_addr.s_addr = inet_addr(ip_address.c_str());

			int client_sizeof = sizeof(client);

			int const buffer_size = 1024;
			char buffer[buffer_size];


			if (sendto(server_socket, "Ready", 5, 0, (SOCKADDR*)&client, client_sizeof) == SOCKET_ERROR)
			{
				closesocket(server_socket);
				WSACleanup();
			}

			FILE* file;
			file = fopen(data, "wb");

			int received_size = 0;
			while (true)
			{
				received_size = recvfrom(server_socket, buffer, buffer_size, 0, (SOCKADDR*)&client, &client_sizeof);
				if (received_size == SOCKET_ERROR)
				{
					fclose(file);
					closesocket(server_socket);
					WSACleanup();
					
				}
				
				else if (strcmp(buffer, "QUIT") == 0)
				{
					cout << "�������� ���������." << endl;
					break;
				}

				fwrite(buffer, sizeof(char), received_size, file);
			}
			fclose(file);

			closesocket(server_socket);
			WSACleanup();
		}




private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = buffer;
}

};
}

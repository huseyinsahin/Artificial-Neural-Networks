#pragma once

#include <time.h>
#include "Process.h"
#include <iostream>
#include "pch.h"
#include "perceptronRule.h"
#include "deltaRule.h"
#include "Resource.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			total_Sample_Size = classCount = classLabel = 0;
			class_Size = new int[10];
			for (int i = 0; i < 10; i++)
				class_Size[i] = 0;
			w = new double[3];
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		/// <summary>

		Samples* sample;
		int total_Sample_Size, *class_Size;
		int isNormalized = 0;
		int classCount, classLabel;
		double* w;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initializingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binaryDiscToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initializingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryDiscToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(13, 58);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 426);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint_1);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick_1);
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(1018, 37);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->initializingToolStripMenuItem,
					this->trainingToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->processToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(91, 29);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// initializingToolStripMenuItem
			// 
			this->initializingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomlyToolStripMenuItem });
			this->initializingToolStripMenuItem->Name = L"initializingToolStripMenuItem";
			this->initializingToolStripMenuItem->Size = System::Drawing::Size(201, 34);
			this->initializingToolStripMenuItem->Text = L"Initializing";
			// 
			// randomlyToolStripMenuItem
			// 
			this->randomlyToolStripMenuItem->Name = L"randomlyToolStripMenuItem";
			this->randomlyToolStripMenuItem->Size = System::Drawing::Size(197, 34);
			this->randomlyToolStripMenuItem->Text = L"Randomly";
			this->randomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::randomlyToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryDiscToolStripMenuItem,
					this->continousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(201, 34);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// binaryDiscToolStripMenuItem
			// 
			this->binaryDiscToolStripMenuItem->Name = L"binaryDiscToolStripMenuItem";
			this->binaryDiscToolStripMenuItem->Size = System::Drawing::Size(213, 34);
			this->binaryDiscToolStripMenuItem->Text = L"Binary(Disc)";
			this->binaryDiscToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::binaryDiscToolStripMenuItem_Click_1);
			// 
			// continousToolStripMenuItem
			// 
			this->continousToolStripMenuItem->Name = L"continousToolStripMenuItem";
			this->continousToolStripMenuItem->Size = System::Drawing::Size(213, 34);
			this->continousToolStripMenuItem->Text = L"Continious";
			this->continousToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::continousToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"1", L"2", L"3", L"4", L"5", L"6" });
			this->comboBox1->Location = System::Drawing::Point(696, 101);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(134, 33);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(563, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Sınıf Sayısı";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(563, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Sınıf Etiketi";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(568, 208);
			this->checkBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(123, 29);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Normalize";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &Form1::checkBox1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(854, 101);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 81);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Sınıf Sayısını Onayla";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(697, 151);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(133, 31);
			this->numericUpDown1->TabIndex = 10;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(563, 257);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 25);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(563, 297);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 25);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(563, 334);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 25);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(563, 368);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 25);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(563, 403);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 25);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(563, 436);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 25);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Label8";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1018, 530);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Single Layer / Multi Level";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		classCount = comboBox1->SelectedIndex + 1;
		w = new double[classCount * 3];
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		numericUpDown1->Maximum = classCount;
		numericUpDown1->Minimum = 1;
		delete w;
		w = new double[classCount * 3];
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		classLabel = (int)numericUpDown1->Value - 1;
	}
	private: System::Void pictureBox1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		//Ana eksen dogrularinin cizilmesi

		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	private: System::Void pictureBox1_MouseClick_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		//Eksen uzerinde orneklerin cizilmesi

		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int temp_x, temp_y;
		double x1, x2; //x1 = width, x2 = height
		temp_x = (Convert::ToInt32(e->X));
		temp_y = (Convert::ToInt32(e->Y));
		x1 = (double)(temp_x - (pictureBox1->Width >> 1));
		x2 = (double)((pictureBox1->Height >> 1) - temp_y);
		if (total_Sample_Size == 0) {
			total_Sample_Size = class_Size[classLabel] = 1;
			sample = new Samples[1];
			sample[0].x1 = x1;
			sample[0].x2 = x2;
			sample[0].id = classLabel;
		}
		else {
			Samples* temp;
			temp = sample;
			class_Size[classLabel]++;
			total_Sample_Size++;
			sample = new Samples[total_Sample_Size];
			for (int i = 0; i < total_Sample_Size - 1; i++) {
				sample[i].x1 = temp[i].x1;
				sample[i].x2 = temp[i].x2;
				sample[i].id = temp[i].id;
			}

			sample[total_Sample_Size - 1].x1 = x1;
			sample[total_Sample_Size - 1].x2 = x2;
			sample[total_Sample_Size - 1].id = classLabel;
			delete temp;

		}//else

		switch (classLabel) {
		case 0:pen = gcnew Pen(Color::Black, 3.0f); sample[total_Sample_Size - 1].color = 0; break;
		case 1:pen = gcnew Pen(Color::Blue, 3.0f); sample[total_Sample_Size - 1].color = 1;  break;
		case 2:pen = gcnew Pen(Color::Red, 3.0f); sample[total_Sample_Size - 1].color = 2;  break;
		case 3:pen = gcnew Pen(Color::Orange, 3.0f); sample[total_Sample_Size - 1].color = 3; break;
		case 4:pen = gcnew Pen(Color::Green, 3.0f); sample[total_Sample_Size - 1].color = 4; break;
		case 5:pen = gcnew Pen(Color::Yellow, 3.0f); sample[total_Sample_Size - 1].color = 5; break;
		default:pen = gcnew Pen(Color::Purple, 3.0f); sample[total_Sample_Size - 1].color = 6; break;
		}

		label3->Text = "x1: " + Convert::ToString(sample[total_Sample_Size - 1].x1) + " x2: " + Convert::ToString(sample[total_Sample_Size - 1].x2);
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		label4->Text = "Samples Total : " + Convert::ToString(total_Sample_Size) + " Class(" + Convert::ToString(classLabel + 1) + ") : " + Convert::ToString(class_Size[classLabel]);
	}
	
	private: System::Void randomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Rastgele ayirtac dogrularinin cizdirilmesi (w1*x1 + w2*x2 + w3 = 0)

		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		srand(time(0));

		for (int label = 0; label < classCount; label++) {
			for (int i = 0; i < 3; i++)
				w[3 * label + i] = ((double)rand() / (RAND_MAX));

			label5->Text = " w[0]: " + System::Convert::ToString(w[3 * label]);
			label6->Text = " w[1]: " + System::Convert::ToString(w[3 * label + 1]);
			label7->Text = " w[2]: " + System::Convert::ToString(w[3 * label + 2]);
			
			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, &w[3 * label]);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, &w[3 * label]);

			switch (label) {
			case 0:pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1:pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 2:pen = gcnew Pen(Color::Red, 3.0f); break;
			case 3:pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 4:pen = gcnew Pen(Color::Green, 3.0f); break;
			case 5:pen = gcnew Pen(Color::Yellow, 3.0f); break;
			default:pen = gcnew Pen(Color::Purple, 3.0f); break;
			}

			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}

	private: System::Void binaryDiscToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		
		//Ayrik aktivasyon fonksiyonuyla orneklerin siniflandirilmasi

		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		pictureBox1->Refresh();
		for (int i = 0; i < total_Sample_Size; i++) {
			int temp_x = Convert::ToInt32(sample[i].x1 + (pictureBox1->Width >> 1));
			int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - sample[i].x2);

			switch (sample[i].id) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}

		for (int category = 0; category < classCount; category++) {
			Samples* tmp_sample = new Samples[total_Sample_Size];

			for (int i = 0; i < 3; i++)
				w[i] = ((double)rand() / (RAND_MAX));
			
			for (int i = 0; i < total_Sample_Size; i++) {
				tmp_sample[i].x1 = sample[i].x1;
				tmp_sample[i].x2 = sample[i].x2;
				
				if (sample[i].id == category) {
					tmp_sample[i].id = 1;
				}
				else {
					tmp_sample[i].id = 0;
				}
			}

			for (int i = 0; i < total_Sample_Size; i++) {
				tmp_sample[i].x1 /= pictureBox1->Width;
				tmp_sample[i].x2 /= pictureBox1->Width;
			}

			int cycle = 10000, allCyclesDone;

			int j;

			for (j = 0; j < cycle; j++) {
				int* training_done = new int[total_Sample_Size];
				allCyclesDone = 1; //Butun cycle'lar tamamlandimi
				for (int i = 0; i < total_Sample_Size; i++)
					training_done[i] = perceptronRule(tmp_sample[i], w, 0.1);
				for (int i = 0; i < total_Sample_Size; i++)
					if (training_done[i] == 0)
						allCyclesDone = 0;
				if (allCyclesDone)
					break;
			}

			switch (category) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			label5->Text = " w[0]: " + System::Convert::ToString(w[0]);
			label6->Text = " w[1]: " + System::Convert::ToString(w[1]);
			label7->Text = " w[2]: " + System::Convert::ToString(w[2]);
			label8->Text = " Cycle: " + System::Convert::ToString(j);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w, pictureBox1->Width);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w, pictureBox1->Width);
			
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}
	private: System::Void continousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Surekli aktivasyon fonksiyonuyla orneklerin siniflandirilmasi

		if (!isNormalized) {
			MessageBox::Show("Öncelikle normalize yapman gerekiyor!!");
			return;
		}
		
		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		pictureBox1->Refresh();
		for (int i = 0; i < total_Sample_Size; i++) {
			int temp_x = Convert::ToInt32((pictureBox1->Width) * sample[i].x1 + (pictureBox1->Width >> 1));
			int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - pictureBox1->Width * sample[i].x2);

			switch (sample[i].id) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			if (!isNormalized) {
				pictureBox1->CreateGraphics()->DrawLine(pen, pictureBox1->Width * (temp_x - 5), pictureBox1->Width * (temp_y), pictureBox1->Width * (temp_x + 5), pictureBox1->Width * (temp_y));
				pictureBox1->CreateGraphics()->DrawLine(pen, pictureBox1->Width * (temp_x), pictureBox1->Width * (temp_y - 5), pictureBox1->Width * (temp_x), pictureBox1->Width * (temp_y + 5));
			}
			else {
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
		}

		for (int category = 0; category < classCount; category++) {
			Samples* tmp_sample = new Samples[total_Sample_Size];

			for (int i = 0; i < 3; i++)
				w[i] = ((double)rand() / (RAND_MAX));

			for (int i = 0; i < total_Sample_Size; i++) {
				tmp_sample[i].x1 = sample[i].x1;
				tmp_sample[i].x2 = sample[i].x2;

				if (sample[i].id == category) {
					tmp_sample[i].id = 1;
				}
				else {
					tmp_sample[i].id = 0;
				}
			}

			int cycle = 10000, allCyclesDone;

			int j;

			for (j = 0; j < cycle; j++) {
				int* training_done = new int[total_Sample_Size];
				allCyclesDone = 1; //Butun cycle'lar tamamlandimi
				for (int i = 0; i < total_Sample_Size; i++)
					training_done[i] = deltaRule(tmp_sample[i], w, 0.1);
				for (int i = 0; i < total_Sample_Size; i++)
					if (training_done[i] == 0)
						allCyclesDone = 0;
				if (allCyclesDone)
					break;
			}

			switch (category) {
			case 0:pen->Color = Color::Black; break;
			case 1:pen->Color = Color::Blue; break;
			case 2:pen->Color = Color::Red; break;
			case 3:pen->Color = Color::Orange; break;
			case 4:pen->Color = Color::Green; break;
			case 5:pen->Color = Color::Yellow; break;
			default:pen->Color = Color::Purple; break;
			}

			label5->Text = " w[0]: " + System::Convert::ToString(w[0]);
			label6->Text = " w[1]: " + System::Convert::ToString(w[1]);
			label7->Text = " w[2]: " + System::Convert::ToString(w[2]);
			label8->Text = " Cycle: " + System::Convert::ToString(j);
			
			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w, pictureBox1->Width);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w, pictureBox1->Width);

			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}
	private: System::Void checkBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Normalizasyonun gerceklenmesi
		
		if (!isNormalized) {
			for (int i = 0; i < total_Sample_Size; i++) {
				sample[i].x1 /= pictureBox1->Width;
				sample[i].x2 /= pictureBox1->Width;
			}
			isNormalized = 1;
		}
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Uygulamanin kapatilmasi
		
		Application::Exit();
	}
};
}

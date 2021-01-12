#pragma once

#include "Resource.h"
#include <time.h>
#include "Process.h"
#include <iostream>
#include "pch.h"
#include "perceptronRule.h"
#include "deltaRule.h"


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

			total_Sample_Size = class1_Size = class2_Size = 0;
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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initialToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::CheckBox^ check_Class1;
	private: System::Windows::Forms::CheckBox^ check_Class2;



	private:
		/// <summary>

		Samples *sample;
		int total_Sample_Size, class1_Size, class2_Size;
		int isNormalized = 0;
		double* w;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ToolStripMenuItem^ ramdomlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binaryDiscToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continiousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;


	private: System::Windows::Forms::CheckBox^ checkBox1;




	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;





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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ramdomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryDiscToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continiousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->check_Class1 = (gcnew System::Windows::Forms::CheckBox());
			this->check_Class2 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1414, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->initialToolStripMenuItem,
					this->trainingToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->processToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(91, 29);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// initialToolStripMenuItem
			// 
			this->initialToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ramdomlyToolStripMenuItem });
			this->initialToolStripMenuItem->Name = L"initialToolStripMenuItem";
			this->initialToolStripMenuItem->Size = System::Drawing::Size(182, 34);
			this->initialToolStripMenuItem->Text = L"Initial";
			// 
			// ramdomlyToolStripMenuItem
			// 
			this->ramdomlyToolStripMenuItem->Name = L"ramdomlyToolStripMenuItem";
			this->ramdomlyToolStripMenuItem->Size = System::Drawing::Size(202, 34);
			this->ramdomlyToolStripMenuItem->Text = L"Ramdomly";
			this->ramdomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ramdomlyToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryDiscToolStripMenuItem,
					this->continiousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(182, 34);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// binaryDiscToolStripMenuItem
			// 
			this->binaryDiscToolStripMenuItem->Name = L"binaryDiscToolStripMenuItem";
			this->binaryDiscToolStripMenuItem->Size = System::Drawing::Size(213, 34);
			this->binaryDiscToolStripMenuItem->Text = L"Binary(Disc)";
			this->binaryDiscToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::binaryDiscToolStripMenuItem_Click);
			// 
			// continiousToolStripMenuItem
			// 
			this->continiousToolStripMenuItem->Name = L"continiousToolStripMenuItem";
			this->continiousToolStripMenuItem->Size = System::Drawing::Size(213, 34);
			this->continiousToolStripMenuItem->Text = L"Continious";
			this->continiousToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::continiousToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(182, 34);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(13, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(770, 624);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// check_Class1
			// 
			this->check_Class1->AutoSize = true;
			this->check_Class1->Checked = true;
			this->check_Class1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->check_Class1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->check_Class1->Location = System::Drawing::Point(825, 82);
			this->check_Class1->Name = L"check_Class1";
			this->check_Class1->Size = System::Drawing::Size(91, 29);
			this->check_Class1->TabIndex = 2;
			this->check_Class1->Text = L"Class 1";
			this->check_Class1->UseVisualStyleBackColor = true;
			// 
			// check_Class2
			// 
			this->check_Class2->AutoSize = true;
			this->check_Class2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->check_Class2->Location = System::Drawing::Point(825, 140);
			this->check_Class2->Name = L"check_Class2";
			this->check_Class2->Size = System::Drawing::Size(94, 29);
			this->check_Class2->TabIndex = 3;
			this->check_Class2->Text = L"Class 2";
			this->check_Class2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(825, 204);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(825, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Label2";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(1024, 82);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(123, 29);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Normalize";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &Form1::checkBox1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(825, 299);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 25);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(825, 346);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 25);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(825, 388);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 25);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(825, 432);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 25);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Label6";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1414, 700);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->check_Class2);
			this->Controls->Add(this->check_Class1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Single Layer / Single Level";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			
			//Ana eksen dogrularinin cizilmesi

			Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			int center_width, center_height;
			center_width = (int)(pictureBox1->Width / 2);
			center_height = (int)(pictureBox1->Height / 2);
			e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
			e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
		}
		private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			
			//Eksen uzerinde orneklerin cizilmesi

			if (check_Class1->Checked || check_Class2->Checked) {
				if (check_Class1->Checked && check_Class2->Checked) {
					MessageBox::Show("Her iki sinif türü ayni anda seçilemez.");
					check_Class1->Checked = false;
					check_Class2->Checked = false;
				}
				else {
					if (check_Class1->Checked) {
						Pen^ pen = gcnew Pen(Color::Black, 3.0f);
						int temp_x, temp_y;
						double x1, x2; //x1 = width, x2 = height
						temp_x = (Convert::ToInt32(e->X));
						temp_y = (Convert::ToInt32(e->Y));

						// Noktalarin ana eksenin merkezine gore tasinmasi

						x1 = (double)(temp_x - (pictureBox1->Width >> 1));
						x2 = (double)((pictureBox1->Height >> 1) - temp_y);

						if (total_Sample_Size == 0) {
							total_Sample_Size = class1_Size = 1;
							sample = new Samples[1];
							sample[0].x1 = x1;
							sample[0].x2 = x2;
							sample[0].id = CLASS1;
						}
						else {
							Samples* temp;
							temp = sample;
							class1_Size++;
							total_Sample_Size++;
							sample = new Samples[total_Sample_Size];
							for (int i = 0; i < total_Sample_Size - 1; i++) {
								sample[i].x1 = temp[i].x1;
								sample[i].x2 = temp[i].x2;
								sample[i].id = temp[i].id;
							}

							sample[total_Sample_Size - 1].x1 = x1;
							sample[total_Sample_Size - 1].x2 = x2;
							sample[total_Sample_Size - 1].id = CLASS1;
							delete temp;

						}

						label1->Text = "x1 = " + Convert::ToString(sample[total_Sample_Size - 1].x1) + "  x2 = " + Convert::ToString(sample[total_Sample_Size - 1].x2);
						pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
						pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
						label2->Text = "Samples Total = " + Convert::ToString(total_Sample_Size) + "  Class 1 = " + Convert::ToString(class1_Size);
					
					}
					//Class2 icin
					else {
						if (check_Class2->Checked) {
							Pen^ pen = gcnew Pen(Color::Red, 3.0f);
							int temp_x, temp_y;
							double x1, x2; //x1 = width, x2 = height
							temp_x = (Convert::ToInt32(e->X));
							temp_y = (Convert::ToInt32(e->Y));
							x2 = (double)((pictureBox1->Height >> 1) - temp_y);
							x1 = (double)(temp_x - (pictureBox1->Width >> 1));
							if (total_Sample_Size == 0) {
								total_Sample_Size = class2_Size = 1;
								sample = new Samples[1];
								sample[0].x1 = x1;
								sample[0].x2 = x2;
								sample[0].id = CLASS2;
							}
							else {
								Samples* temp;
								temp = sample;
								class2_Size++;
								total_Sample_Size++;
								sample = new Samples[total_Sample_Size];
								for (int i = 0; i < total_Sample_Size - 1; i++) {
									sample[i].x1 = temp[i].x1;
									sample[i].x2 = temp[i].x2;
									sample[i].id = temp[i].id;
								}

								sample[total_Sample_Size - 1].x1 = x1;
								sample[total_Sample_Size - 1].x2 = x2;
								sample[total_Sample_Size - 1].id = CLASS2;
								delete temp;

							}
							
							label1->Text = "x1 = " + Convert::ToString(sample[total_Sample_Size - 1].x1) + "  x2 = " + Convert::ToString(sample[total_Sample_Size - 1].x2);
							pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
							pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
							label2->Text = "Samples Total = " + Convert::ToString(total_Sample_Size) + "  Class 2 = " + Convert::ToString(class2_Size);
						}
					}
				}
			}
			else {
				MessageBox::Show("Öncelikle örneklerin etiketini belirlemek için ilgili sinifi seçin.");
			}
		}
		private: System::Void ramdomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
			//Rastgele ayirtac dogrusunun cizdirilmesi (w1*x1 + w2*x2 + w3 = 0)

			Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			int min_x, max_x, min_y, max_y;

			w = new double[3];
			srand(time(0));
			for (int i = 0; i < 3; i++)
				w[i] = ((double)rand() / (RAND_MAX));

			label3->Text = "w[0]: " + System::Convert::ToString(w[0]);
			label4->Text = "w[1]: " + System::Convert::ToString(w[1]);
			label5->Text = "w[2]: " + System::Convert::ToString(w[2]);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

		}
		private: System::Void binaryDiscToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
			//Ayrik aktivasyon fonksiyonuyla orneklerin siniflandirilmasi

			Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			int min_x, max_x, min_y, max_y;

			pictureBox1->Refresh();
			for (int i = 0; i < total_Sample_Size; i++) {
				int temp_x = Convert::ToInt32(sample[i].x1 + (pictureBox1->Width >> 1));
				int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - sample[i].x2);

				switch (sample[i].id) {
				case 0:pen->Color = Color::Black; break;
				case 1:pen->Color = Color::Red; break;
				default:pen->Color = Color::Purple; break;
				}

				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
			
			int cycle = 10000, allCyclesDone;
			
			int j;

			for (j = 0; j < cycle; j++){
				int* training_done = new int[total_Sample_Size];
				allCyclesDone = 1; //Butun cycle'lar tamamlandimi
				for (int i = 0; i < total_Sample_Size; i++)
					training_done[i] = perceptronRule(sample[i], w, 0.1);
				for (int i = 0; i < total_Sample_Size; i++)
					if (training_done[i] == 0)
						allCyclesDone = 0;
				if (allCyclesDone)
					break;
			}
				
			label3->Text = "w[0]: " + System::Convert::ToString(w[0]);
			label4->Text = "w[1]: " + System::Convert::ToString(w[1]);
			label5->Text = "w[2]: " + System::Convert::ToString(w[2]);
			label6->Text = " cycle: " + System::Convert::ToString(j);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w);

			pen->Color = Color::Blue;
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}

		private: System::Void continiousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
			//Surekli aktivasyon fonksiyonuyla orneklerin siniflandirilmasi

			if (!isNormalized) {
				MessageBox::Show("Öncelikle normalize yapman gerekiyor!!");
				return;
			}
			
			Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			pictureBox1->Refresh();
			for (int i = 0; i < total_Sample_Size; i++) {
				int temp_x = Convert::ToInt32((pictureBox1->Width) * sample[i].x1 + (pictureBox1->Width >> 1));
				int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - pictureBox1->Width * sample[i].x2);

				switch (sample[i].id) {
				case 0:pen->Color = Color::Black; break;
				case 1:pen->Color = Color::Red; break;
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

			pen->Color = Color::Blue;

			int min_x, max_x, min_y, max_y;

			int cycle = 10000, allCyclesDone;

			int j;

			for (j = 0; j < cycle; j++) {
				int* training_done = new int[total_Sample_Size];
				allCyclesDone = 1; //Butun cycle'lar tamamlandimi
				for (int i = 0; i < total_Sample_Size; i++)
					training_done[i] = deltaRule(sample[i], w, 0.1);
				for (int i = 0; i < total_Sample_Size; i++)
					if (training_done[i] == 0)
						allCyclesDone = 0;
				if (allCyclesDone)
					break;
			}

			label3->Text = "w[0]: " + System::Convert::ToString(w[0]);
			label4->Text = "w[1]: " + System::Convert::ToString(w[1]);
			label5->Text = "w[2]: " + System::Convert::ToString(w[2]);
			label6->Text = " cycle: " + System::Convert::ToString(j);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, w, pictureBox1->Width);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, w, pictureBox1->Width);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
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

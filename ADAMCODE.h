#pragma once
#include "modbus.h"
#include <iostream>
#include <ctime>

namespace Project3 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	uint8_t tab_DI[2], tab_DO[2];
	uint16_t tab_reg[64];
	uint16_t tab_V[2];
	modbus_t* ctx1;
	modbus_t* ctx2;
	int rc,i;
	float f;
	Char time;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ConADAM;
	private: System::Windows::Forms::ProgressBar^ ADAM1;
	private: System::Windows::Forms::ProgressBar^ IONBar;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::TextBox^ ERRORTEXT;
	private: System::Windows::Forms::TextBox^ V_1;
	private: System::Windows::Forms::TextBox^ V_2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ Vion;
	private: System::Windows::Forms::TextBox^ AT;
	private: System::Windows::Forms::TextBox^ VT;
	private: System::Windows::Forms::TextBox^ PMT;
	private: System::Windows::Forms::TextBox^ Edwards;
	private: System::Windows::Forms::TextBox^ Temp;
	private: System::Windows::Forms::TextBox^ BPM;
	private: System::Windows::Forms::NumericUpDown^ AO0_1;
	private: System::Windows::Forms::NumericUpDown^ AO1_1;
	private: System::Windows::Forms::NumericUpDown^ AO1_2;
	private: System::Windows::Forms::NumericUpDown^ AO0_2;
	private: System::Windows::Forms::Button^ SetV_1;
	private: System::Windows::Forms::Button^ SetV_2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ProgressBar^ ADAM2;
	private: System::Windows::Forms::ProgressBar^ TBar;
	private:
	private: System::ComponentModel::IContainer^ components;
	protected:
	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>


#pragma region Windows Form Designer generated code
			/// <summary>
			/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
			/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
			/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ConADAM = (gcnew System::Windows::Forms::Button());
			this->ADAM1 = (gcnew System::Windows::Forms::ProgressBar());
			this->IONBar = (gcnew System::Windows::Forms::ProgressBar());
			this->ERRORTEXT = (gcnew System::Windows::Forms::TextBox());
			this->AO0_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->AO1_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->SetV_1 = (gcnew System::Windows::Forms::Button());
			this->V_1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ADAM2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->TBar = (gcnew System::Windows::Forms::ProgressBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->V_2 = (gcnew System::Windows::Forms::TextBox());
			this->SetV_2 = (gcnew System::Windows::Forms::Button());
			this->AO1_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->AO0_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->Vion = (gcnew System::Windows::Forms::TextBox());
			this->AT = (gcnew System::Windows::Forms::TextBox());
			this->VT = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->PMT = (gcnew System::Windows::Forms::TextBox());
			this->Edwards = (gcnew System::Windows::Forms::TextBox());
			this->Temp = (gcnew System::Windows::Forms::TextBox());
			this->BPM = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO0_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO1_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO1_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO0_2))->BeginInit();
			this->SuspendLayout();
			// 
			// ConADAM
			// 
			this->ConADAM->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ConADAM->Location = System::Drawing::Point(356, 53);
			this->ConADAM->Name = L"ConADAM";
			this->ConADAM->Size = System::Drawing::Size(180, 43);
			this->ConADAM->TabIndex = 0;
			this->ConADAM->Text = L"Connect to ADAM";
			this->ConADAM->UseVisualStyleBackColor = false;
			this->ConADAM->UseWaitCursor = true;
			this->ConADAM->Click += gcnew System::EventHandler(this, &MyForm::ConADAM_Click);
			// 
			// ADAM1
			// 
			this->ADAM1->Location = System::Drawing::Point(375, 3);
			this->ADAM1->Maximum = 1;
			this->ADAM1->Name = L"ADAM1";
			this->ADAM1->Size = System::Drawing::Size(30, 24);
			this->ADAM1->Step = 100;
			this->ADAM1->TabIndex = 1;
			this->ADAM1->UseWaitCursor = true;
			// 
			// IONBar
			// 
			this->IONBar->Location = System::Drawing::Point(132, 124);
			this->IONBar->Maximum = 1;
			this->IONBar->Name = L"IONBar";
			this->IONBar->Size = System::Drawing::Size(88, 56);
			this->IONBar->Step = 1;
			this->IONBar->TabIndex = 6;
			this->IONBar->UseWaitCursor = true;
			this->IONBar->Click += gcnew System::EventHandler(this, &MyForm::IONBar_Click);
			// 
			// ERRORTEXT
			// 
			this->ERRORTEXT->Location = System::Drawing::Point(1, 439);
			this->ERRORTEXT->Multiline = true;
			this->ERRORTEXT->Name = L"ERRORTEXT";
			this->ERRORTEXT->ReadOnly = true;
			this->ERRORTEXT->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ERRORTEXT->Size = System::Drawing::Size(903, 266);
			this->ERRORTEXT->TabIndex = 8;
			this->ERRORTEXT->UseWaitCursor = true;
			// 
			// AO0_1
			// 
			this->AO0_1->DecimalPlaces = 3;
			this->AO0_1->Location = System::Drawing::Point(46, 222);
			this->AO0_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->AO0_1->Name = L"AO0_1";
			this->AO0_1->Size = System::Drawing::Size(120, 20);
			this->AO0_1->TabIndex = 13;
			this->AO0_1->UseWaitCursor = true;
			// 
			// AO1_1
			// 
			this->AO1_1->DecimalPlaces = 3;
			this->AO1_1->Location = System::Drawing::Point(46, 248);
			this->AO1_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->AO1_1->Name = L"AO1_1";
			this->AO1_1->Size = System::Drawing::Size(120, 20);
			this->AO1_1->TabIndex = 14;
			this->AO1_1->UseWaitCursor = true;
			// 
			// SetV_1
			// 
			this->SetV_1->Location = System::Drawing::Point(46, 275);
			this->SetV_1->Name = L"SetV_1";
			this->SetV_1->Size = System::Drawing::Size(120, 49);
			this->SetV_1->TabIndex = 15;
			this->SetV_1->Text = L"Çàäàòü íàïðÿæåíèå";
			this->SetV_1->UseVisualStyleBackColor = true;
			this->SetV_1->UseWaitCursor = true;
			this->SetV_1->Click += gcnew System::EventHandler(this, &MyForm::SetV_1_Click);
			// 
			// V_1
			// 
			this->V_1->Location = System::Drawing::Point(172, 221);
			this->V_1->Multiline = true;
			this->V_1->Name = L"V_1";
			this->V_1->ReadOnly = true;
			this->V_1->Size = System::Drawing::Size(100, 102);
			this->V_1->TabIndex = 16;
			this->V_1->UseWaitCursor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(416, 423);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Òóò áóäóò îøèáêè";
			this->label1->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(172, 205);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Íàïðÿæåíèå íà âõîäàõ.";
			this->label2->UseWaitCursor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(43, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Ñîñòîÿíèå ION";
			this->label4->UseWaitCursor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(353, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"ADAM-6024 #1";
			this->label5->UseWaitCursor = true;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(35, 205);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(131, 13);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Íàïðÿæåíèå íà âûõîäàõ";
			// 
			// ADAM2
			// 
			this->ADAM2->Location = System::Drawing::Point(481, 3);
			this->ADAM2->Maximum = 1;
			this->ADAM2->Name = L"ADAM2";
			this->ADAM2->Size = System::Drawing::Size(30, 24);
			this->ADAM2->Step = 100;
			this->ADAM2->TabIndex = 30;
			this->ADAM2->UseWaitCursor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(461, 30);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(81, 13);
			this->label8->TabIndex = 31;
			this->label8->Text = L"ADAM-6024 #2";
			this->label8->UseWaitCursor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(633, 143);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(105, 13);
			this->label10->TabIndex = 34;
			this->label10->Text = L"Ñîñòîÿíèå íàãðåâà";
			this->label10->UseWaitCursor = true;
			// 
			// TBar
			// 
			this->TBar->Location = System::Drawing::Point(744, 124);
			this->TBar->Maximum = 1;
			this->TBar->Name = L"TBar";
			this->TBar->Size = System::Drawing::Size(88, 56);
			this->TBar->Step = 1;
			this->TBar->TabIndex = 32;
			this->TBar->UseWaitCursor = true;
			this->TBar->Click += gcnew System::EventHandler(this, &MyForm::TBar_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(115, 83);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 13);
			this->label11->TabIndex = 36;
			this->label11->Text = L"ADAM-6024 #1";
			this->label11->UseWaitCursor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(703, 83);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(81, 13);
			this->label12->TabIndex = 37;
			this->label12->Text = L"ADAM-6024 #2";
			this->label12->UseWaitCursor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(598, 205);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(131, 13);
			this->label13->TabIndex = 43;
			this->label13->Text = L"Íàïðÿæåíèå íà âûõîäàõ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(741, 205);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(126, 13);
			this->label14->TabIndex = 42;
			this->label14->Text = L"Íàïðÿæåíèå íà âõîäàõ.";
			this->label14->UseWaitCursor = true;
			// 
			// V_2
			// 
			this->V_2->Location = System::Drawing::Point(735, 222);
			this->V_2->Multiline = true;
			this->V_2->Name = L"V_2";
			this->V_2->ReadOnly = true;
			this->V_2->Size = System::Drawing::Size(100, 102);
			this->V_2->TabIndex = 41;
			this->V_2->UseWaitCursor = true;
			// 
			// SetV_2
			// 
			this->SetV_2->Location = System::Drawing::Point(609, 275);
			this->SetV_2->Name = L"SetV_2";
			this->SetV_2->Size = System::Drawing::Size(120, 49);
			this->SetV_2->TabIndex = 40;
			this->SetV_2->Text = L"Çàäàòü íàïðÿæåíèå";
			this->SetV_2->UseVisualStyleBackColor = true;
			this->SetV_2->UseWaitCursor = true;
			this->SetV_2->Click += gcnew System::EventHandler(this, &MyForm::SetV_2_Click);
			// 
			// AO1_2
			// 
			this->AO1_2->DecimalPlaces = 3;
			this->AO1_2->Location = System::Drawing::Point(609, 248);
			this->AO1_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->AO1_2->Name = L"AO1_2";
			this->AO1_2->Size = System::Drawing::Size(120, 20);
			this->AO1_2->TabIndex = 39;
			this->AO1_2->UseWaitCursor = true;
			// 
			// AO0_2
			// 
			this->AO0_2->DecimalPlaces = 3;
			this->AO0_2->Location = System::Drawing::Point(609, 222);
			this->AO0_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->AO0_2->Name = L"AO0_2";
			this->AO0_2->Size = System::Drawing::Size(120, 20);
			this->AO0_2->TabIndex = 38;
			this->AO0_2->UseWaitCursor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(245, 5);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(124, 22);
			this->textBox3->TabIndex = 46;
			this->textBox3->UseWaitCursor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(517, 5);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(124, 22);
			this->textBox4->TabIndex = 47;
			this->textBox4->UseWaitCursor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 225);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 48;
			this->label7->Text = L"AO 0";
			this->label7->UseWaitCursor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 250);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 13);
			this->label9->TabIndex = 49;
			this->label9->Text = L"AO 1";
			this->label9->UseWaitCursor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(572, 250);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 13);
			this->label15->TabIndex = 51;
			this->label15->Text = L"AO 1";
			this->label15->UseWaitCursor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(572, 225);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 13);
			this->label16->TabIndex = 50;
			this->label16->Text = L"AO 0";
			this->label16->UseWaitCursor = true;
			// 
			// Vion
			// 
			this->Vion->Location = System::Drawing::Point(172, 338);
			this->Vion->Multiline = true;
			this->Vion->Name = L"Vion";
			this->Vion->ReadOnly = true;
			this->Vion->Size = System::Drawing::Size(100, 28);
			this->Vion->TabIndex = 52;
			this->Vion->UseWaitCursor = true;
			// 
			// AT
			// 
			this->AT->Location = System::Drawing::Point(735, 338);
			this->AT->Multiline = true;
			this->AT->Name = L"AT";
			this->AT->ReadOnly = true;
			this->AT->Size = System::Drawing::Size(100, 28);
			this->AT->TabIndex = 53;
			this->AT->UseWaitCursor = true;
			// 
			// VT
			// 
			this->VT->Location = System::Drawing::Point(735, 372);
			this->VT->Multiline = true;
			this->VT->Name = L"VT";
			this->VT->ReadOnly = true;
			this->VT->Size = System::Drawing::Size(100, 28);
			this->VT->TabIndex = 54;
			this->VT->UseWaitCursor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(130, 341);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 55;
			this->label3->Text = L"V ION";
			this->label3->UseWaitCursor = true;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(680, 375);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(52, 13);
			this->label17->TabIndex = 56;
			this->label17->Text = L"V íàãðåâ";
			this->label17->UseWaitCursor = true;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(680, 341);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(52, 13);
			this->label18->TabIndex = 57;
			this->label18->Text = L"A íàãðåâ";
			this->label18->UseWaitCursor = true;
			// 
			// PMT
			// 
			this->PMT->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->PMT->Location = System::Drawing::Point(436, 258);
			this->PMT->Multiline = true;
			this->PMT->Name = L"PMT";
			this->PMT->ReadOnly = true;
			this->PMT->Size = System::Drawing::Size(100, 28);
			this->PMT->TabIndex = 58;
			this->PMT->UseWaitCursor = true;
			// 
			// Edwards
			// 
			this->Edwards->Location = System::Drawing::Point(436, 225);
			this->Edwards->Multiline = true;
			this->Edwards->Name = L"Edwards";
			this->Edwards->ReadOnly = true;
			this->Edwards->Size = System::Drawing::Size(100, 28);
			this->Edwards->TabIndex = 59;
			this->Edwards->UseWaitCursor = true;
			// 
			// Temp
			// 
			this->Temp->Location = System::Drawing::Point(436, 292);
			this->Temp->Multiline = true;
			this->Temp->Name = L"Temp";
			this->Temp->ReadOnly = true;
			this->Temp->Size = System::Drawing::Size(100, 28);
			this->Temp->TabIndex = 60;
			this->Temp->UseWaitCursor = true;
			// 
			// BPM
			// 
			this->BPM->Location = System::Drawing::Point(436, 326);
			this->BPM->Multiline = true;
			this->BPM->Name = L"BPM";
			this->BPM->ReadOnly = true;
			this->BPM->Size = System::Drawing::Size(100, 28);
			this->BPM->TabIndex = 61;
			this->BPM->UseWaitCursor = true;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(373, 261);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(60, 13);
			this->label19->TabIndex = 62;
			this->label19->Text = L"ÏÌÒ-4(Ïà)";
			this->label19->UseWaitCursor = true;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(365, 229);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(68, 13);
			this->label20->TabIndex = 63;
			this->label20->Text = L"Edwards(Ïà)";
			this->label20->UseWaitCursor = true;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(368, 329);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(65, 13);
			this->label21->TabIndex = 65;
			this->label21->Text = L"ÁÏÌ-025(À)";
			this->label21->UseWaitCursor = true;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(346, 295);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(87, 13);
			this->label22->TabIndex = 64;
			this->label22->Text = L"Òåìïåðàòóðà(Ñ)";
			this->label22->UseWaitCursor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(904, 741);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->BPM);
			this->Controls->Add(this->Temp);
			this->Controls->Add(this->Edwards);
			this->Controls->Add(this->PMT);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->VT);
			this->Controls->Add(this->AT);
			this->Controls->Add(this->Vion);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->V_2);
			this->Controls->Add(this->SetV_2);
			this->Controls->Add(this->AO1_2);
			this->Controls->Add(this->AO0_2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->TBar);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ADAM2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->V_1);
			this->Controls->Add(this->SetV_1);
			this->Controls->Add(this->AO1_1);
			this->Controls->Add(this->AO0_1);
			this->Controls->Add(this->ERRORTEXT);
			this->Controls->Add(this->IONBar);
			this->Controls->Add(this->ADAM1);
			this->Controls->Add(this->ConADAM);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->Location = System::Drawing::Point(187, 77);
			this->Name = L"MyForm";
			this->Text = L"ADAM6024 soft.";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO0_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO1_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO1_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AO0_2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
			{
				if (ADAM1->Value == 1)
				{
					rc = modbus_read_registers(ctx1, 0, 6, tab_reg);
					if (rc == -1)
					{
						const char* charstr = modbus_strerror(errno);
						String^ clistr = gcnew String(charstr);
						this->ERRORTEXT->Text += "Error!!" + "read registers" + clistr + "\r\n";
					}
					this->V_1->Text = "";
					for (i = 0; i < rc; i++)
					{
						this->V_1->Text += (tab_reg[i] - 32766) * 0.0003051944 + "\r\n";
					}
					rc = modbus_read_input_bits(ctx1, 0, 2, tab_DI);
					if (rc == -1)
					{
						const char* charstr = modbus_strerror(errno);
						String^ clistr = gcnew String(charstr);
						this->ERRORTEXT->Text += "Error!!" + "read input bits" + clistr + "\r\n";
					}
					IONBar->Value = tab_DI[1];
					
					this->Edwards->Text = "";//100kpa - 10^-7 pa
					this->PMT->Text = "";//100kpa - 10^-2 pa
					this->BPM->Text = "";//0a - 1a
					this->Vion->Text = "";//0V - 7kV
					float x= ((tab_reg[3] - 32766) * 0.0003051944);
					this->Edwards->Text += pow(10,(((tab_reg[0]) - 32766) * 0.0003051944 * 1.5 - 10));
					this->PMT->Text +=(0.547) + ((-0.136) * x) + (0.0267 * x * x) + ((-0.00184) * x * x * x);
					this->BPM->Text += (tab_reg[4] - 32766) * 0.0003051944 /10;
					this->Vion->Text += (tab_reg[5]-32766)*0.0003051944 * 700;
					//=0,547 + -0,136 *x + 0,0267*x^2 + -0,00184*x^3 PMT
				}
				else
				{
					const char* charstr = modbus_strerror(errno);
					String^ clistr = gcnew String(charstr);
					ERRORTEXT->Text += "Óñòðîéñòâî íå ïîäêëþ÷åíî" + clistr + "\r\n";
				}
				if (ADAM2->Value == 1)
				{
					rc = modbus_read_registers(ctx2, 0, 6, tab_reg);
					if (rc == -1)
					{
						const char* charstr = modbus_strerror(errno);
						String^ clistr = gcnew String(charstr);
						this->ERRORTEXT->Text += "Error!!" + "read registers" + clistr + "\r\n";
					}
					this->V_2->Text = "";
					for (i = 0; i < rc; i++)
					{
						this->V_2->Text += (tab_reg[i] - 32766) * 0.0003051944 + "\r\n";
					}
					rc = modbus_read_input_bits(ctx2, 0, 2, tab_DI);
					if (rc == -1)
					{
						const char* charstr = modbus_strerror(errno);
						String^ clistr = gcnew String(charstr);
						this->ERRORTEXT->Text += "Error!!" + "read input bits" + clistr + "\r\n";
					}
					TBar->Value = tab_DI[1];
					this->Temp->Text = "";//0C - 2000C
					this->AT->Text = "";
					this->VT->Text = "";
					this->Temp->Text += (tab_reg[3] - 32766) * 0.0003051944 *200;
					this->AT->Text += (tab_reg[4] - 32766) * 0.0003051944 * 10;
					this->VT->Text += (tab_reg[5] - 32766) * 0.0003051944 * 10;

				}
				else
				{
					const char* charstr = modbus_strerror(errno);
					String^ clistr = gcnew String(charstr);
					ERRORTEXT->Text += "Óñòðîéñòâî íå ïîäêëþ÷åíî" + clistr + "\r\n";
				}
			}
	private: System::Void ConADAM_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ctx1 = modbus_new_tcp("192.168.22.11", 502);
		ctx2 = modbus_new_tcp("192.168.22.12", 502);
		if (modbus_connect(ctx1) != -1)
		{
			this->ADAM1->Value = 1;
		}
		else
		{
			const char* charstr = modbus_strerror(errno);
			String^ clistr = gcnew String(charstr);
			this->ERRORTEXT->Text += "Error!!" + "connect lost" + clistr + "\r\n";
		}

		if (modbus_connect(ctx2) != -1)
		{
			this->ADAM2->Value = 1;
		}
		else
		{
			const char* charstr = modbus_strerror(errno);
			String^ clistr = gcnew String(charstr);
			this->ERRORTEXT->Text += "Error!!" + "connect lost" + clistr + "\r\n";
		}
		rc = modbus_read_input_bits(ctx1, 0, 2, tab_DI);
		if (rc == -1)
		{
			const char* charstr = modbus_strerror(errno);
			String^ clistr = gcnew String(charstr);
			this->ERRORTEXT->Text += "Error!!" + "read input bits" + clistr + "\r\n";
		}
		ERRORTEXT->Text = "";

	}
	private: System::Void IONBar_Click(System::Object^ sender, System::EventArgs^ e)//Äèñêðåòíûé D0
	{
		if (IONBar->Value == 0)
		{
			IONBar->Value = 1;
			tab_DO[1] = 0;
		}
		else
		{
			IONBar->Value = 0;
			tab_DO[1] = 1;
		}
		rc = modbus_write_bit(ctx1, 16, tab_DO[0]);
	}
	private: System::Void TBar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (TBar->Value == 0)
		{
			TBar->Value = 1;
			tab_DO[1] = 0;
		}
		else
		{
			TBar->Value = 0;
			tab_DO[1] = 1;
		}
		rc = modbus_write_bit(ctx2, 16, tab_DO[0]);
	}
	private: System::Void SetV_1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		tab_V[0] = 409.500409 * float(AO0_1->Value);
		tab_V[1] = 409.500409 * float(AO1_1->Value);

		rc = modbus_write_registers(ctx1, 10, 2, tab_V);
		if (rc == -1)
		{
			const char* charstr = modbus_strerror(errno);
			String^ clistr = gcnew String(charstr);
			this->ERRORTEXT->Text += "Error!!" + "write registers." + clistr + "\r\n";
		}
	}
	private: System::Void SetV_2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		tab_V[0] = 409.500409 * float(AO0_2->Value);
		tab_V[1] = 409.500409 * float(AO1_2->Value);
		rc = modbus_write_registers(ctx2, 10, 2, tab_V);
		if (rc == -1)
		{
			const char* charstr = modbus_strerror(errno);
			String^ clistr = gcnew String(charstr);
			this->ERRORTEXT->Text += "Error!!" + "write registers." + clistr + "\r\n";
		}
	}

};
}	

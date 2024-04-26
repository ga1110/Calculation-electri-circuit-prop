#pragma once
#include "Elec.h"
namespace Fact {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
		ElementManager^ Scheme1_manager = gcnew ElementManager();
		ElementManager^ Scheme2_manager = gcnew ElementManager();
		ElementManager^ Scheme3_manager = gcnew ElementManager();
	private: System::Windows::Forms::Button^ Scheme3_button;
	private: System::Windows::Forms::Button^ Scheme2_button;
	public:
		MyForm(void)
		{
			InitializeComponent();
			InitialScheme1();
			InitialScheme2();
			InitialScheme3();

			this->WindowState = FormWindowState::Maximized;
			//TODO: добавьте код конструктора
			//
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


	protected:

	protected:







	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::CheckBox^ checkBox9;
	private: System::Windows::Forms::CheckBox^ checkBox10;
	private: System::Windows::Forms::CheckBox^ checkBox11;
	private: System::Windows::Forms::CheckBox^ checkBox12;
	private: System::Windows::Forms::CheckBox^ checkBox13;
	private: System::Windows::Forms::CheckBox^ checkBox14;
	private: System::Windows::Forms::CheckBox^ checkBox15;
	private: System::Windows::Forms::CheckBox^ checkBox16;
	private: System::Windows::Forms::CheckBox^ checkBox17;
	private: System::Windows::Forms::CheckBox^ checkBox18;
	private: System::Windows::Forms::CheckBox^ checkBox19;
	private: System::Windows::Forms::CheckBox^ checkBox20;

	private: System::Windows::Forms::CheckBox^ checkBox21;
	private: System::Windows::Forms::CheckBox^ checkBox22;
	private: System::Windows::Forms::CheckBox^ checkBox23;
	private: System::Windows::Forms::CheckBox^ checkBox24;
	private: System::Windows::Forms::CheckBox^ checkBox25;
	private: System::Windows::Forms::CheckBox^ checkBox26;
	private: System::Windows::Forms::CheckBox^ checkBox27;
	private: System::Windows::Forms::CheckBox^ checkBox28;
	private: System::Windows::Forms::CheckBox^ checkBox29;
	private: System::Windows::Forms::CheckBox^ checkBox30;
	private: System::Windows::Forms::CheckBox^ checkBox31;
	private: System::Windows::Forms::CheckBox^ checkBox32;
	private: System::Windows::Forms::CheckBox^ checkBox33;
	private: System::Windows::Forms::CheckBox^ checkBox34;
	private: System::Windows::Forms::CheckBox^ checkBox35;
	private: System::Windows::Forms::CheckBox^ checkBox36;

	private: System::Windows::Forms::Button^ Info_button;
	private: System::Windows::Forms::Button^ Key_Switch;
	private: System::Windows::Forms::Button^ Change_info_button;
	private: System::Windows::Forms::Label^ R_label;
	private: System::Windows::Forms::Label^ I_label;
	private: System::Windows::Forms::TextBox^ InputR_textbox;
	private: System::Windows::Forms::TextBox^ InputI_textbox;
	private: System::Windows::Forms::TextBox^ Schemetextbox;
	private: System::Windows::Forms::Button^ Scheme1_button;








	private: System::Windows::Forms::Panel^ scheme1;
	private: System::Windows::Forms::Panel^ scheme2;
	private: System::Windows::Forms::Panel^ scheme3;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox20 = (gcnew System::Windows::Forms::CheckBox());

			this->checkBox21 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox22 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox23 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox24 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox25 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox26 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox27 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox28 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox29 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox30 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox31 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox32 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox33 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox34 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox35 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox36 = (gcnew System::Windows::Forms::CheckBox());

			this->scheme1 = (gcnew System::Windows::Forms::Panel());
			this->scheme2 = (gcnew System::Windows::Forms::Panel());
			this->scheme3 = (gcnew System::Windows::Forms::Panel());
			this->Info_button = (gcnew System::Windows::Forms::Button());
			this->Key_Switch = (gcnew System::Windows::Forms::Button());
			this->Change_info_button = (gcnew System::Windows::Forms::Button());
			this->R_label = (gcnew System::Windows::Forms::Label());
			this->I_label = (gcnew System::Windows::Forms::Label());
			this->InputR_textbox = (gcnew System::Windows::Forms::TextBox());
			this->InputI_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Schemetextbox = (gcnew System::Windows::Forms::TextBox());
			this->Scheme1_button = (gcnew System::Windows::Forms::Button());
			this->Scheme2_button = (gcnew System::Windows::Forms::Button());
			this->Scheme3_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->Location = System::Drawing::Point(0, 0);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(104, 24);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->Location = System::Drawing::Point(0, 0);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(104, 24);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->Location = System::Drawing::Point(0, 0);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(104, 24);
			this->checkBox3->TabIndex = 0;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->Location = System::Drawing::Point(0, 0);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(104, 24);
			this->checkBox4->TabIndex = 0;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->Location = System::Drawing::Point(0, 0);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(104, 24);
			this->checkBox5->TabIndex = 0;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->Location = System::Drawing::Point(0, 0);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(104, 24);
			this->checkBox6->TabIndex = 0;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->Location = System::Drawing::Point(0, 0);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(104, 24);
			this->checkBox7->TabIndex = 0;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox8
			// 
			this->checkBox8->Location = System::Drawing::Point(0, 0);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(104, 24);
			this->checkBox8->TabIndex = 0;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox9
			// 
			this->checkBox9->Location = System::Drawing::Point(0, 0);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(104, 24);
			this->checkBox9->TabIndex = 0;
			this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox10
			// 
			this->checkBox10->Location = System::Drawing::Point(0, 0);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(104, 24);
			this->checkBox10->TabIndex = 0;
			this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox11
			// 
			this->checkBox11->Location = System::Drawing::Point(0, 0);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(104, 24);
			this->checkBox11->TabIndex = 0;
			this->checkBox11->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox12
			// 
			this->checkBox12->Location = System::Drawing::Point(0, 0);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(104, 24);
			this->checkBox12->TabIndex = 0;
			this->checkBox12->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox13
			// 
			this->checkBox13->Location = System::Drawing::Point(0, 0);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(104, 24);
			this->checkBox13->TabIndex = 0;
			this->checkBox13->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox14
			// 
			this->checkBox14->Location = System::Drawing::Point(0, 0);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(104, 24);
			this->checkBox14->TabIndex = 0;
			this->checkBox14->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox15
			// 
			this->checkBox15->Location = System::Drawing::Point(0, 0);
			this->checkBox15->Name = L"checkBox15";
			this->checkBox15->Size = System::Drawing::Size(104, 24);
			this->checkBox15->TabIndex = 0;
			this->checkBox15->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox16
			// 
			this->checkBox16->Location = System::Drawing::Point(0, 0);
			this->checkBox16->Name = L"checkBox16";
			this->checkBox16->Size = System::Drawing::Size(104, 24);
			this->checkBox16->TabIndex = 0;
			this->checkBox16->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox17
			// 
			this->checkBox17->Location = System::Drawing::Point(0, 0);
			this->checkBox17->Name = L"checkBox17";
			this->checkBox17->Size = System::Drawing::Size(104, 24);
			this->checkBox17->TabIndex = 0;
			this->checkBox17->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox18
			// 
			this->checkBox18->Location = System::Drawing::Point(0, 0);
			this->checkBox18->Name = L"checkBox18";
			this->checkBox18->Size = System::Drawing::Size(104, 24);
			this->checkBox18->TabIndex = 0;
			this->checkBox18->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox19
			// 
			this->checkBox19->Location = System::Drawing::Point(0, 0);
			this->checkBox19->Name = L"checkBox19";
			this->checkBox19->Size = System::Drawing::Size(104, 24);
			this->checkBox19->TabIndex = 0;
			this->checkBox19->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox20
			// 
			this->checkBox20->Location = System::Drawing::Point(0, 0);
			this->checkBox20->Name = L"checkBox20";
			this->checkBox20->Size = System::Drawing::Size(104, 24);
			this->checkBox20->TabIndex = 0;
			this->checkBox20->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox21
			// 
			this->checkBox21->Location = System::Drawing::Point(0, 0);
			this->checkBox21->Name = L"checkBox21";
			this->checkBox21->Size = System::Drawing::Size(104, 24);
			this->checkBox21->TabIndex = 0;
			this->checkBox21->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox22
			// 
			this->checkBox22->Location = System::Drawing::Point(0, 0);
			this->checkBox22->Name = L"checkBox22";
			this->checkBox22->Size = System::Drawing::Size(104, 24);
			this->checkBox22->TabIndex = 0;
			this->checkBox22->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox23
			// 
			this->checkBox23->Location = System::Drawing::Point(0, 0);
			this->checkBox23->Name = L"checkBox23";
			this->checkBox23->Size = System::Drawing::Size(104, 24);
			this->checkBox23->TabIndex = 0;
			this->checkBox23->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox24
			// 
			this->checkBox24->Location = System::Drawing::Point(0, 0);
			this->checkBox24->Name = L"checkBox24";
			this->checkBox24->Size = System::Drawing::Size(104, 24);
			this->checkBox24->TabIndex = 0;
			this->checkBox24->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox25
			// 
			this->checkBox25->Location = System::Drawing::Point(0, 0);
			this->checkBox25->Name = L"checkBox25";
			this->checkBox25->Size = System::Drawing::Size(104, 24);
			this->checkBox25->TabIndex = 0;
			this->checkBox25->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox26
			// 
			this->checkBox26->Location = System::Drawing::Point(0, 0);
			this->checkBox26->Name = L"checkBox26";
			this->checkBox26->Size = System::Drawing::Size(104, 24);
			this->checkBox26->TabIndex = 0;
			this->checkBox26->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox27
			// 
			this->checkBox27->Location = System::Drawing::Point(0, 0);
			this->checkBox27->Name = L"checkBox27";
			this->checkBox27->Size = System::Drawing::Size(104, 24);
			this->checkBox27->TabIndex = 0;
			this->checkBox27->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox28
			// 
			this->checkBox28->Location = System::Drawing::Point(0, 0);
			this->checkBox28->Name = L"checkBox28";
			this->checkBox28->Size = System::Drawing::Size(104, 24);
			this->checkBox28->TabIndex = 0;
			this->checkBox28->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox29
			// 
			this->checkBox29->Location = System::Drawing::Point(0, 0);
			this->checkBox29->Name = L"checkBox29";
			this->checkBox29->Size = System::Drawing::Size(104, 24);
			this->checkBox29->TabIndex = 0;
			this->checkBox29->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox30
			// 
			this->checkBox30->Location = System::Drawing::Point(0, 0);
			this->checkBox30->Name = L"checkBox30";
			this->checkBox30->Size = System::Drawing::Size(104, 24);
			this->checkBox30->TabIndex = 0;
			this->checkBox30->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox31
			// 
			this->checkBox31->Location = System::Drawing::Point(0, 0);
			this->checkBox31->Name = L"checkBox31";
			this->checkBox31->Size = System::Drawing::Size(104, 24);
			this->checkBox31->TabIndex = 0;
			this->checkBox31->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox32
			// 
			this->checkBox32->Location = System::Drawing::Point(0, 0);
			this->checkBox32->Name = L"checkBox32";
			this->checkBox32->Size = System::Drawing::Size(104, 24);
			this->checkBox32->TabIndex = 0;
			this->checkBox32->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox33
			// 
			this->checkBox33->Location = System::Drawing::Point(0, 0);
			this->checkBox33->Name = L"checkBox33";
			this->checkBox33->Size = System::Drawing::Size(104, 24);
			this->checkBox33->TabIndex = 0;
			this->checkBox33->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox34
			// 
			this->checkBox34->Location = System::Drawing::Point(0, 0);
			this->checkBox34->Name = L"checkBox34";
			this->checkBox34->Size = System::Drawing::Size(104, 24);
			this->checkBox34->TabIndex = 0;
			this->checkBox34->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox35
			// 
			this->checkBox35->Location = System::Drawing::Point(0, 0);
			this->checkBox35->Name = L"checkBox35";
			this->checkBox35->Size = System::Drawing::Size(104, 24);
			this->checkBox35->TabIndex = 0;
			this->checkBox35->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// checkBox36
			// 
			this->checkBox36->Location = System::Drawing::Point(0, 0);
			this->checkBox36->Name = L"checkBox36";
			this->checkBox36->Size = System::Drawing::Size(104, 24);
			this->checkBox36->TabIndex = 0;
			this->checkBox36->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// scheme1
			// 
			this->scheme1->AutoScroll = true;
			this->scheme1->AutoScrollMinSize = System::Drawing::Size(2200, 1400);
			this->scheme1->Location = System::Drawing::Point(0, 0);
			this->scheme1->Name = L"scheme1";
			this->scheme1->Size = System::Drawing::Size(1000, 1000);
			this->scheme1->TabIndex = 0;
			// 
			// scheme2
			// 
			this->scheme2->AutoScroll = true;
			this->scheme2->AutoScrollMinSize = System::Drawing::Size(2100, 940);
			this->scheme2->Enabled = false;
			this->scheme2->Location = System::Drawing::Point(0, 0);
			this->scheme2->Name = L"scheme2";
			this->scheme2->Size = System::Drawing::Size(1000, 1000);
			this->scheme2->TabIndex = 0;
			this->scheme2->Visible = false;
			// 
			// scheme3
			// 
			this->scheme3->AutoScroll = true;
			this->scheme3->AutoScrollMinSize = System::Drawing::Size(2100, 1513);
			this->scheme3->Enabled = false;
			this->scheme3->Location = System::Drawing::Point(0, 0);
			this->scheme3->Name = L"scheme3";
			this->scheme3->Size = System::Drawing::Size(1000, 1000);
			this->scheme3->TabIndex = 0;
			this->scheme3->Visible = false;
			// 
			// Info_button
			// 
			this->Info_button->Location = System::Drawing::Point(1082, 90);
			this->Info_button->Name = L"Info_button";
			this->Info_button->Size = System::Drawing::Size(106, 23);
			this->Info_button->TabIndex = 1;
			this->Info_button->Text = L"Характеристики";
			this->Info_button->UseVisualStyleBackColor = true;
			this->Info_button->Click += gcnew System::EventHandler(this, &MyForm::Info_button_Click);
			// 
			// Key_Switch
			// 
			this->Key_Switch->Location = System::Drawing::Point(1082, 119);
			this->Key_Switch->Name = L"Key_Switch";
			this->Key_Switch->Size = System::Drawing::Size(127, 23);
			this->Key_Switch->TabIndex = 2;
			this->Key_Switch->Text = L"Переключение ключа";
			this->Key_Switch->UseVisualStyleBackColor = true;
			this->Key_Switch->Click += gcnew System::EventHandler(this, &MyForm::Key_Switch_Click);
			// 
			// Change_info_button
			// 
			this->Change_info_button->Location = System::Drawing::Point(1082, 148);
			this->Change_info_button->Name = L"Change_info_button";
			this->Change_info_button->Size = System::Drawing::Size(160, 21);
			this->Change_info_button->TabIndex = 3;
			this->Change_info_button->Text = L"Поменять характеристики";
			this->Change_info_button->UseVisualStyleBackColor = true;
			this->Change_info_button->Click += gcnew System::EventHandler(this, &MyForm::Change_info_button_Click);
			// 
			// R_label
			// 
			this->R_label->AutoSize = true;
			this->R_label->Location = System::Drawing::Point(1082, 217);
			this->R_label->Name = L"R_label";
			this->R_label->Size = System::Drawing::Size(27, 13);
			this->R_label->TabIndex = 4;
			this->R_label->Text = L"R = ";
			// 
			// I_label
			// 
			this->I_label->AutoSize = true;
			this->I_label->Location = System::Drawing::Point(1083, 252);
			this->I_label->Name = L"I_label";
			this->I_label->Size = System::Drawing::Size(22, 13);
			this->I_label->TabIndex = 6;
			this->I_label->Text = L"I = ";
			this->I_label->Click += gcnew System::EventHandler(this, &MyForm::I_label_Click);
			// 
			// InputR_textbox
			// 
			this->InputR_textbox->Location = System::Drawing::Point(1110, 211);
			this->InputR_textbox->Name = L"InputR_textbox";
			this->InputR_textbox->Size = System::Drawing::Size(100, 20);
			this->InputR_textbox->TabIndex = 7;
			// 
			// InputI_textbox
			// 
			this->InputI_textbox->Location = System::Drawing::Point(1110, 244);
			this->InputI_textbox->Name = L"InputI_textbox";
			this->InputI_textbox->Size = System::Drawing::Size(100, 20);
			this->InputI_textbox->TabIndex = 8;
			// 
			// Schemetextbox
			// 
			this->Schemetextbox->Location = System::Drawing::Point(1269, 191);
			this->Schemetextbox->Multiline = true;
			this->Schemetextbox->Name = L"Schemetextbox";
			this->Schemetextbox->ReadOnly = true;
			this->Schemetextbox->Size = System::Drawing::Size(246, 74);
			this->Schemetextbox->TabIndex = 9;
			// 
			// Scheme1_button
			// 
			this->Scheme1_button->Location = System::Drawing::Point(1086, 420);
			this->Scheme1_button->Name = L"Scheme1_button";
			this->Scheme1_button->Size = System::Drawing::Size(96, 66);
			this->Scheme1_button->TabIndex = 10;
			this->Scheme1_button->Text = L"Схема 1";
			this->Scheme1_button->UseVisualStyleBackColor = true;
			this->Scheme1_button->Click += gcnew System::EventHandler(this, &MyForm::Scheme1_button_Click);
			// 
			// Scheme2_button
			// 
			this->Scheme2_button->Location = System::Drawing::Point(1187, 420);
			this->Scheme2_button->Name = L"Scheme2_button";
			this->Scheme2_button->Size = System::Drawing::Size(96, 66);
			this->Scheme2_button->TabIndex = 11;
			this->Scheme2_button->Text = L"Схема 2";
			this->Scheme2_button->UseVisualStyleBackColor = true;
			this->Scheme2_button->Click += gcnew System::EventHandler(this, &MyForm::Scheme2_button_Click);
			// 
			// Scheme3_button
			// 
			this->Scheme3_button->Location = System::Drawing::Point(1288, 420);
			this->Scheme3_button->Name = L"Scheme3_button";
			this->Scheme3_button->Size = System::Drawing::Size(96, 66);
			this->Scheme3_button->TabIndex = 12;
			this->Scheme3_button->Text = L"Схема 3";
			this->Scheme3_button->UseVisualStyleBackColor = true;
			this->Scheme3_button->Click += gcnew System::EventHandler(this, &MyForm::Scheme3_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1527, 900);
			this->Controls->Add(this->Scheme3_button);
			this->Controls->Add(this->Scheme2_button);
			this->Controls->Add(this->Scheme1_button);
			this->Controls->Add(this->Schemetextbox);
			this->Controls->Add(this->InputI_textbox);
			this->Controls->Add(this->InputR_textbox);
			this->Controls->Add(this->I_label);
			this->Controls->Add(this->R_label);
			this->Controls->Add(this->Change_info_button);
			this->Controls->Add(this->Key_Switch);
			this->Controls->Add(this->Info_button);
			this->Controls->Add(this->scheme1);
			this->Controls->Add(this->scheme2);
			this->Controls->Add(this->scheme3);
			this->Name = L"MyForm";
			this->Text = L"Электрическая цепь ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void Create_Check(CheckBox^ box, String^ name, double x, double y, Panel^ panel)
		{
			box->AutoSize = true;
			box->Location = System::Drawing::Point(x + 150, y + 300);
			box->Name = name;
			box->Size = System::Drawing::Size(1000, 1000);
			box->TabIndex = 1;
			box->Text = L"";
			box->UseVisualStyleBackColor = true;
			panel->Controls->Add(box);
		}
		void CheckBoxFor1()
		{
			Create_Check(checkBox1, "EDS1_box", 9, 585.5, scheme1);
			Create_Check(checkBox2, "Resistor1_box", 600, 233, scheme1);
			Create_Check(checkBox3, "Lamp1_box", 900, 234, scheme1);
			Create_Check(checkBox4, "Key1_box", 600, 932 - 350, scheme1);
			Create_Check(checkBox5, "Resistor2_box", 900, 932 - 350, scheme1);
			Create_Check(checkBox6, "Resistor3_box", 1500, 9, scheme1);
			Create_Check(checkBox7, "Resistor4_box", 1500, 469.5 - 350, scheme1);
			Create_Check(checkBox8, "ElectricPribor1_box", 1800, 9.5, scheme1);
			Create_Check(checkBox9, "Resistor5_box", 1800, 469.5 - 350, scheme1);
			Create_Check(checkBox10, "Resistor6_box", 1500, 710, scheme1);
			Create_Check(checkBox11, "Lamp2_box", 1800, 710, scheme1);
			Create_Check(checkBox12, "Resistor7_box", 1500, 1166 - 350, scheme1);
		}
		void CheckBoxFor2()
		{
			Create_Check(checkBox13, "EDS1_box", 9, 0, scheme2);
			Create_Check(checkBox14, "Key1_box", 300, 0 , scheme2);
			Create_Check(checkBox15, "EDS2_box", 9, 700-350, scheme2);
			Create_Check(checkBox16, "Key2_box", 300, 700-350, scheme2);
			Create_Check(checkBox17, "Resistor1_box", 900,  350, scheme2);
			Create_Check(checkBox18, "Lamp1_box", 1200, 350, scheme2);
			Create_Check(checkBox19, "Resistor2_box", 1500, 350, scheme2);
			Create_Check(checkBox20, "ElectricPribor1_box", 1800, 350, scheme2);

		}
		void CheckBoxFor3()
		{
			Create_Check(checkBox21, "EDS1_box", 9, 933, scheme3);
			Create_Check(checkBox22, "Key1_box", 600, 900, scheme3);
			Create_Check(checkBox23, "Lamp1_box", 900, 900, scheme3);
			Create_Check(checkBox24, "Resistor1_box", 1200, 900, scheme3);
			Create_Check(checkBox25, "Resistor2_box", 1500, 900, scheme3);
			Create_Check(checkBox26, "ElectricPribor1_box", 1800, 900, scheme3);
			Create_Check(checkBox27, "Key2_box", 900, 550, scheme3);
			Create_Check(checkBox28, "Lamp2_box", 1200, 550, scheme3);
			Create_Check(checkBox29, "Resistor3_box", 1500, 550, scheme3);
			Create_Check(checkBox30, "Resistor4_box", 1800, 550, scheme3);
			Create_Check(checkBox31, "Key3_box", 1200, 100, scheme3);
			Create_Check(checkBox32, "Lamp3_box", 1500, 100, scheme3);
			Create_Check(checkBox33, "Resistor5_box", 1800, 100, scheme3);
			Create_Check(checkBox34, "Resistor6_box", 1200, 0, scheme3);
			Create_Check(checkBox35, "Resistor7_box", 1500, 0, scheme3);
			Create_Check(checkBox36, "ElectricPribor2_box", 1800, 0, scheme3);
		}
		void InitialScheme1()
		{
			//Инициализация checkbox
			CheckBoxFor1();
			//Инициализация элементов
			EDS^ Eds1 = gcnew EDS(1, 5, 32, scheme1, 0, 585.5);
			Razdel^ Razdel1 = gcnew Razdel(scheme1, 300, 350.5);
			Resistor^ Resistor1 = gcnew Resistor(1, 8, scheme1, 600, 233);
			Lamp^ Lamp1 = gcnew Lamp(1, 2, scheme1, 900, 234, 1);
			Key^ Key1 = gcnew Key(1, scheme1, 600, 932, true);
			Resistor^ Resistor2 = gcnew Resistor(2, 12, scheme1, 900, 932);
			Razdelm^ Razdelm1 = gcnew Razdelm(scheme1, 1200, 825.25);
			Razdelm^ Razdelm2 = gcnew Razdelm(scheme1, 1200, 127.5);
			Resistor^ Resistor3 = gcnew Resistor(3, 9, scheme1, 1500, 9);
			Resistor^ Resistor4 = gcnew Resistor(4, 6, scheme1, 1500, 469.5);
			Electric_device^ El_pribor1 = gcnew Electric_device(1, 32, scheme1, 1800, 9.5, 2);
			Resistor^ Resistor5 = gcnew Resistor(5, 5, scheme1, 1800, 469.5);
			Resistor^ Resistor6 = gcnew Resistor(6, 5, scheme1, 1500, 710);
			Lamp^ Lamp2 = gcnew Lamp(2, 3, scheme1, 1800, 710, 2);
			Resistor^ Resistor7 = gcnew Resistor(7, 11, scheme1, 1500, 1166);
			Line^ Line1 = gcnew Line(scheme1, 1800, 1175);
			RazdelmR^ RazdelmR1 = gcnew RazdelmR(scheme1, 2100, 128);
			RazdelmR^ RazdelmR2 = gcnew RazdelmR(scheme1, 2100, 828);
			//Заносим в список
			Scheme1_manager->AddElement(Eds1);
			Scheme1_manager->AddElement(Resistor1);
			Scheme1_manager->AddElement(Lamp1);
			Scheme1_manager->AddElement(Key1);
			Scheme1_manager->AddElement(Resistor2);
			Scheme1_manager->AddElement(Resistor3);
			Scheme1_manager->AddElement(Resistor4);
			Scheme1_manager->AddElement(El_pribor1);
			Scheme1_manager->AddElement(Resistor5);
			Scheme1_manager->AddElement(Resistor6);
			Scheme1_manager->AddElement(Lamp2);
			Scheme1_manager->AddElement(Resistor7);
			scheme1_Calc_Total();
		}
		void InitialScheme2()
		{
			CheckBoxFor2();
			//Инициализация элементов
			EDS^ Eds1 = gcnew EDS(1, 5, 32, scheme2, 0, 0);   
			Key^ Key1 = gcnew Key(1, scheme2, 300, 0, true);
			EDS^ Eds2 = gcnew EDS(2, 5, 32, scheme2, 0, 700); //
			Key^ Key2 = gcnew Key(2, scheme2, 300, 700, true);
			RazdelR^ RazdelR1 = gcnew RazdelR(scheme2, 600, 116);
			Resistor^ Resistor1 = gcnew Resistor(1, 8, scheme2, 900, 350);
			Lamp^ Lamp1 = gcnew Lamp(1, 2, scheme2, 1200, 350, true);
			Resistor^ Resistor2 = gcnew Resistor(2, 8, scheme2, 1500, 350);
			Electric_device^ El_pribor1 = gcnew Electric_device(1, 32, scheme2, 1800, 350, true);

			Scheme2_manager->AddElement(Eds1);
			Scheme2_manager->AddElement(Key1);
			Scheme2_manager->AddElement(Eds2);
			Scheme2_manager->AddElement(Key2);
			Scheme2_manager->AddElement(Resistor1);
			Scheme2_manager->AddElement(Lamp1);
			Scheme2_manager->AddElement(Resistor2);
			Scheme2_manager->AddElement(El_pribor1);
		}
		void InitialScheme3()
		{
			CheckBoxFor3();
			//Инициализация элементов
			EDS^ Eds1 = gcnew EDS(1, 5, 72, scheme3, 0, 923);

			Razdel^ Razdel1 = gcnew Razdel(scheme3, 300, 687);
			Key^ Key1 = gcnew Key(1, scheme3, 600, 1269, true);
			Lamp^ Lamp1 = gcnew Lamp(1, 3, scheme3, 900, 1269, true);
			Resistor^ Resistor1 = gcnew Resistor(1, 6, scheme3, 1200, 1269);
			Resistor^ Resistor2 = gcnew Resistor(2, 8, scheme3, 1500, 1269);
			Electric_device^ El_pribor1 = gcnew Electric_device(1, 32, scheme3, 1800, 1269, true);

			Razdel^ Razdel2 = gcnew Razdel(scheme3, 600, 337);
			Key^ Key2 = gcnew Key(2, scheme3, 900, 918, true);
			Lamp^ Lamp2 = gcnew Lamp(2, 12, scheme3, 1200, 918, true);
			Resistor^ Resistor3 = gcnew Resistor(3, 10, scheme3, 1500, 918);
			Resistor^ Resistor4 = gcnew Resistor(4, 12, scheme3, 1800, 918);
			

			Razdelm^ Razdelm1 = gcnew Razdelm(scheme3, 900, 113);
			Key^ Key3 = gcnew Key(3, scheme3, 1200, 453, true);
			Lamp^ Lamp3 = gcnew Lamp(3, 7, scheme3, 1500, 453, true);
			Resistor^ Resistor5 = gcnew Resistor(5, 14, scheme3, 1800, 453);

			Resistor^ Resistor6 = gcnew Resistor(6, 16, scheme3, 1200, -5);
			Resistor^ Resistor7 = gcnew Resistor(7, 18, scheme3, 1500, -5);
			Electric_device^ El_pribor2 = gcnew Electric_device(2, 8, scheme3, 1800, -5, true);


			Scheme3_manager->AddElement(Eds1);
			Scheme3_manager->AddElement(Key1);
			Scheme3_manager->AddElement(Lamp1);
			Scheme3_manager->AddElement(Resistor1);
			Scheme3_manager->AddElement(Resistor2);
			Scheme3_manager->AddElement(El_pribor1);
			Scheme3_manager->AddElement(Key2);
			Scheme3_manager->AddElement(Lamp2);
			Scheme3_manager->AddElement(Resistor3);
			Scheme3_manager->AddElement(Resistor4);
			Scheme3_manager->AddElement(Key3);
			Scheme3_manager->AddElement(Lamp3);
			Scheme3_manager->AddElement(Resistor5);
			Scheme3_manager->AddElement(Resistor6);
			Scheme3_manager->AddElement(Resistor7);
			Scheme3_manager->AddElement(El_pribor2);
		}
		void scheme1_Calc_Total()
		{
			// Инициализация переменных
			double totalResistance, resistance45, resistance67, resistance47, resistance1011, resistance9, resistance911, resistance27, resistance811, internalResistance;
			double totalCurrent, current27, current45, current67, current811, current9, current1011;
			double totalVoltage;

			// Получение ссылок на компоненты схемы
			auto resistor1 = Scheme1_manager->Find("Resistor1");
			auto resistor2 = Scheme1_manager->Find("Resistor2");
			auto resistor3 = Scheme1_manager->Find("Resistor3");
			auto resistor4 = Scheme1_manager->Find("Resistor4");
			auto resistor5 = Scheme1_manager->Find("Resistor5");
			auto resistor6 = Scheme1_manager->Find("Resistor6");
			auto resistor7 = Scheme1_manager->Find("Resistor7");
			auto electricDevice1 = Scheme1_manager->Find("ElectricDevice1");
			auto lamp1 = Scheme1_manager->Find("Lamp1");
			auto lamp2 = Scheme1_manager->Find("Lamp2");
			auto eds1 = Scheme1_manager->Find("EDS1");
			auto key1 = Scheme1_manager->Find("Key1");

			// Расчет сопротивлений
			resistance45 = resistor3->Get_Res() + electricDevice1->Get_Res();
			resistance67 = resistor4->Get_Res() + resistor5->Get_Res();
			resistance47 = ParallelResistance(resistance45, resistance67);

			if (key1->Get_Work())
			{
				resistance1011 = resistor6->Get_Res() + lamp2->Get_Res();
				resistance9 = resistor7->Get_Res();
				resistance911 = ParallelResistance(resistance9, resistance1011);
				resistance27 = resistor1->Get_Res() + lamp1->Get_Res() + resistance47;
				resistance811 = resistor2->Get_Res() + resistance911;
				totalResistance = ParallelResistance(resistance27, resistance811) + eds1->Get_Res();
			}
			else
			{
				totalResistance = resistor1->Get_Res() + lamp1->Get_Res() + resistance47;
			}

			// Расчет тока и напряжения
			totalCurrent = eds1->Get_Cur();
			internalResistance = eds1->Get_Res();
			eds1->Set_Vol(totalCurrent * totalResistance);
			totalVoltage = totalCurrent * totalResistance;

			// Вывод результатов
			Schemetextbox->AppendText("Общее сопротивление: " + Math::Round(totalResistance, 2) + " Ом\r\n");
			Schemetextbox->AppendText("Общая сила тока: " + Math::Round(totalCurrent, 2) + " A\r\n");
			Schemetextbox->AppendText("Общее напряжение: " + Math::Round(totalVoltage, 2) + " В\r\n");

			// Расчет тока через каждый элемент
			if (key1->Get_Work())
			{
				current27 = Math::Round((totalCurrent * (totalResistance - internalResistance)) / (resistance27), 2);
				resistor1->Set_Cur(current27);
				lamp1->Set_Cur(current27);
				current45 = Math::Round((current27 * resistance47) / resistance45, 2);
				resistor3->Set_Cur(current45);
				electricDevice1->Set_Cur(current45);
				current67 = Math::Round((current27 * resistance47) / resistance67, 2);
				resistor4->Set_Cur(current67);
				resistor5->Set_Cur(current67);

				current811 = Math::Round((totalCurrent * (totalResistance - internalResistance)) / resistance811, 2);
				resistor2->Set_Cur(current811);
				current9 = Math::Round((current811 * resistance911) / resistance9, 2);
				resistor7->Set_Cur(current9);
				current1011 = Math::Round((current811 * resistance911) / resistance1011, 2);
				resistor6->Set_Cur(current1011);
				lamp2->Set_Cur(current1011);
			}
			else
			{
				current27 = totalCurrent;
				resistor1->Set_Cur(current27);
				lamp1->Set_Cur(current27);
				current45 = Math::Round((current27 * resistance47) / resistance45, 2);
				resistor3->Set_Cur(current45);
				electricDevice1->Set_Cur(current45);
				current67 = Math::Round((current27 * resistance47) / resistance67, 2);
				resistor4->Set_Cur(current67);
				resistor5->Set_Cur(current67);

				current811 = 0;
				resistor2->Set_Cur(current811);
				current9 = 0;
				resistor7->Set_Cur(current9);
				current1011 = 0;
				resistor6->Set_Cur(current1011);
				lamp2->Set_Cur(current1011);
			}
		}

		void scheme2_Calc_Total()
		{
			// Инициализация переменных
			double totalResistance, resistance1, resistance2, resistance3, resistance4, resistance5, resistance6, resistance12, resistance36;
			double totalCurrent;
			double totalVoltage;

			// Получение ссылок на компоненты схемы
			auto eds1 = Scheme2_manager->Find("EDS1");
			auto eds2 = Scheme2_manager->Find("EDS2");
			auto resistor1 = Scheme2_manager->Find("Resistor1");
			auto resistor2 = Scheme2_manager->Find("Resistor2");
			auto lamp1 = Scheme2_manager->Find("Lamp1");
			auto electricDevice1 = Scheme2_manager->Find("ElectricDevice1");
			auto key1 = Scheme2_manager->Find("Key1");
			auto key2 = Scheme2_manager->Find("Key2");

			// Расчет сопротивлений
			resistance1 = eds1->Get_Res() * key1->Get_Work();
			resistance2 = eds2->Get_Res() * key2->Get_Work();
			resistance3 = resistor1->Get_Res();
			resistance4 = lamp1->Get_Res();
			resistance5 = resistor2->Get_Res();
			resistance6 = electricDevice1->Get_Res();

			if ((resistance1 + resistance2) == 0)
			{
				resistance12 = 0;
			}
			else
			{
				resistance12 = ParallelResistance(resistance1, resistance2);
			}

			resistance36 = resistance3 + resistance4 + resistance5 + resistance6;
			totalResistance = resistance12 + resistance36;

			// Расчет тока и напряжения
			totalCurrent = (eds1->Get_Cur() * key1->Get_Work()) + (eds2->Get_Cur() * key2->Get_Work());
			eds1->Set_Vol(totalCurrent * totalResistance);
			eds2->Set_Vol(totalCurrent * totalResistance);
			totalVoltage = totalCurrent * totalResistance;

			// Вывод результатов
			Schemetextbox->AppendText("Общее сопротивление: " + Math::Round(totalResistance, 2) + " Ом\r\n");
			Schemetextbox->AppendText("Общая сила тока: " + Math::Round(totalCurrent, 2) + " A\r\n");
			Schemetextbox->AppendText("Общее напряжение: " + Math::Round(totalVoltage, 2) + " В\r\n");

			// Установка тока через каждый элемент
			resistor1->Set_Cur(totalCurrent);
			resistor2->Set_Cur(totalCurrent);
			lamp1->Set_Cur(totalCurrent);
			electricDevice1->Set_Cur(totalCurrent);
		}

		void scheme3_Calc_Total()
		{
			// Инициализация переменных
			double totalResistance, resistance1, resistance2, resistance3, resistance4, resistance5, resistance6, resistance7, resistance8, resistance9, resistance10, resistance11, resistance12, resistance13, resistance25, resistance68, resistance910, resistance1113, resistance913, resistance613, resistance213;
			double totalCurrent, current1, current2, current3, current25, current45, current68, current910, current1113, current1011;
			double totalVoltage;

			// Получение ссылок на компоненты схемы
			auto eds1 = Scheme3_manager->Find("EDS1");
			auto lamp1 = Scheme3_manager->Find("Lamp1");
			auto resistor1 = Scheme3_manager->Find("Resistor1");
			auto resistor2 = Scheme3_manager->Find("Resistor2");
			auto electricDevice1 = Scheme3_manager->Find("ElectricDevice1");
			auto lamp2 = Scheme3_manager->Find("Lamp2");
			auto resistor3 = Scheme3_manager->Find("Resistor3");
			auto resistor4 = Scheme3_manager->Find("Resistor4");
			auto lamp3 = Scheme3_manager->Find("Lamp3");
			auto resistor5 = Scheme3_manager->Find("Resistor5");
			auto resistor6 = Scheme3_manager->Find("Resistor6");
			auto resistor7 = Scheme3_manager->Find("Resistor7");
			auto electricDevice2 = Scheme3_manager->Find("ElectricDevice2");
			auto key1 = Scheme3_manager->Find("Key1");
			auto key2 = Scheme3_manager->Find("Key2");
			auto key3 = Scheme3_manager->Find("Key3");

			// Расчет сопротивлений
			resistance1 = eds1->Get_Res();
			resistance2 = lamp1->Get_Res();
			resistance3 = resistor1->Get_Res();
			resistance4 = resistor2->Get_Res();
			resistance5 = electricDevice1->Get_Res();
			resistance25 = resistance2 + resistance3 + resistance4 + resistance5;
			resistance6 = lamp2->Get_Res();
			resistance7 = resistor3->Get_Res();
			resistance8 = resistor4->Get_Res();
			resistance68 = resistance6 + resistance7 + resistance8;
			resistance9 = lamp3->Get_Res();
			resistance10 = resistor5->Get_Res();
			resistance910 = resistance9 + resistance10;
			resistance11 = resistor6->Get_Res();
			resistance12 = resistor7->Get_Res();
			resistance13 = electricDevice2->Get_Res();
			resistance1113 = resistance11 + resistance12 + resistance13;
			resistance913 = ParallelResistance(resistance910, resistance1113) * key3->Get_Work() + resistance1113 * (1 - key3->Get_Work());
			resistance613 = ParallelResistance(resistance913, resistance68) * key2->Get_Work() + resistance913 * (1 - key2->Get_Work());
			resistance213 = ParallelResistance(resistance613, resistance25) * key1->Get_Work() + resistance613 * (1 - key1->Get_Work());
			totalResistance = resistance213 + resistance1;

			// Расчет тока и напряжения
			totalCurrent = eds1->Get_Cur();
			eds1->Set_Vol(totalCurrent * totalResistance);
			totalVoltage = totalCurrent * totalResistance;

			// Вывод результатов
			Schemetextbox->AppendText("Общее сопротивление: " + Math::Round(totalResistance, 2) + " Ом\r\n");
			Schemetextbox->AppendText("Общая сила тока: " + Math::Round(totalCurrent, 2) + " A\r\n");
			Schemetextbox->AppendText("Общее напряжение: " + Math::Round(totalVoltage, 2) + " В\r\n");

			// Расчет тока через каждый элемент
			current25 = Math::Round((totalCurrent * resistance213) / (resistance25), 2) * key1->Get_Work();
			resistor1->Set_Cur(current25);
			lamp1->Set_Cur(current25);
			resistor2->Set_Cur(current25);
			electricDevice1->Set_Cur(current25);
			current1 = totalCurrent - current25;
			current68 = Math::Round((current1 * resistance613) / resistance68, 2) * key2->Get_Work();
			lamp2->Set_Cur(current68);
			resistor3->Set_Cur(current68);
			resistor4->Set_Cur(current68);
			current2 = current1 - current68;
			current910 = Math::Round((current2 * resistance913) / resistance910, 2) * key3->Get_Work();
			lamp3->Set_Cur(current910);
			resistor5->Set_Cur(current910);
			current3 = current2 - current910;
			current1113 = current3;
			resistor6->Set_Cur(current1113);
			resistor7->Set_Cur(current1113);
			electricDevice2->Set_Cur(current1113);
		}

		// Функция для расчета параллельного сопротивления
		double ParallelResistance(double r1, double r2)
		{
			return (r1 * r2) / (r1 + r2);
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}



	private: System::Void Info_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ checkBoxInfo = "";
		Panel^ panel = Current_panel();
		CheckBox^ checkedCheckBox = nullptr;
		Panel^ checkBoxPanel = nullptr;
		ElementManager^ Scheme_manager = Current_manager();
		// Перебор всех элементов в Panel scheme1
		for each (Control ^ control in panel->Controls)
		{
			if (control->GetType() == CheckBox::typeid)
			{
				CheckBox^ checkBox = dynamic_cast<CheckBox^>(control);

				if (checkBox->Checked)
				{
					checkedCheckBox = checkBox; // Сохраняем ссылку на первый включенный CheckBox
					checkBoxPanel = panel;
					break; // Завершаем цикл, когда найден включенный CheckBox
				}
			}
			if (checkedCheckBox != nullptr)
			{
				break;
			}
		}
		if (checkedCheckBox == nullptr) {
			MessageBox::Show("Не выбран элемент");
			return;
		}
		if (panel == scheme1)
		{
			scheme1_Calc_Total();
		}
		if (panel == scheme2)
		{
			scheme2_Calc_Total();
		}
		if (panel == scheme3)
		{
			scheme3_Calc_Total();
		}
		MessageBox::Show((Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Get_Info()));
	}

	private: System::Void checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{ //There Can Be Only One!!!
		CheckBox^ currentCheckBox = dynamic_cast<CheckBox^>(sender);
		Panel^ panel = Current_panel();
		ElementManager^ Scheme_manager = Current_manager();
		if (currentCheckBox->Checked)
		{
			for each (Control ^ control in panel->Controls)
			{
				if (control != currentCheckBox && control->GetType() == CheckBox::typeid)
				{
					CheckBox^ otherCheckBox = dynamic_cast<CheckBox^>(control);
					otherCheckBox->Checked = false;
				}
			}

		}
		//InputR_textbox->Text
		//InputI_textbox->Text
		Scheme_manager->Find(currentCheckBox->Name->Replace("_box", ""))->Get_Res();
		String^ Name = currentCheckBox->Name->Replace("_box", "");
		if (!Name->Contains("EDS") && !Name->Contains("Key"))
		{
			InputI_textbox->Visible = false;
			InputI_textbox->Enabled = false;
			I_label->Visible = false;
			InputI_textbox->Text = "";

			InputR_textbox->Visible = true;
			InputR_textbox->Enabled = true;
			R_label->Visible = true;
			InputR_textbox->Text = (Scheme_manager->Find(currentCheckBox->Name->Replace("_box", ""))->Get_Res()).ToString();
		}
		else if (Name->Contains("EDS"))
		{
			InputI_textbox->Visible = true;
			InputI_textbox->Enabled = true;
			I_label->Visible = true;

			InputR_textbox->Visible = true;
			InputR_textbox->Enabled = true;
			R_label->Visible = true;

			InputI_textbox->Text = (Scheme_manager->Find(currentCheckBox->Name->Replace("_box", ""))->Get_Cur()).ToString();;
			InputR_textbox->Text = (Scheme_manager->Find(currentCheckBox->Name->Replace("_box", ""))->Get_Res()).ToString();
		}
		else
		{
			InputI_textbox->Visible = false;
			InputI_textbox->Enabled = false;
			I_label->Visible = false;
			InputI_textbox->Text = "";

			InputR_textbox->Visible = false;
			InputR_textbox->Enabled = false;
			R_label->Visible = false;
			InputR_textbox->Text = "";
		}
	}
	private: System::Void Key_Switch_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ checkBoxInfo = "";
		Panel^ panel = Current_panel();
		CheckBox^ checkedCheckBox = nullptr;
		Panel^ checkBoxPanel = nullptr;
		ElementManager^ Scheme_manager = Current_manager();
		// Перебор всех элементов в Panel scheme1
		for each (Control ^ control in panel->Controls)
		{
			if (control->GetType() == CheckBox::typeid)
			{
				CheckBox^ checkBox = dynamic_cast<CheckBox^>(control);

				if (checkBox->Checked)
				{
					checkedCheckBox = checkBox; // Сохраняем ссылку на первый включенный CheckBox
					checkBoxPanel = panel;
					break; // Завершаем цикл, когда найден включенный CheckBox
				}
			}
			if (checkedCheckBox != nullptr)
			{
				break;
			}
		}
		if (checkedCheckBox == nullptr) {
			MessageBox::Show("Не выбран элемент");
			return;
		}
		if (!checkedCheckBox->Name->Contains("Key"))
		{
			MessageBox::Show("Выбран не ключ");
			return;
		}
		bool w = Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Get_Work();
		Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Set_Work(!w);
		if (panel == scheme1)
		{
			scheme1_Calc_Total();
		}
		if (panel == scheme2)
		{
			scheme2_Calc_Total();
		}
		if (panel == scheme3)
		{
			scheme3_Calc_Total();
		}
	}
	private: System::Void I_label_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void Change_info_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		String^ checkBoxInfo = "";
		Panel^ panel = Current_panel();
		CheckBox^ checkedCheckBox = nullptr;
		Panel^ checkBoxPanel = nullptr;
		ElementManager^ Scheme_manager = Current_manager();
		for each (Control ^ control in panel->Controls)
		{
			if (control->GetType() == CheckBox::typeid)
			{
				CheckBox^ checkBox = dynamic_cast<CheckBox^>(control);

				if (checkBox->Checked)
				{
					checkedCheckBox = checkBox; // Сохраняем ссылку на первый включенный CheckBox
					checkBoxPanel = panel;
					break; // Завершаем цикл, когда найден включенный CheckBox
				}
			}
			if (checkedCheckBox != nullptr)
			{
				break;
			}
		}
		if (checkedCheckBox == nullptr) {
			MessageBox::Show("Не выбран элемент");
			return;
		}
		double R = 0;
		String^ textR = "";
		if (InputR_textbox->Text == "")
		{
			textR = (Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Get_Res()).ToString();
		}
		else
		{
			textR = InputR_textbox->Text;
		}
		if (!double::TryParse(textR, R)) {
			MessageBox::Show("Введено не число");
			return;
		}
		double I = 0;
		String^ textI = "";
		if (InputI_textbox->Text == "")
		{
			textI = (Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Get_Cur()).ToString();
		}
		else
		{
			textI = InputI_textbox->Text;
		}
		if (!double::TryParse(textI, I)) {
			MessageBox::Show("Введено не число");
			return;
		}

		Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Set_Res(R);
		Scheme_manager->Find(checkedCheckBox->Name->Replace("_box", ""))->Set_Cur(I);
		if (panel == scheme1)
		{
			scheme1_Calc_Total();
		}
		if (panel == scheme2)
		{
			scheme2_Calc_Total();
		}
		if (panel == scheme3)
		{
			scheme3_Calc_Total();
		}
	}
	private: System::Void Scheme1_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		scheme1->Visible = true;
		scheme1->Enabled = true;

		scheme2->Visible = false;
		scheme2->Enabled = false;

		scheme3->Visible = false;
		scheme3->Enabled = false;

		scheme1_Calc_Total();
	}
	private: System::Void Scheme2_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		scheme1->Visible = false;
		scheme1->Enabled = false;

		scheme2->Visible = true;
		scheme2->Enabled = true;

		scheme3->Visible = false;
		scheme3->Enabled = false;

		scheme2_Calc_Total();

	}
	private: System::Void Scheme3_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		scheme1->Visible = false;
		scheme1->Enabled = false;

		scheme2->Visible = false;
		scheme2->Enabled = false;

		scheme3->Visible = true;
		scheme3->Enabled = true;

		scheme3_Calc_Total();
    }
	Panel^ Current_panel()
	{
		if (scheme1->Visible)
		{
			return scheme1;
		}
		else if (scheme2->Visible)
		{
			return scheme2;
		}
		else
		{
			return scheme3;
		}
	}
	ElementManager^ Current_manager()
	{
		if (scheme1->Visible)
		{
			return Scheme1_manager;
		}
		else if (scheme2->Visible)
		{
			return Scheme2_manager;
		}
		else
		{
			return Scheme3_manager;
		}
	}

};
}





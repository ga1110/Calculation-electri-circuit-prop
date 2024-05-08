#pragma once
#include "Elec.h"
using namespace System;
public ref class InputForm : public System::Windows::Forms::Form
{
public:
    System::Windows::Forms::TextBox^ res_textbox;
    System::Windows::Forms::TextBox^ cur_textbox;

    System::Windows::Forms::Label^ res_label;
    System::Windows::Forms::Label^ cur_label;
    System::Windows::Forms::Label^ name_label;

    System::Windows::Forms::Button^ okButton;
    InputForm()
    {
        //Текстовые поля для ввода параметров
        res_textbox = gcnew System::Windows::Forms::TextBox();
        cur_textbox = gcnew System::Windows::Forms::TextBox();
        res_textbox->Location = System::Drawing::Point(15, 65);
        cur_textbox->Location = System::Drawing::Point(15, 115);

        //Подписи к полям
        res_label = gcnew System::Windows::Forms::Label();
        cur_label = gcnew System::Windows::Forms::Label();
        name_label = gcnew System::Windows::Forms::Label();
        res_label->Location = System::Drawing::Point(15, 45);
        cur_label->Location = System::Drawing::Point(15, 95);
        name_label->Location = System::Drawing::Point(15, 0);
        res_label->Text = "Resistence: ";
        cur_label->Text = "Current: ";
        name_label->Text = "Parameters ";
        name_label->AutoSize = true;

        okButton = gcnew System::Windows::Forms::Button();
        okButton->Text = "OK";
        okButton->Location = System::Drawing::Point(15, 145);
        okButton->Click += gcnew System::EventHandler(this, &InputForm::okButton_Click);

        this->Controls->Add(res_textbox);
        this->Controls->Add(cur_textbox);
        this->Controls->Add(res_label);
        this->Controls->Add(cur_label);
        this->Controls->Add(name_label);
        this->Controls->Add(okButton);

        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
    }
protected:
    virtual System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::OK;

    }
};

public ref class InputFormEDS : InputForm
{
public:
    InputFormEDS(String^ name_element)
    {
        this->Size = System::Drawing::Size(150, 250); // Установка размера формы

        name_label->Text = name_element + " parameters";
    }

};

public ref class InputFormBaselement : InputForm
{
public:
    InputFormBaselement(String^ name_element)
    {
        this->Size = System::Drawing::Size(150, 250); // Установка размера формы

        this->Controls->Remove(cur_label);
        this->Controls->Remove(cur_textbox);
        name_label->Text = name_element + " parameters";
        okButton->Location = System::Drawing::Point(15, 95);
    }
};

public ref class InputFormKey : InputForm
{
public:
    System::Windows::Forms::CheckBox^ check_work;
    InputFormKey(String^ name_element)
    {
        this->Size = System::Drawing::Size(300, 250); // Установка размера формы

        check_work = gcnew System::Windows::Forms::CheckBox();

        this->Controls->Remove(cur_label);
        this->Controls->Remove(cur_textbox);

        this->Controls->Remove(res_textbox);

        res_label->Text = "Is locked? ";

        check_work->Location = System::Drawing::Point(15, 65);
        this->Controls->Add(check_work);

        name_label->Text = name_element  + " parameters";


        okButton->Location = System::Drawing::Point(15, 95);
    }
};

public ref class InputFormChoose : InputForm
{
public:
    System::Windows::Forms::RadioButton^ eds_check;
    System::Windows::Forms::RadioButton^ resistor_check;
    System::Windows::Forms::RadioButton^ edev_check;
    System::Windows::Forms::RadioButton^ lamp_check;
    System::Windows::Forms::RadioButton^ key_check;

    System::Windows::Forms::Label^ eds_label;
    System::Windows::Forms::Label^ resistor_label;
    System::Windows::Forms::Label^ edev_label;
    System::Windows::Forms::Label^ lamp_label;
    System::Windows::Forms::Label^ key_label;

    System::Windows::Forms::Panel^ radioButtonPanel;
    InputFormChoose()
    {
        this->Size = System::Drawing::Size(300, 250);  // Установка размера формы

        System::Windows::Forms::Panel^ radioButtonPanel = gcnew System::Windows::Forms::Panel();

        this->Controls->Remove(cur_label);
        this->Controls->Remove(cur_textbox);
        this->Controls->Remove(res_textbox);
        this->Controls->Remove(res_label);

        eds_check = gcnew System::Windows::Forms::RadioButton();
        resistor_check = gcnew System::Windows::Forms::RadioButton();
        edev_check = gcnew System::Windows::Forms::RadioButton();
        lamp_check = gcnew System::Windows::Forms::RadioButton();
        key_check = gcnew System::Windows::Forms::RadioButton();

        eds_label = gcnew System::Windows::Forms::Label();
        resistor_label = gcnew System::Windows::Forms::Label();
        edev_label = gcnew System::Windows::Forms::Label();
        lamp_label = gcnew System::Windows::Forms::Label();
        key_label = gcnew System::Windows::Forms::Label();

        name_label->Text = "Choose element";

        eds_label->Location = System::Drawing::Point(40, 30);
        eds_label->Text = "EDS";
        eds_label->AutoSize = true;
        this->Controls->Add(eds_label);
        eds_check->Location = System::Drawing::Point(20, 25);
        radioButtonPanel->Controls->Add(eds_check);

        resistor_label->Location = System::Drawing::Point(40, 50);
        resistor_label->Text = "Resistor";
        resistor_label->AutoSize = true;
        this->Controls->Add(resistor_label);
        resistor_check->Location = System::Drawing::Point(20, 45);
        resistor_check->Checked = true;
        radioButtonPanel->Controls->Add(resistor_check);

        edev_label->Location = System::Drawing::Point(40, 70);
        edev_label->Text = "Electrical device";
        edev_label->AutoSize = true;
        this->Controls->Add(edev_label);
        edev_check->Location = System::Drawing::Point(20, 65);
        radioButtonPanel->Controls->Add(edev_check);

        lamp_label->Location = System::Drawing::Point(40, 90);
        lamp_label->Text = "Lamp";
        lamp_label->AutoSize = true;
        this->Controls->Add(lamp_label);
        lamp_check->Location = System::Drawing::Point(20, 85);
        radioButtonPanel->Controls->Add(lamp_check);

        key_label->Location = System::Drawing::Point(40, 110);
        key_label->Text = "Key";
        key_label->AutoSize = true;
        this->Controls->Add(key_label);
        key_check->Location = System::Drawing::Point(20, 105);
        radioButtonPanel->Controls->Add(key_check);

        radioButtonPanel->AutoSize = true;
        this->Controls->Add(radioButtonPanel);
        okButton->Location = System::Drawing::Point(15, 155);
    }
};
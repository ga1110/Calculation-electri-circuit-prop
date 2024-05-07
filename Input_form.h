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
        res_label->Text = "Сопротивление: ";
        cur_label->Text = "Напряжение: ";
        name_label->Text = "Параметры ";
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
    System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::OK;

    }
};

public ref class InputFormEDS : InputForm
{
public:
    InputFormEDS(String^ name_element)
    {
        this->Size = System::Drawing::Size(300, 250); // Установка размера формы

        name_label->Text = "Параметры " + name_element;
    }
};

public ref class InputFormBaselement : InputForm
{
public:
    InputFormBaselement(String^ name_element)
    {
        this->Size = System::Drawing::Size(300, 250); // Установка размера формы

        this->Controls->Remove(cur_label);
        this->Controls->Remove(cur_textbox);
        name_label->Text = "Параметры " + name_element;
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

        res_label->Text = "Замкнут? ";

        check_work->Location = System::Drawing::Point(15, 65);
        this->Controls->Add(check_work);

        name_label->Text = "Параметры " + name_element;


        okButton->Location = System::Drawing::Point(15, 95);
    }
};


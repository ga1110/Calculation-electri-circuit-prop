#pragma once
#include "Elec.h"
using namespace System;
public ref class ChangeForm : public System::Windows::Forms::Form
{
public:
    System::Windows::Forms::TextBox^ res_textbox;
    System::Windows::Forms::TextBox^ cur_textbox;
    System::Windows::Forms::TextBox^ vol_textbox;
    System::Windows::Forms::CheckBox^ connect_checkbox;
    System::Windows::Forms::CheckBox^ iswork_checkbox;

    System::Windows::Forms::Label^ res1_label;
    System::Windows::Forms::Label^ res2_label;
    System::Windows::Forms::Label^ cur1_label;
    System::Windows::Forms::Label^ cur2_label;
    System::Windows::Forms::Label^ vol1_label;
    System::Windows::Forms::Label^ vol2_label;
    System::Windows::Forms::Label^ connect_label;
    System::Windows::Forms::Label^ iswork_label;

    System::Windows::Forms::Label^ name_label;

    System::Windows::Forms::Button^ okButton;

    static E_elem^ element;
    List<String^>^ info_list;
    ChangeForm(E_elem^% new_element)
    {
        element = new_element;
        info_list = element->get_info();

        //info_list->Add(this->get_name());
        //info_list->Add(this->get_res().ToString());
        //info_list->Add(this->get_cur().ToString());
        //info_list->Add(this->get_vol().ToString());
        //info_list->Add(((this->get_cur() != 0) ? "1" : "0"));

        //Текстовые поля для ввода параметров
        res_textbox = gcnew System::Windows::Forms::TextBox();
        cur_textbox = gcnew System::Windows::Forms::TextBox();
        vol_textbox = gcnew System::Windows::Forms::TextBox();
        connect_checkbox = gcnew System::Windows::Forms::CheckBox();
        iswork_checkbox = gcnew System::Windows::Forms::CheckBox();

        iswork_checkbox->Location = System::Drawing::Point(80, 25);
        connect_checkbox->Location = System::Drawing::Point(80, 65);
        vol_textbox->Location = System::Drawing::Point(80, 105);
        cur_textbox->Location = System::Drawing::Point(80, 145);
        res_textbox->Location = System::Drawing::Point(80, 185);

        res_textbox->Text = element->get_res().ToString();
        cur_textbox->Text = element->get_cur().ToString();
        vol_textbox->Text = element->get_vol().ToString();
        connect_checkbox->Checked = (element->get_cur() != 0) ? true : false;
        iswork_checkbox->Checked = element->get_work();

        //Подписи к полям
        name_label = gcnew System::Windows::Forms::Label();
        res1_label = gcnew System::Windows::Forms::Label();
        cur1_label = gcnew System::Windows::Forms::Label();
        vol1_label = gcnew System::Windows::Forms::Label();
        res2_label = gcnew System::Windows::Forms::Label();
        cur2_label = gcnew System::Windows::Forms::Label();
        vol2_label = gcnew System::Windows::Forms::Label();
        connect_label = gcnew System::Windows::Forms::Label();
        iswork_label = gcnew System::Windows::Forms::Label();

        name_label->Location = System::Drawing::Point(15, 0);
        iswork_label->Location = System::Drawing::Point(15, 30);
        connect_label->Location = System::Drawing::Point(15, 70);
        vol1_label->Location = System::Drawing::Point(15, 110);
        cur1_label->Location = System::Drawing::Point(15, 150);
        res1_label->Location = System::Drawing::Point(15, 190);
        vol2_label->Location = System::Drawing::Point(180, 110);
        cur2_label->Location = System::Drawing::Point(180, 150);
        res2_label->Location = System::Drawing::Point(180, 190);

        name_label->Text = element->get_name() + " parameters";
        name_label->AutoSize = true;
        res1_label->Text = "Resistence: ";
        cur1_label->Text = "Current: ";
        vol1_label->Text = "Voltage: ";

        res2_label->Text = "Ohms";
        cur2_label->Text = "Amps";
        vol2_label->Text = "Volts";

        connect_label->Text = "Connect:";
        iswork_label->Text = "Working:";

        okButton = gcnew System::Windows::Forms::Button();
        okButton->Text = "OK";
        okButton->Location = System::Drawing::Point(15, 235);
        okButton->Click += gcnew System::EventHandler(this, &ChangeForm::okButton_Click);

        this->Controls->Add(res_textbox);
        this->Controls->Add(cur_textbox);
        this->Controls->Add(vol_textbox);
        this->Controls->Add(connect_checkbox);
        this->Controls->Add(iswork_checkbox);

        this->Controls->Add(name_label);
        this->Controls->Add(res1_label);
        this->Controls->Add(cur1_label);
        this->Controls->Add(vol1_label);

        this->Controls->Add(res2_label);
        this->Controls->Add(cur2_label);
        this->Controls->Add(vol2_label);

        this->Controls->Add(connect_label);
        this->Controls->Add(iswork_label);
        this->Controls->Add(okButton);

        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
    }
    virtual void change_param(E_elem^% new_element)
    {
        double res, cur, vol;
        bool iswork, connect;
        //new_element->set_res(1);
    }
protected:
    virtual System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        change_param(element);
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        
    }
};

public ref class ChangeFormEDS : ChangeForm
{
public:
    ChangeFormEDS(E_elem^ new_element) : ChangeForm(new_element)
    {
        vol_textbox->Enabled = false;
        iswork_checkbox->Enabled = false;
        connect_checkbox->Enabled = false;
    }
    void change_param(E_elem^% new_element) override
    {
    }
};

//public ref class ChangeFormBaseElement : ChangeForm
//{
//public:
//    ChangeFormBaseElement(String^ name_element)
//    {
//        this->Size = System::Drawing::Size(150, 250); // Установка размера формы
//
//        this->Controls->Remove(cur_label);
//        this->Controls->Remove(cur_textbox);
//        name_label->Text = name_element + " parameters";
//        okButton->Location = System::Drawing::Point(15, 95);
//    }
//};
//
//public ref class ChangeFormKey : ChangeForm
//{
//public:
//    System::Windows::Forms::CheckBox^ check_work;
//    ChangeFormKey(String^ name_element)
//    {
//        this->Size = System::Drawing::Size(300, 250); // Установка размера формы
//
//        check_work = gcnew System::Windows::Forms::CheckBox();
//
//        this->Controls->Remove(cur_label);
//        this->Controls->Remove(cur_textbox);
//
//        this->Controls->Remove(res_textbox);
//
//        res_label->Text = "Is locked? ";
//
//        check_work->Location = System::Drawing::Point(15, 65);
//        this->Controls->Add(check_work);
//
//        name_label->Text = name_element + " parameters";
//
//
//        okButton->Location = System::Drawing::Point(15, 95);
//    }
//};

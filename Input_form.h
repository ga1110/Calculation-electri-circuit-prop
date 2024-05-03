public ref class InputForm : public System::Windows::Forms::Form
{
public:
    System::Windows::Forms::TextBox^ textBox1;
    System::Windows::Forms::TextBox^ textBox2;
    System::Windows::Forms::Label^ label1;
    System::Windows::Forms::Label^ label2;

    InputForm()
    {
        this->Size = System::Drawing::Size(200, 200); // Установка размера формы

        textBox1 = gcnew System::Windows::Forms::TextBox();
        textBox2 = gcnew System::Windows::Forms::TextBox();
        label1 = gcnew System::Windows::Forms::Label();
        label2 = gcnew System::Windows::Forms::Label();
        System::Windows::Forms::Button^ okButton = gcnew System::Windows::Forms::Button();

        textBox1->Location = System::Drawing::Point(15, 35);
        textBox2->Location = System::Drawing::Point(15, 85);
        label1->Location = System::Drawing::Point(15, 15);
        label2->Location = System::Drawing::Point(15, 65);
        okButton->Text = "OK";
        okButton->Location = System::Drawing::Point(15, 115);
        label1->Text = "Сопротивление:";
        label2->Text = "Напряжение";
        okButton->Click += gcnew System::EventHandler(this, &InputForm::okButton_Click);

        this->Controls->Add(textBox1);
        this->Controls->Add(textBox2);
        this->Controls->Add(label1);
        this->Controls->Add(label2);
        this->Controls->Add(okButton);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
    }

private:
    System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
    }
};

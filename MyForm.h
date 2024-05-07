#pragma once
#include <array>
#include "Elec.h"
#include "Tree.h"
#include "Input_form.h"
namespace Fact {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace std;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	/// 
	public ref class MyForm : public System::Windows::Forms::Form
	{

		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	public: //»нициализаци€
		Scheme_tree^ root;
		Graphics^ g;
		List<Scheme_tree^>^ list_nodes;
		List<Scheme_tree^>^ list_leafs;
		bool init_load = true;
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1527, 900);
			this->Name = L"MyForm";
			this->Text = L"Ёлектрическа€ цепь";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		//InputFormKey^ inputFormKey = gcnew InputFormKey("ключ");
		//inputFormKey->ShowDialog();

		//InputFormEDS^ inputFormEDS = gcnew InputFormEDS("эдс");
		//inputFormEDS->ShowDialog();

		//InputFormBaselement^ inputFormKeyBE = gcnew InputFormBaselement("резистор");
		//inputFormKeyBE->ShowDialog();


		//if (inputForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		//{
		//	// «десь вы можете получить доступ к значени€м в текстовых пол€х
		//	String^ resistance = inputForm->res_textbox->Text;
		//	String^ voltage = inputForm->cur_textbox->Text;
		//	// »спользуйте значени€ resistance и voltage
		//}
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		g = e->Graphics;
		g->Clear(Color::Aquamarine);
		if(init_load) { create_init(e); }
		root->all_paint(g);
	}
	void create_init(System::Windows::Forms::PaintEventArgs^ e)
	{
		EDS^ Eds0 = gcnew EDS();
		root = gcnew Scheme_tree(Eds0, this->ClientRectangle.Height / 2, g);
		init_load = false; 
	}
    void draw_arrow()
	{

	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	};
}

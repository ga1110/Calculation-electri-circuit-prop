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
	/// Сводка для MyForm
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
	public: //Инициализация
		Scheme_tree^ root;
		Graphics^ g;
		List<Scheme_tree^>^ list_nodes;
		List<Scheme_tree^>^ list_leafs;
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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
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
			this->Text = L"Электрическая цепь";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);
		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		InputForm^ form = gcnew InputForm();
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ text1 = form->textBox1->Text;
			String^ text2 = form->textBox2->Text;
			// Используйте text1 и text2
		}
		g = e->Graphics;
		g->Clear(Color::Aquamarine);
		EDS^ Eds0 = gcnew EDS(5, 0);
		Resistor^ Resistor0 = gcnew Resistor(3);
		Resistor^ Resistor01 = gcnew Resistor(4);
		Electric_device^ Ed0 = gcnew Electric_device(6, 1);
		Key^ key0 = gcnew Key(1);
		Lamp^ lamp0 = gcnew Lamp(7, 1);
		Lamp^ lamp1 = gcnew Lamp(2, 1);
		root = gcnew Scheme_tree(Eds0, this->ClientRectangle.Height / 2, g);
		

		Scheme_tree^ tmp1 = root->get_top();
		tmp1 = tmp1->set_node(root, lamp0);

		Scheme_tree^ tmp2 = root->get_bottom();
		tmp2 = tmp2->set_node(root, Resistor0);

		Scheme_tree^ tmp3 = tmp2->get_straight();
		tmp3 = tmp3->set_node(tmp2, lamp1);

		Scheme_tree^ tmp4 = tmp3->get_top();
		tmp4 = tmp4->set_node(tmp3, lamp1);

		Scheme_tree^ tmp5 = tmp3->get_bottom();
		tmp5 = tmp5->set_node(tmp3, lamp1);

		//
		//float my_result = root->get_all_res();
		////Цикл по всем элементам (надпись + рисунок)

		//float a = root->get_element()->Get_Res();
		//float b = tmp1->get_element()->Get_Res();
		//float c = tmp2->get_element()->Get_Res();
		//float d = tmp3->get_element()->Get_Res();
		//d += 1 / (1/tmp4->get_element()->Get_Res() + 1/tmp5->get_element()->Get_Res());
		//float result = a + 1/(1/b + 1/(c+d));
		//MessageBox::Show("Моё - " + my_result.ToString() + "\n" +
		//"Настоящий - " + result);
		
	}
    void draw_arrow()
	{

	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	};
}

/*
TODO:
1) Отрисовка относительно начальной координаты
2) Дорисовка отсутствубщих элементов (линии)
3) Перерисовка когда добавляется разделение
4) Элементы управления экраном 
5) Переключение места отрисовка и стрелка указывающаю на текущее местоположение
6) При выборе места выпадающий список с возможными элементами 
7) Структура для подсчета 

Отрисвока должна быть относительно оструктуры.
*/
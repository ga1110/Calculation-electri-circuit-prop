#pragma once
#include <array>
#include "Elec.h"
#include "Tree.h"
#include "Input_form.h"
#include "Change_form.h"
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
		Scheme_tree^ root; // Корень схемы
		Graphics^ g; // Пространство графики
		List<Scheme_tree^>^ list_nodes; // Список узлов 
		List<Scheme_tree^>^ list_leafs; // Список листьев
		bool init_load = true; // Нужна ли инициализация корня 
		bool scheme_completed = false; // Собрана ли схема целиком
		int current_element_ln = 0;
		int current_element_lf = 0;
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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		g = e->Graphics;
		g->Clear(Color::Aquamarine);
		if(init_load) { create_init(e); }
		root->all_paint(g, !scheme_completed);
	}

	void create_init(System::Windows::Forms::PaintEventArgs^ e) // Начальный узел - эдс
	{
		EDS^ Eds0 = gcnew EDS();
		root = gcnew Scheme_tree(Eds0, this->ClientRectangle.Height / 2, g);
		init_load = false; 
		list_nodes = root->list_nodes(root);
		list_leafs = root->list_leafs(root);
		list_leafs[current_element_lf]->draw_arrow(true);
		ChangeForm^ inputForm = gcnew ChangeForm(Eds0);
		inputForm->ShowDialog();
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}



	void create_new_node()
	{

		InputFormChoose^ inputForm = gcnew InputFormChoose();
		Scheme_tree^ tmp_node = list_leafs[current_element_lf];;
		Scheme_tree^ tmp_parent_node;
		if (inputForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (inputForm->eds_check->Checked)
			{
				EDS^ tmp_eds = gcnew EDS();
				tmp_parent_node = list_leafs[current_element_lf]->get_parent();
				tmp_node = tmp_node->set_node(tmp_parent_node, tmp_eds);
			}
			else if (inputForm->resistor_check->Checked)
			{
				Resistor^ tmp_resistor = gcnew Resistor();
				tmp_parent_node = list_leafs[current_element_lf]->get_parent();
				tmp_node = tmp_node->set_node(tmp_parent_node, tmp_resistor);
			}
			else if (inputForm->edev_check->Checked)
			{
				Electric_device^ tmp_edev = gcnew Electric_device();
				tmp_parent_node = list_leafs[current_element_lf]->get_parent();
				tmp_node = tmp_node->set_node(tmp_parent_node, tmp_edev);
			}
			else if (inputForm->lamp_check->Checked)
			{
				Lamp^ tmp_lamp = gcnew Lamp();
				tmp_parent_node = list_leafs[current_element_lf]->get_parent();
				tmp_node = tmp_node->set_node(tmp_parent_node, tmp_lamp);
			}
			else if (inputForm->key_check->Checked)
			{
				Key^ tmp_key = gcnew Key();
				tmp_parent_node = list_leafs[current_element_lf]->get_parent();
				tmp_node = tmp_node->set_node(tmp_parent_node, tmp_key);
			}
		}
		//Обновление списков
		list_nodes = root->list_nodes(root);
		list_leafs = root->list_leafs(root);
		list_leafs[current_element_lf]->draw_arrow(true);
		Refresh();
	}

	void change_scheme_buttons(System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode)
		{
		case Keys::Left:
			list_nodes[current_element_ln]->draw_arrow(false);
			current_element_ln = (current_element_ln > 0) ? current_element_ln - 1 : list_nodes->Count - 1;
			list_nodes[current_element_ln]->draw_arrow(true);
			break;
		case Keys::Right:
			list_nodes[current_element_ln]->draw_arrow(false);
			current_element_ln = (current_element_ln < list_nodes->Count - 1) ? current_element_ln + 1 : 0;
			list_nodes[current_element_ln]->draw_arrow(true);
			break;
		case Keys::Enter:
			
			break;
		case Keys::Escape:
			list_leafs[current_element_lf]->draw_arrow(!list_leafs[current_element_lf]->get_drawarrow());
			list_nodes[current_element_ln]->draw_arrow(!list_nodes[current_element_ln]->get_drawarrow());
			scheme_completed = !scheme_completed;
			break;
		default:
			break;
		}
		Refresh();
	}

	void create_scheme_buttons(System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode)
		{
		case Keys::Left:
			list_leafs[current_element_lf]->draw_arrow(false);
			current_element_lf = (current_element_lf > 0) ? current_element_lf - 1 : list_leafs->Count - 1;
			list_leafs[current_element_lf]->draw_arrow(true);
			break;
		case Keys::Right:
			list_leafs[current_element_lf]->draw_arrow(false);
			current_element_lf = (current_element_lf < list_leafs->Count - 1) ? current_element_lf + 1 : 0;
			list_leafs[current_element_lf]->draw_arrow(true);
			break;
		case Keys::Enter:
			create_new_node();
			break;
		case Keys::Escape:
			list_leafs[current_element_lf]->draw_arrow(!list_leafs[current_element_lf]->get_drawarrow());
			list_nodes[current_element_ln]->draw_arrow(!list_nodes[current_element_ln]->get_drawarrow());
			scheme_completed = !scheme_completed;
			break;
		default:
			break;
		}
		Refresh();
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (scheme_completed)
		{
			change_scheme_buttons(e);
		}
		else
		{
			create_scheme_buttons(e);
		}
	}
	};


}

#pragma once
#include "Elec.h"
public ref class Scheme_tree
{
private:
	Scheme_tree^ parent; // Родительский узел
	Scheme_tree^ top; // Верхний потомок
	Scheme_tree^ straight; // Средний потомок
	Scheme_tree^ bottom; // Нижний потомок 
	E_elem^ element; // Элемент схемы
	bool leaf;
	Point^ point;
	int height;
public:
	static int split_count = 1;
	static Pen^ pen = gcnew Pen(Color::Black, 6);
	static Graphics^ g = nullptr;
	static Scheme_tree^ root = nullptr;
	static Pen^ arrow_pen = gcnew Pen(Color::Red, 5);
	
	Scheme_tree(Scheme_tree^ parent, E_elem^ element, bool leaf, Point^ old_point, int d)  // Конструктор узла-листа 
	{
		this->height = d;
		this->point = gcnew Point(old_point->X, old_point->Y);
		this->parent = parent;
		this->element = element;
		this->top = nullptr;
		this->straight = nullptr;
		this->bottom = nullptr;
		this->parent = parent;
		this->leaf = leaf;
	}
	Scheme_tree(E_elem^ element, float y, Graphics^ new_g) // Начальный узел 
	{
		this->height = 0;
		this->element = element;
		this->parent = nullptr;
		this->leaf = false;
		this->point = gcnew Point(0, y);

		this->top = gcnew Scheme_tree(this, element, true, gcnew Point(100, (y-20)), abs(this->height) + 1);
		this->straight = gcnew Scheme_tree(this, element, true, gcnew Point(100, y), this->height);
		this->bottom = gcnew Scheme_tree(this, element, true, gcnew Point(100, (y+20)), abs(this->height) - 1);
		root = this;
		set_g(new_g); // Задаем Graphics 
		this->paint(); // Вызываем отрисовку
	}
	Scheme_tree^ set_node(Scheme_tree^ node, E_elem^ new_elemenet) // Функция пересоздания узла из узла-листа
	{
		this->element = new_elemenet;
		this->parent = node;

		if (node->top == this || node->bottom == this) // У элемента может быть только 2 верхних или 1 потомок по середине 
		{
			node->straight = nullptr;
			split_count += 1;
			all_paint(g);
		}
		else
		{
			node->top = nullptr;
			node->bottom = nullptr;
			all_paint(g);
		}
		this->paint_split();
		this->top = gcnew Scheme_tree(this, element, true, gcnew Point(this->point->X + 100, (this->point->Y-20)), abs(this->height) + 1);
		this->straight = gcnew Scheme_tree(this, element, true, gcnew Point(this->point->X + 100, this->point->Y), this->height);
		this->bottom = gcnew Scheme_tree(this, element, true, gcnew Point(this->point->X + 100, (this->point->Y+20)), -(abs(this->height) + 1));
		this->leaf = false;
		element->to_paint(g, point); // Вызываем отрисовку
		return this;

	}

	Scheme_tree^ get_parent()
	{
		return this->parent;
	}

	Scheme_tree^ get_top()
	{
		return this->top;
	}

	Scheme_tree^ get_straight()
	{
		return this->straight;
	}

	Scheme_tree^ get_bottom()
	{
		return this->bottom;
	}

	E_elem^ get_element()
	{
		return this->element;
	}
	Point^ get_point()
	{
		return this->point;
	}
	int get_count()
	{
		return split_count;
	}
	int get_height()
	{
		return this->height;
	}
	bool is_leaf()
	{
		return this->leaf;
	}

	void paint()
	{
		this->element->to_paint(g, this->point);
		
	}

	void set_g(Graphics^ new_g)
	{
		g = new_g;
	}

	void paint_split()
	{
		float x1 = this->parent->point->X + 50;
		float y1 = this->parent->point->Y;

		float x2 = this->point->X;
		float y2 = this->point->Y;
		this->point->X = x2;
		this->point->Y = y2;

		g->DrawLine(pen, x1, y1, x1 + 10, y1);
		g->DrawLine(pen, x1 + 10, y1, x1 + 10, y2);
		g->DrawLine(pen, x1 + 10, y2, x2, y2);
	}

	void draw_arrow()
	{
		float param1 = (this->parent->get_top() == this) ? -50 : 50;
		float param2 = (this->parent->get_top() == this) ? -20 : 20;
		float start_x = this->point->X + 25;
		float start_y = this->point->Y + param1;
		g->DrawLine(arrow_pen, start_x, start_y, start_x, start_y + param1);
		g->DrawLine(arrow_pen, start_x, start_y, start_x - 10, start_y + param2);
		g->DrawLine(arrow_pen, start_x, start_y, start_x + 10, start_y + param2);
	}

	void all_paint(Graphics^ tmp_g)
	{
		g = tmp_g;
		Scheme_tree^ tmp_root = root;
		all_paint_help(tmp_root, 0);

	}
	void all_paint_help(Scheme_tree^ node, float y)
	{
		if (node == nullptr)
		{
			return;
		}
		float new_y = (node->height > 0) ? (-30) * (split_count - node->height) : 30 * (split_count + node->height);
		if (node->is_leaf() == true) 
		{
			node->point->Y = y + new_y;
			return;
		}
		else if (node != root)
		{
			node->point->Y = y + new_y;
			node->paint();
			node->paint_split();
		}
		else
		{
			node->paint();
		}
		
		
		
		all_paint_help(node->top, node->point->Y);
		all_paint_help(node->straight, y);
		all_paint_help(node->bottom, node->point->Y);
	}

	List<Scheme_tree^>^ list_nodes(Scheme_tree^ node)
	{
		List<Scheme_tree^>^ list = gcnew List<Scheme_tree^>();
		if (node->is_leaf() != true)
		{
			list->Add(node);
		}
		if (node->get_top() != nullptr)
		{
			list->AddRange(list_nodes(node->get_top()));
		}
		if (node->get_straight() != nullptr)
		{
			list->AddRange(list_nodes(node->get_straight()));
		}
		if (node->get_bottom() != nullptr)
		{
			list->AddRange(list_nodes(node->get_bottom()));
		}
		return list;
	}
	List<Scheme_tree^>^ list_leafs(Scheme_tree^ node) // Функция дял получения всех доступных листьев 
	{
		List<Scheme_tree^>^ list = gcnew List<Scheme_tree^>();
		if (node->is_leaf() == true)
		{
			list->Add(node);
		}
		if (node->get_top() != nullptr)
		{
			list->AddRange(list_leafs(node->get_top()));
		}
		if (node->get_straight() != nullptr)
		{
			list->AddRange(list_leafs(node->get_straight()));
		}
		if (node->get_bottom() != nullptr)
		{
			list->AddRange(list_leafs(node->get_bottom()));
		}
		return list;
	}

	float get_all_res()
	{
		Scheme_tree^ tmp_root = root;
		float res = root->element->Get_Res();
		get_all_res_help(tmp_root, res);
		return res;
	}
	float get_all_res_help(Scheme_tree^ node, float% res)
	{
		
		if (node == nullptr)
		{
			return res; 
		}
		
		if (node->top->is_leaf() && node->bottom->is_leaf() && node->straight->is_leaf() )
		{
			res += node->element->Get_Res();
			return res;
		}
		
		if ((!node->top->is_leaf() && !node->bottom->is_leaf()))
		{
			res += parallel_connect(node, res);
			return res;
		}
		if (node->top != nullptr)
		{
			straight_connect(node->top, res);
		}
		else if (node->straight != nullptr)
		{
			straight_connect(node->straight, res);
		}
		else if (node->bottom != nullptr)
		{
			straight_connect(node->bottom, res);
		}
		else
		{
			return res;
		}
		// Соединение прямое, если у узла только один потомок и наважно какой 
	
		return res;
	}
	float parallel_connect(Scheme_tree^ node, float% res)
	{

		if (node == nullptr)
		{
			return res;
		}
		float tmp_res_top = 0, tmp_res_bot = 0;
		tmp_res_top += straight_connect(node->top, tmp_res_top);
		tmp_res_bot += straight_connect(node->bottom, tmp_res_bot);
		res = 1 / (1 / tmp_res_top + 1 / tmp_res_bot);
		MessageBox::Show("Верхний - " + tmp_res_top.ToString() + "\n" +
			"Нижний - " + tmp_res_bot.ToString() + "\n" +
			"Результат -" + res.ToString());
		return res;
	}
	float straight_connect(Scheme_tree^ node, float% res)
	{
		if (node == nullptr || node->is_leaf())
		{
			return res;
		}

		res += node->element->Get_Res();

		if (node->top != nullptr && node->bottom != nullptr && !node->top->is_leaf() && !node->bottom->is_leaf())
		{
			res += parallel_connect(node, res);
			return res;
		}

		straight_connect(node->straight, res);
		straight_connect(node->top, res);
		straight_connect(node->bottom, res);

		return res;
	}
};

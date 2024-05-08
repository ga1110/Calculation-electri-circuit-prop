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
	bool drawarrow;
public:
	static int split_count = 1;
	static Pen^ pen = gcnew Pen(Color::Black, 6);
	static Graphics^ g = nullptr;
	static Scheme_tree^ root = nullptr;
	static Pen^ arrow_pen_inner = gcnew Pen(Color::Red, 2); // Цвет и толщина внутренней части стрелки
	static Pen^ arrow_pen_outline = gcnew Pen(Color::Black, 8); // Цвет и толщина обводки

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
		this->drawarrow = false;
	}
	Scheme_tree(E_elem^ element, float y, Graphics^ new_g) // Начальный узел 
	{
		this->height = 0;
		this->element = element;
		this->parent = nullptr;
		this->leaf = false;
		this->point = gcnew Point(0, y);

		this->top = gcnew Scheme_tree(this, element, true, gcnew Point(100, (y - 20)), abs(this->height) + 1);
		this->straight = gcnew Scheme_tree(this, element, true, gcnew Point(100, y), this->height);
		this->bottom = gcnew Scheme_tree(this, element, true, gcnew Point(100, (y + 20)), abs(this->height) - 1);
		root = this;
		this->drawarrow = false;
		set_g(new_g); // Задаем Graphics 
	}
	Scheme_tree^ set_node(Scheme_tree^ node, E_elem^ new_elemenet) // Функция пересоздания узла из узла-листа
	{
		this->element = new_elemenet;
		this->parent = node;
		if (node->top == this || node->bottom == this) // У элемента может быть только 2 верхних или 1 потомок по середине 
		{
			node->straight = nullptr;
			split_count += 1;
		}
		else
		{
			node->top = nullptr;
			node->bottom = nullptr;
		}
		this->top = gcnew Scheme_tree(this, element, true, gcnew Point(this->point->X + 100, (this->point->Y - 20)), abs(this->height) + 1);
		this->straight = gcnew Scheme_tree(this, element, true, gcnew Point(this->point->X + 100, this->point->Y), this->height);
		this->bottom = gcnew Scheme_tree(this, element, true, gcnew Point(this->point->X + 100, (this->point->Y + 20)), -(abs(this->height) + 1));
		this->leaf = false;
		this->drawarrow = false;
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

	bool get_drawarrow()
	{
		return this->drawarrow;
	}

	bool is_leaf()
	{
		return this->leaf;
	}

	void paint()
	{
		if (!this->is_leaf())
		{
			if (this->drawarrow)
			{
				this->draw_arrow_help();
			}
			this->element->to_paint(g, this->point);
		}
		else
		{
			if (this->drawarrow)
			{
				this->draw_arrow_help();
			}
		}
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

	void draw_arrow(bool d_a)
	{
		this->drawarrow = d_a;
	}

	void draw_arrow_help()
	{
		float param1, param2, start_x, start_y;
		if (!this->is_leaf())
		{
			if (this == root)
			{
				param1 = 55;
				param2 = 25;
			}
			else
			{
				param1 = (this->parent->get_top() == this) ? -55 : 55;
				param2 = (this->parent->get_top() == this) ? -25 : 25;
			}
			start_x = this->point->X + 25;
			start_y = this->point->Y + param1;

			
			// Обводка
			g->DrawLine(arrow_pen_outline, start_x, start_y, start_x, start_y + param1);
			g->DrawLine(arrow_pen_outline, start_x + 1, start_y + 2, start_x - 10, start_y + param2);
			g->DrawLine(arrow_pen_outline, start_x - 1, start_y + 2, start_x + 10, start_y + param2);

			g->DrawLine(arrow_pen_inner, start_x, start_y, start_x, start_y + param1);
			g->DrawLine(arrow_pen_inner, start_x, start_y, start_x - 10, start_y + param2);
			g->DrawLine(arrow_pen_inner, start_x, start_y, start_x + 10, start_y + param2);
		}
		else
		{
			start_x = this->point->X + 5;
			start_y = this->point->Y;
			param1 = start_x + 50;

			// Обводка
			g->DrawLine(arrow_pen_outline, start_x, start_y, param1, start_y);
			g->DrawLine(arrow_pen_outline, start_x - 2, start_y - 2, start_x + 10, start_y + 10);
			g->DrawLine(arrow_pen_outline, start_x - 2, start_y + 2, start_x + 10, start_y - 10);

			// Внутренняя часть 
			g->DrawLine(arrow_pen_inner, start_x, start_y, param1, start_y);
			g->DrawLine(arrow_pen_inner, start_x, start_y, start_x + 10, start_y + 10);
			g->DrawLine(arrow_pen_inner, start_x, start_y, start_x + 10, start_y - 10);
		}
	}

	void all_paint(Graphics^ tmp_g, bool scheme_completed)
	{
		g = tmp_g;
		Scheme_tree^ tmp_root = root;
		all_paint_help(tmp_root, root->point->Y, scheme_completed);

	}
	void all_paint_help(Scheme_tree^ node, float y, bool scheme_completed)
	{
		if (node == nullptr)
		{
			return;
		}
		float param1_y = (split_count - node->height == 0) ? 1 : split_count - node->height;
		float param2_y = (split_count + node->height == 0) ? 1 : split_count + node->height;
		float new_y = (node->height > 0) ? (-30) * (param1_y) : 30 * (param2_y);
		if (node->is_leaf() == true && !(root->straight == node)) 
		{
			node->point->Y = y + new_y;
			node->paint();
			if (scheme_completed)
			{
				node->paint_split();
			}
			return;
		}
		else if (node->is_leaf() == true && (root->straight == node))
		{
			
			node->point->Y = y;
			node->paint();
			if (scheme_completed)
			{
				node->paint_split();
			}
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
		
		all_paint_help(node->top, node->point->Y, scheme_completed);
		all_paint_help(node->straight, y, scheme_completed);
		all_paint_help(node->bottom, node->point->Y, scheme_completed);
	}

	float get_all_res()
	{
		Scheme_tree^ tmp_root = root;
		float res = root->element->get_res();
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
			res += node->element->get_res();
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

		res += node->element->get_res();

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

};

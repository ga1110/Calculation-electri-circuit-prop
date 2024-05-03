#pragma once
#include <cliext/list>
using namespace System::Collections::Generic;
using namespace cliext;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
public ref class E_elem
{
protected:
	String^ name;
	double resistance;
	double voltage;
	double current;
	bool isWork;
	Pen^ pen;
	SolidBrush^ font_pen;
	Font^ draw_font;
public:
	E_elem()
	{
		resistance = 0;
		voltage = 0;
		current = 0;
		pen = gcnew Pen(Color::Black);
		pen->Width = 6;
		font_pen = gcnew SolidBrush(Color::Black);
		draw_font = gcnew Font("Arial", 8);
	}
	E_elem(double res, double vol, double cur, bool w)
	{
		resistance = res;
		voltage = vol;
		current = cur;
		isWork = w;
		pen = gcnew System::Drawing::Pen(Color::Black);
		pen->Width = 6;
		font_pen = gcnew SolidBrush(Color::Black);
		draw_font = gcnew Font("Arial", 8);
	}
	String^ Get_Name()
	{
		return name;
	}
	virtual double Get_Res()
	{
		return resistance;
	}
	virtual double Get_Vol()
	{
		return voltage;
	}
	virtual double Get_Cur()
	{
		return current;
	}
	virtual void set_res(double new_h)
	{
		resistance = new_h;
	}
	virtual void set_vol(double new_h)
	{
		voltage = new_h;
	}
	virtual void set_cur(double new_h)
	{
		current = new_h;
		set_vol(new_h * Get_Res());

	}
	virtual bool get_work()
	{
		return isWork =((Get_Res() != 0 && Get_Cur() != 0))? true: false;

	}
	virtual void set_work(bool w)
	{
		isWork = w;
	}
	virtual String^ get_info()
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ res = "Сопротивление: " + Get_Res().ToString() + " Ом" + "\n";
		String^ cur = "Сила тока: " + Get_Cur().ToString() + " A" + "\n";
		String^ vol = "Напряжение : " + Get_Vol().ToString() + " В" + "\n";
		String^ connect = "Подключен к сети :" + ((this->Get_Cur() != 0) ? " да" : " нет") + "\n";
		return name + res + cur + vol + connect;
	}
	virtual void to_paint(Graphics^ g, Point^ point)
	{

		
	}
};
public ref class EDS : E_elem
{
public:
	static int eds_count = 0;
	EDS(double res, double cur) :E_elem(res, 0, cur, 1)
	{
		name = "EDS" + eds_count.ToString();
		resistance = res;
		current = cur;
		eds_count += 1;
	}
	void to_paint(Graphics^ g, Point^ point) override
	{
		float x = point->X; //начальная точка X
		float y = point->Y; //начальная точка X

		g->DrawLine(pen, x, y, x + 20, y);
		g->DrawLine(pen, x + 20, y, x + 20, y + 25);
		g->DrawLine(pen, x + 20, y, x + 20, y - 25);

		g->DrawLine(pen, x + 30, y, x + 30, y + 25);
		g->DrawLine(pen, x + 30, y, x + 30, y - 25);
		g->DrawLine(pen, x + 30, y, x + 50, y);

		g->DrawString(name, draw_font, font_pen, x + 10, y + 30);
	}
};
public ref class Resistor : E_elem
{
protected:
public:
	static int res_count = 0;
	Resistor(double res) :E_elem(res, 0, 0, 1)
	{
		name = "Resistor" + res_count.ToString();
		resistance = res;
		res_count += 1;
 
	}

	void to_paint(Graphics^ g, Point^ point) override
	{
		float x = point->X; //начальная точка X
		float y = point->Y; //начальная точка X

		g->DrawLine(pen, x, y, x + 10, y);

		g->DrawLine(pen, x + 10, y, x + 10, y + 25);
		g->DrawLine(pen, x + 10, y + 25, x + 40, y + 25);
		g->DrawLine(pen, x + 40, y + 25, x + 40, y);


		g->DrawLine(pen, x + 10, y, x + 10, y - 25);
		g->DrawLine(pen, x + 10, y - 25, x + 40, y - 25);
		g->DrawLine(pen, x + 40, y - 25, x + 40, y);

		g->DrawLine(pen, x + 40, y, x + 50, y);

		g->DrawString(name, draw_font, font_pen, x, y + 30);
	}

};

public ref class Electric_device : E_elem
{
protected:
public:
	static int ed_count = 0;
	Electric_device(double res, bool w) :E_elem(res, 0, 0, w)
	{
		name = "E_dev" + ed_count.ToString();
		resistance = res;
		isWork = w;
		ed_count += 1;
	}
	String^ get_info() override
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ res = "Сопротивление: " + Get_Res().ToString() + " Ом" + "\n";
		String^ cur = "Сила тока: " + Get_Cur().ToString() + " A" + "\n";
		String^ vol = "Напряжение : " + Get_Vol().ToString() + " В" + "\n";
		String^ connect = "Подключен к сети :" + ((this->Get_Cur() != 0) ? " да" : " нет") + "\n";
		String^ work = "Работает:" + ((this->get_work()) ? " да" : " нет") + "\n";
		return name + res + cur + vol + connect + work;
	}
	bool get_work() override
	{
		isWork = !(Get_Res() == 0 || Get_Cur() == 0 || Get_Vol() == 0);
		return isWork;

	}
	void set_res(double h) override
	{
		resistance = h;
		set_vol(h * Get_Cur());
		get_work();
	}
	void set_vol(double new_h) override
	{
		voltage = new_h;
		get_work();
	}
	void set_cur(double new_h) override
	{
		current = new_h;
		set_vol(new_h * Get_Res());
		get_work();

	}
	void to_paint(Graphics^ g, Point^ point) override
	{
		float x = point->X; //начальная точка X
		float y = point->Y; //начальная точка X

		g->DrawLine(pen, x, y, x + 10, y);

		pen->Color = (get_work())? Color::Yellow : Color::Black;
		g->DrawLine(pen, x + 10, y, x + 15, y + 15);
		g->DrawLine(pen, x + 15, y + 15, x + 20, y - 20);
		g->DrawLine(pen, x + 20, y - 20, x + 30, y + 10);
		g->DrawLine(pen, x + 30, y + 10, x + 40, y);
		pen->Color = Color::Black;

		g->DrawLine(pen, x + 40, y, x + 50, y);

		g->DrawString(name, draw_font, font_pen, x + 2, y + 30);
	}
};
public ref class Lamp : E_elem
{
protected:
public:
	static int lamp_count = 0;
	Lamp(double res, bool w) :E_elem(res, 0, 0, w)
	{
		name = "Lamp" + lamp_count.ToString();
		resistance = res;
		isWork = w;
		lamp_count += 1;
	}
	String^ get_info() override
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ res = "Сопротивление: " + Get_Res().ToString() + " Ом" + "\n";
		String^ cur = "Сила тока: " + Get_Cur().ToString() + " A" + "\n";
		String^ vol = "Напряжение : " + Get_Vol().ToString() + " В" + "\n";
		String^ connect = "Подключен к сети :" + ((this->Get_Cur() != 0) ? " да" : " нет") + "\n";
		String^ work = "Работает:" + ((this->get_work()) ? " да" : " нет") + "\n";
		return name + res + cur + vol + connect + work;
	}
	bool get_work() override
	{
		isWork = !(Get_Res() == 0 || Get_Cur() == 0 || Get_Vol() == 0);
		return isWork;

	}
	void set_res(double h) override
	{
		resistance = h;
		set_vol(h * Get_Cur());
		get_work();
	}
	void set_vol(double new_h) override
	{
		voltage = new_h;
		get_work();
	}
	void set_cur(double new_h) override
	{
		current = new_h;
		set_vol(new_h * Get_Res());
		get_work();
	}
	void to_paint(Graphics^ g, Point^ point) override
	{
		float x = point->X; //начальная точка X
		float y = point->Y; //начальная точка X

		g->DrawLine(pen, x, y, x + 10, y);

		g->DrawEllipse(pen, x+10, y+25, ((x + 40) - (x + 10)), ((y - 25) - (y + 25)));

		if (this->get_work())
		{
			Brush^ brush = gcnew SolidBrush(Color::Yellow);
			g->FillEllipse(brush, x + 13, y + 22, ((x + 37) - (x + 13)), ((y - 22) - (y + 22)));
		}
		pen->Width = 4;
		g->DrawLine(pen, x + 35, y - 20, x + 15, y + 20);
		g->DrawLine(pen, x + 35, y + 20, x + 15, y - 20);
		pen->Width = 6;

		g->DrawLine(pen, x + 40, y, x + 50, y);


		g->DrawString(name, draw_font, font_pen, x + 6, y + 30);
	}
};
public ref class Key : E_elem
{
protected:
	bool isWork;
public:
	static int key_count = 0;
	Key(bool w) :E_elem(0, 0, 0, w)
	{
		name = "Key" + key_count.ToString();
		isWork = w;
		key_count += 1;
 
	}
	bool get_work() override
	{
		return isWork;
	}
	void set_work(bool k) override
	{
		isWork = k;
	}
	void set_cur(double new_h) override
	{
		current = 0;
	}
	void set_res(double new_h) override
	{
		resistance = 0;
	}
	String^ get_info() override
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ work = "Замкнут:" + ((this->isWork) ? " да" : " нет") + "\n";
		return name + work;
	}
	void to_paint(Graphics^ g, Point^ point) override
	{
		float x = point->X; //начальная точка X
		float y = point->Y; //начальная точка X

		float new_y = (get_work()) ? y - 25 : y;
		g->DrawLine(pen, x, y, x + 10, y);

		g->DrawLine(pen, x + 10, y, x + 40, new_y);

		g->DrawLine(pen, x + 40, y, x + 50, y);

		g->DrawString(name, draw_font, font_pen, x + 10, y + 30);
	}
};


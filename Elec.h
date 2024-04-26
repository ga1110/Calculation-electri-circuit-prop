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
	String^ Name;
	PictureBox^ picBox = gcnew PictureBox();
	double Resistance;
	double Voltage;
	double Current;
	Image^ img;
	bool isWork;
	static List<E_elem^>^ elementsList = gcnew List<E_elem^>();
public:
	E_elem()
	{
		Resistance = 0;
		Voltage = 0;
		Current = 0;
	}
	E_elem(int ns, double res, double vol, double cur, Panel^ panel, double x, double y, bool w)
	{
		Resistance = res;
		Voltage = vol;
		Current = cur;
		isWork = w;
	}
	void Add_Image(PictureBox^ pic_box, Image^ img, double x, double y, Panel^ panel)
	{
		pic_box->Location = System::Drawing::Point(x, y);
		pic_box->Image = img; // Устанавливаем изображение в PictureBox
		pic_box->Size = img->Size;
		pic_box->SizeMode = PictureBoxSizeMode::AutoSize;
		panel->Controls->Add(pic_box); // Добавляем PictureBox на панель
	}
	String^ Get_Name()
	{
		return Name;
	}
	virtual double Get_Res()
	{
		return Resistance;
	}
	virtual double Get_Vol()
	{
		return Voltage;
	}
	virtual double Get_Cur()
	{
		return Current;
	}
	virtual void Set_Res(double new_h)
	{
		Resistance = new_h;
	}
	virtual void Set_Vol(double new_h)
	{
		Voltage = new_h;
	}
	virtual void Set_Cur(double new_h)
	{
		Current = new_h;
		Set_Vol(new_h * Get_Res());

	}
	virtual bool Get_Work()
	{
		return isWork =((Get_Res() != 0 && Get_Cur() != 0))? true: false;

	}
	virtual void Set_Work(bool w)
	{
		isWork = w;
	}
	virtual String^ Get_Info()
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ res = "Сопротивление: " + Get_Res().ToString() + " Ом" + "\n";
		String^ cur = "Сила тока: " + Get_Cur().ToString() + " A" + "\n";
		String^ vol = "Напряжение : " + Get_Vol().ToString() + " В" + "\n";
		String^ connect = "Подключен к сети :" + ((this->Get_Cur() != 0) ? " да" : " нет") + "\n";
		return name + res + cur + vol + connect;
	}
};
public ref class EDS : E_elem
{
protected:
	Image^ EDS_Image = Image::FromFile("EDS.png");
public:
	EDS(int ns, double res, double cur, Panel^ panel, double x, double y) :E_elem(ns, res, 0, cur, panel, x, y, 1)
	{
		Name = "EDS" + ns.ToString();
		Resistance = res;
		Current = cur;
		Add_Image(picBox, EDS_Image, x, y, panel);
	}

};
public ref class Resistor : E_elem
{
protected:
	Image^ Resistor_Image = Image::FromFile("Resistor.png");
public:
	Resistor(int ns, double res, Panel^ panel, double x, double y) :E_elem(ns, res, 0, 0, panel, x, y, 1)
	{
		Name = "Resistor" + ns.ToString();
		Resistance = res;
		Add_Image(picBox, Resistor_Image, x, y, panel);
 
	}

};

public ref class Electric_device : E_elem
{
protected:
	Image^ El_pribor1_Image = Image::FromFile("Electric device1.png");
	Image^ El_pribor0_Image = Image::FromFile("Electric device0.png");
public:
	Electric_device(int ns, double res, Panel^ panel, double x, double y, bool w) :E_elem(ns, res, 0, 0, panel, x, y, w)
	{
		Name = "ElectricDevice" + ns.ToString();
		Resistance = res;
		isWork = w;
		Image^ tmp_img = (isWork) ? El_pribor1_Image : El_pribor0_Image;
	    Add_Image(picBox, tmp_img, x, y, panel);
	}
	String^ Get_Info() override
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ res = "Сопротивление: " + Get_Res().ToString() + " Ом" + "\n";
		String^ cur = "Сила тока: " + Get_Cur().ToString() + " A" + "\n";
		String^ vol = "Напряжение : " + Get_Vol().ToString() + " В" + "\n";
		String^ connect = "Подключен к сети :" + ((this->Get_Cur() != 0) ? " да" : " нет") + "\n";
		String^ work = "Работает:" + ((this->Get_Work()) ? " да" : " нет") + "\n";
		return name + res + cur + vol + connect + work;
	}
	bool Get_Work() override
	{
		isWork = !(Get_Res() == 0 || Get_Cur() == 0 || Get_Vol() == 0);
		picBox->Image = isWork ? El_pribor1_Image : El_pribor0_Image;
		return isWork;

	}
	void Set_Res(double h) override
	{
		Resistance = h;
		Set_Vol(h * Get_Cur());
		Get_Work();
	}
	void Set_Vol(double new_h) override
	{
		Voltage = new_h;
		Get_Work();
	}
	void Set_Cur(double new_h) override
	{
		Current = new_h;
		Set_Vol(new_h * Get_Res());
		Get_Work();

	}
};
public ref class Lamp : E_elem
{
protected:
	Image^ Lamp1_Image = Image::FromFile("Lamp1.png");
	Image^ Lamp0_Image = Image::FromFile("Lamp0.png");
public:
	Lamp(int ns, double res, Panel^ panel, double x, double y, bool w) :E_elem(ns, res, 0, 0, panel, x, y, w)
	{
		Name = "Lamp" + ns.ToString();
		Resistance = res;
		isWork = w;
		Image^ tmp_image = (isWork) ? Lamp1_Image : Lamp0_Image;
		Add_Image(picBox, tmp_image, x, y, panel);
	}
	String^ Get_Info() override
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ res = "Сопротивление: " + Get_Res().ToString() + " Ом" + "\n";
		String^ cur = "Сила тока: " + Get_Cur().ToString() + " A" + "\n";
		String^ vol = "Напряжение : " + Get_Vol().ToString() + " В" + "\n";
		String^ connect = "Подключен к сети :" + ((this->Get_Cur() != 0) ? " да" : " нет") + "\n";
		String^ work = "Работает:" + ((this->Get_Work()) ? " да" : " нет") + "\n";
		return name + res + cur + vol + connect + work;
	}
	bool Get_Work() override
	{
		isWork = !(Get_Res() == 0 || Get_Cur() == 0 || Get_Vol() == 0);
		picBox->Image = isWork ? Lamp1_Image : Lamp0_Image;
		return isWork;

	}
	void Set_Res(double h) override
	{
		Resistance = h;
		Set_Vol(h * Get_Cur());
		Get_Work();
	}
	void Set_Vol(double new_h) override
	{
		Voltage = new_h;
		Get_Work();
	}
	void Set_Cur(double new_h) override
	{
		Current = new_h;
		Set_Vol(new_h * Get_Res());
		Get_Work();

	}
};
public ref class Key : E_elem
{
protected:
	Image^ Key0_Image = Image::FromFile("Key0.png");
	Image^ Key1_Image = Image::FromFile("Key1.png");
	bool isWork;
public:
	Key(int ns, Panel^ panel, double x, double y, bool w) :E_elem(ns, 0, 0, 0, panel, x, y, w)
	{
		Name = "Key" + ns.ToString();
		isWork = w;
		Image^ tmp_img = (isWork) ? Key1_Image : Key0_Image;
		Add_Image(picBox, tmp_img, x, y, panel);
 
	}
	bool Get_Work() override
	{
		return isWork;
	}
	void Set_Work(bool k) override
	{
		isWork = k;
		ChangeImage();
	}
	void Set_Cur(double new_h) override
	{
		Current = 0;
	}
	void Set_Res(double new_h) override
	{
		Resistance = 0;
	}
	String^ Get_Info() override
	{
		String^ name = "Имя: " + Get_Name() + "\n";
		String^ work = "Замкнут:" + ((this->isWork) ? " да" : " нет") + "\n";
		return name + work;
	}
	void ChangeImage()
	{
		picBox->Image = (isWork) ? Key1_Image : Key0_Image;
	}
};

public ref class Line : E_elem
{
protected:
	Image^ Line_Image = Image::FromFile("Line.png");
public:
	Line(Panel^ panel, double x, double y) :E_elem(0, 0, 0, 0, panel, x, y, 0)
	{
		Add_Image(picBox, Line_Image, x, y, panel);

	}

};
public ref class Razdel : Line
{
protected:
	Image^ Razdel_Image = Image::FromFile("Razdel.png");
public:
	Razdel(Panel^ panel, double x, double y) :Line(panel, x, y)
	{
		Add_Image(picBox, Razdel_Image, x, y, panel);
	}
};
public ref class RazdelR : Line
{
protected:
	Image^ RazdelR_Image = Image::FromFile("RazdelR.png");
public:
	RazdelR(Panel^ panel, double x, double y) :Line(panel, x, y)
	{
		Add_Image(picBox, RazdelR_Image, x, y, panel);
	}
};
public ref class Razdelm : Razdel
{
protected:
	Image^ Razdelm_Image = Image::FromFile("Razdelm.png");
public:
	Razdelm(Panel^ panel, double x, double y) :Razdel(panel, x, y)
	{
		Add_Image(picBox, Razdelm_Image, x, y, panel);
	}
};
public ref class RazdelmR : Razdel
{
protected:
	Image^ RazdelmR_Image = Image::FromFile("RazdelmR.png");
public:
	RazdelmR(Panel^ panel, double x, double y) :Razdel(panel, x, y)
	{
		Add_Image(picBox, RazdelmR_Image, x, y, panel);
	}
};

ref class ElementManager {
private:
	List<E_elem^>^ elements;

public:
	ElementManager() {
		elements = gcnew List<E_elem^>();
	}

	void AddElement(E_elem^ element) {
		elements->Add(element);
	}

	E_elem^ Find(String^ name) {
		for each (E_elem ^ element in elements) {
			if (element->Get_Name() == name) {
				return element;
			}
		}
		return nullptr;
	}
};
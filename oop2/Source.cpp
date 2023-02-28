#include <iostream>
#include <conio.h>

using namespace std;

class Tank //Стандартный класс
{
protected:
	int armor;
	int weapon;
public:
	Tank() //Конструктор по умолчанию
	{
		cout << "Tank()\n";
		armor = 0;
		weapon = 0;
	}
	Tank(int armor, int weapon) //Конструктор с параметрами
	{
		cout << "Tank(int armor, int weapon)\n";
		this->armor = armor;
		this->weapon = weapon;
	}
	Tank(const Tank& p) //Конструктор копирования 
	{
		cout << "Tank(const Tank& p)\n";
		armor = p.armor;
		weapon = p.weapon;
	}
	~Tank() //Деструктор
	{
		cout << "~Tank(" << armor << ", " << weapon << ")\n";
	}

	void swap_weapon(int newweapon) //Метод для замены одного из параметров
	{
		weapon = newweapon;
	}

	void reset(); //Метод обнуления параметров
};

void Tank::reset() //Инициализация метода
{
	armor = 0;
	weapon = 0;
}

class ColoredTank : public Tank //Класс с наследованием
{
protected:
	int color;
public:
	ColoredTank()  : Tank() //Конструктор по умолчанию
	{
		cout << "ColoredTank()\n";
		color = 0;
	}
	ColoredTank(int armor, int weapon, int color) : Tank(armor, weapon) //Конструктор с параметрами
	{
		cout << "ColoredTank(int armor, int weapon, int color)\n";
		this->color = color;
	}
	ColoredTank(const ColoredTank& p) //Конструктор копирования
	{
		cout << "ColoredTank(const ColoredTank& p)\n";
		color = p.color;
		armor = p.armor;
		weapon = p.weapon;
	}
	~ColoredTank() //Деструктор
	{
		cout << "~ColoredTank(" << armor << ", " << weapon << ", " << color << ")\n";
	}

	void change_color(int newcolor) //Метод замены одного из паметров
	{
		color = newcolor;
	}
};

class Duo //Класс с композицией
{
protected:
	Tank* t1;
	Tank* t2;
public:
	Duo() //Конструктор по умолчанию
	{
		cout << "Duo()\n";
		t1 = new Tank;
		t2 = new Tank;
	}
	Duo(int t1armor, int t1weapon, int t2armor, int t2weapon) //Конструктор с параметрами
	{
		cout << "Duo(Tank nt1, Tank nt2)\n";
		t1 = new Tank(t1armor, t1weapon);
		t2 = new Tank(t2armor, t2weapon);
	}
	Duo(const Duo& p) //Конструктор копирования
	{
		cout << "Duo(const Duo& p)\n";
		t1 = new Tank(*(p.t1));
		t2 = new Tank(*(p.t2));
	}
	~Duo() //Деструктор
	{
		cout << "~Duo()\n";
		delete t1;
		delete t2;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Конструкторы/деструкторы класса\n" << "t1 - конструктор по умолчанию, t2 - конструктор с заданными параметрами, t3 - конструктор копирования от t2\n";
	{
		Tank t1;
		Tank t2(90, 75);
		Tank t3(t2);
	}
	_getch();
	cout << "Методы класса\n" << "Будет создан новый объект и на нем показана работа методов, начальные значения (90, 0)\n";
	{
		{
			Tank t1(90, 0);
			t1.reset();
		}
		{
			Tank t2(90, 0);
			t2.swap_weapon(85);
		}
	}
	_getch();
	cout << "Конструкторы/деструкторы класса с наследованием(созданы динамически)\n";
	{
		ColoredTank* t1 = new ColoredTank;
		ColoredTank* t2 = new ColoredTank(90, 75, 1);
		ColoredTank* t3 = new ColoredTank(*t2);
		delete t1;
		delete t2;
		delete t3;
	}
	_getch();
	cout << "Конструкторы/деструкторы класса с композицией(созданы динамически)\n";
	{
		Duo* d1 = new Duo;
		Duo* d2 = new Duo(90, 75, 30, 150);;
		Duo* d3 = new Duo(*(d2));
		delete d1;
		delete d2;
		delete d3;
	}
	_getch();
}
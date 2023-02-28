#include <iostream>
#include <conio.h>

using namespace std;

class Tank //����������� �����
{
protected:
	int armor;
	int weapon;
public:
	Tank() //����������� �� ���������
	{
		cout << "Tank()\n";
		armor = 0;
		weapon = 0;
	}
	Tank(int armor, int weapon) //����������� � �����������
	{
		cout << "Tank(int armor, int weapon)\n";
		this->armor = armor;
		this->weapon = weapon;
	}
	Tank(const Tank& p) //����������� ����������� 
	{
		cout << "Tank(const Tank& p)\n";
		armor = p.armor;
		weapon = p.weapon;
	}
	~Tank() //����������
	{
		cout << "~Tank(" << armor << ", " << weapon << ")\n";
	}

	void swap_weapon(int newweapon) //����� ��� ������ ������ �� ����������
	{
		weapon = newweapon;
	}

	void reset(); //����� ��������� ����������
};

void Tank::reset() //������������� ������
{
	armor = 0;
	weapon = 0;
}

class ColoredTank : public Tank //����� � �������������
{
protected:
	int color;
public:
	ColoredTank()  : Tank() //����������� �� ���������
	{
		cout << "ColoredTank()\n";
		color = 0;
	}
	ColoredTank(int armor, int weapon, int color) : Tank(armor, weapon) //����������� � �����������
	{
		cout << "ColoredTank(int armor, int weapon, int color)\n";
		this->color = color;
	}
	ColoredTank(const ColoredTank& p) //����������� �����������
	{
		cout << "ColoredTank(const ColoredTank& p)\n";
		color = p.color;
		armor = p.armor;
		weapon = p.weapon;
	}
	~ColoredTank() //����������
	{
		cout << "~ColoredTank(" << armor << ", " << weapon << ", " << color << ")\n";
	}

	void change_color(int newcolor) //����� ������ ������ �� ��������
	{
		color = newcolor;
	}
};

class Duo //����� � �����������
{
protected:
	Tank* t1;
	Tank* t2;
public:
	Duo() //����������� �� ���������
	{
		cout << "Duo()\n";
		t1 = new Tank;
		t2 = new Tank;
	}
	Duo(int t1armor, int t1weapon, int t2armor, int t2weapon) //����������� � �����������
	{
		cout << "Duo(Tank nt1, Tank nt2)\n";
		t1 = new Tank(t1armor, t1weapon);
		t2 = new Tank(t2armor, t2weapon);
	}
	Duo(const Duo& p) //����������� �����������
	{
		cout << "Duo(const Duo& p)\n";
		t1 = new Tank(*(p.t1));
		t2 = new Tank(*(p.t2));
	}
	~Duo() //����������
	{
		cout << "~Duo()\n";
		delete t1;
		delete t2;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������/����������� ������\n" << "t1 - ����������� �� ���������, t2 - ����������� � ��������� �����������, t3 - ����������� ����������� �� t2\n";
	{
		Tank t1;
		Tank t2(90, 75);
		Tank t3(t2);
	}
	_getch();
	cout << "������ ������\n" << "����� ������ ����� ������ � �� ��� �������� ������ �������, ��������� �������� (90, 0)\n";
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
	cout << "������������/����������� ������ � �������������(������� �����������)\n";
	{
		ColoredTank* t1 = new ColoredTank;
		ColoredTank* t2 = new ColoredTank(90, 75, 1);
		ColoredTank* t3 = new ColoredTank(*t2);
		delete t1;
		delete t2;
		delete t3;
	}
	_getch();
	cout << "������������/����������� ������ � �����������(������� �����������)\n";
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
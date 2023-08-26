#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
using namespace std;

struct san
{
	string name;
	string place;
	string prof;
	unsigned col;
};

void input(san* p, int n);
void output(san* p, int n);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите количество путевок" << endl;
	cin >> n;
	san* p = new san[n];
	input(p,n);
	output(p, n);
}

void input(san* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Введите название санатория,его расположение,профиль,кол.путевок" << endl;
		cin >> (p+i)->name;
		cin >> (p + i)->place;
		cin >> (p + i)->prof;
		cin >> (p + i)->col;
	}
}

void output(san* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((p + i)->prof != (p + i + 1)->prof)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((p + i)->prof == (p + j)->prof)
				{
					swap(*(p + i + 1), *(p + j));
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((p + i)->prof == (p + j)->prof)
			{
				if ((p + i)->name > (p + j)->name)
				{
					swap(*(p + i), *(p + j));
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << (p + i)->name << " ";
		cout << (p + i)->place << " ";
		cout << (p + i)->prof << " ";
		cout << (p + i)->col << " ";
		cout << endl;
	}

	string temp;
	cout << "Введите расположение санатория" << endl;
	cin >> temp;
	for (int i = 0; i < n; i++)
	{
		if (temp == (p + i)->place)
		{
			cout << (p + i)->name << " ";
			cout << (p + i)->place << " ";
			cout << (p + i)->prof << " ";
			cout << (p + i)->col << " ";
			cout << endl;
		}
	}

}
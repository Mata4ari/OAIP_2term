#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct list {
	int key = NULL;
	list* next = nullptr;
};

struct cell {
	list* l = nullptr;
};

int has(int x, int SIZE)
{
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	return z;
}

void ins(string s, cell* A, int SIZE)
{
	int a = stoi(s);
	int n = has(a, SIZE);
	list* p = new(list);
	p->key =a;
	if (A[n].l == nullptr)
		A[n].l = p;
	else
	{
		list* t = A[n].l;
		while (t->next != nullptr)
			t = t->next;
		t->next = p;
	}
}

void print(cell* A, int SIZE)
{
	list* t;
	for (int i = 0; i < SIZE; i++)
	{
		if (A[i].l != nullptr)
		{
			t = A[i].l;
			while (t != nullptr)
			{
				cout << t->key  << "\t";
				t = t->next;
			}
			cout << endl;
		}
	}
}

void poshuk(int s, cell* A, int SIZE)
{
	
	int n = has(s, SIZE);
	list* t = A[n].l;
	while (t != nullptr)
	{
		if (t->key == s)
		{
			cout << t->key << endl;
			return;
		}
		t = t->next;
	}
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int SIZE;
	int x;
	string str;
	cin >> SIZE;
	cell* A = new cell[SIZE];
	ifstream f("A.txt");
	cin.ignore();
	while (getline(f, str))
	{
		ins(str, A, SIZE);
	}
	f.close();
	print(A, SIZE);
	cout << "¬ведите число дл€ поиска" << endl;
	cin >> x;
	poshuk(x, A, SIZE);
}
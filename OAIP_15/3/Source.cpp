#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct list {
	int key = NULL;
	string name;
	list* next = nullptr;
};

struct cell {
	list* l = nullptr;
};

int has(int x, int SIZE)
{
	return x%SIZE-1;
}

void ins(string s, cell* A, int SIZE)
{
	char a = s[0];
	int n = has((int)a, SIZE);
	list* p = new(list);
	p->key = (int)a;
	p->name = s;
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
				cout << t->key << " " << t->name << " " <<  "\t\t";
				t = t->next;
			}
			cout << endl;
		}
	}
}

void poshuk(string s, cell* A, int SIZE)
{
	char a = s[0];
	int n = has((int)a, SIZE);
	list* t = A[n].l;
	while (t != nullptr)
	{
		if (t->name == s)
		{
			cout << t->key << " " << t->name << endl;
			return;
		}
		t = t->next;
	}
}

void del(char a, cell* A, int SIZE)
{
	int n = has((int)a, SIZE);
	list* t = A[n].l;
	list* temp;
	while (t != nullptr)
	{
		temp = t;
		t = t->next;
		delete temp;
	}
	A[n].l = nullptr;
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int SIZE;
	string s;
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
	cout << "¬ведите слово дл€ поиска" << endl;
	cin >> s;
	poshuk(s, A, SIZE);
	char a;
	cout << "¬ведите букву дл€ удалени€ слов" << endl;
	cin >> a;
	del(a, A, SIZE);
	print(A, SIZE);
}
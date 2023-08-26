#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct list {
	int key = NULL;
	char name;
	int col=1;
	list* next = nullptr;
};

struct cell {
	list* l = nullptr;
};

int has(int x, int SIZE, cell* A)
{
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	return z;
}

void ins(int x, char a, cell* A, int SIZE)
{
	int n = has(x, SIZE, A);
	list* t=A[n].l;
	while (t != nullptr)
	{
		if (t->key == x)
		{
			t->col++;
			return;
		}
		t = t->next;
	}
	list* p = new(list);
	
	if (A[n].l == nullptr)
	{
		A[n].l = p;
		p->key = x;
		p->name = a;
	}
	else
	{
		t = A[n].l;
		while (t->next != nullptr)
			t = t->next;
		t->next = p;
		p->key = x;
		p->name = a;
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
				cout << t->key << " " << t->name << " " <<t->col<< "\t\t";
				t = t->next;
			}
			cout << endl;
		}
	}
}

list* has(int x, cell* A, int SIZE)
{
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	return A[z].l;
}


void poshuk(int x, cell* A, int SIZE)
{
	list* p = has(x, A, SIZE);
	if(p!=nullptr)
	{
		while (p != nullptr)
		{
			if (p->key == x)
				break;
			p = p->next;
		}
		cout << p->key << " " << p->name << " " << p->col << endl;
	}
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	srand(time(NULL));
	
	int SIZE;
	cin >> SIZE;
	string str;
	cin.ignore();
	getline(cin, str);
	cell* A = new cell[SIZE];
	char a;
	for (int i = 0; i < str.size(); i++)
	{
		a = str[i];
		ins((int)a, a, A, SIZE);
	}
	print(A, SIZE);
	cout << "¬ведите букву дл€ поиска" << endl;
	cin >> a;
	poshuk((int)a, A, SIZE);
}
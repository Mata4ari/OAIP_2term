#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct list {
	int key = NULL;
	string name;
	list* next=nullptr;
};

struct cell {
	list* l=nullptr;
};

int has(int x, int SIZE, cell* A)
{
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	if (A[z].l==nullptr)
		return z;
	else
	{
		return x * 13 % SIZE;
	}
}

void ins(int x, string str, cell* A, int SIZE)
{
	int n = has(x, SIZE, A);
	list* p = new(list);
	list* t;
	if(A[n].l==nullptr)
	{
		A[n].l = p;
		p->key = x;
		p->name = str;
	}
	else
	{
		t = A[n].l;
		while (t->next != nullptr)
			t = t->next;
		t->next = p;
		p->key = x;
		p->name = str;
	}
}

void print(cell* A, int SIZE)
{
	list* t;
	for (int i = 0; i < SIZE; i++)
	{
		if(A[i].l!=nullptr)
		{
			t = A[i].l;
			while (t != nullptr)
			{
				cout << t->key << " " << t->name << "\t";
				t = t->next;
			}
			cout << endl;
		}
	}
}

list* has2(int x, cell* A, int SIZE)
{
	list* t;
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	if (A[z].l->key == x)
	{
		t = A[z].l;
		return t;
	}
	else
	{
		z= x * 13 % SIZE;
		t = A[z].l;
		while (t != nullptr)
		{
			if (t->key == x)
				return t;
			t = t->next;
		}
	}
}

void del(int x, cell* A, int SIZE)
{
	list* t,*p;
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	if (A[z].l != nullptr)
	{
		if (A[z].l->key == x)
		{
			t = A[z].l;
			A[z].l = t->next;
			delete t;
			return;
		}
		t = A[z].l;
		p = t->next;
		while (p != nullptr)
		{
			if (p->key == x)
			{
				t->next = p->next;
				delete p;
				return;
			}
			t = p;
			p = p->next;
		}
	}
	z = x * 13 % SIZE;
	if(A[z].l!=nullptr)
	{
		if (A[z].l->key == x)
		{
			t = A[z].l;
			A[z].l = A[z].l->next;
			delete t;
			return;
		}
		t = A[z].l;
		p = t->next;
		while (p != nullptr)
		{
			if (p->key == x)
			{
				t->next = p->next;
				delete p;
				return;
			}
			t = p;
			p = p->next;
		}
	}
}

void poshuk(int x, cell* A, int SIZE)
{
	list* p = has2(x, A, SIZE);
	cout << p->key << " " << p->name << endl;
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	srand(time(NULL));
	int SIZE;
	cin >> SIZE;
	cell* A = new cell[SIZE];
	int x=-1;
	string str;
	while (x != 0)
	{
		cin >> x;
		if(x!=0)
		{
			cin.ignore();
			getline(cin, str);
			ins(x, str, A, SIZE);
			str.clear();
		}
	}
	print(A, SIZE);
	for(int i=0;i<3;i++)
	{
		cout << "Введите номер маршрута для поиска" << endl;
		cin >> x;
		clock_t start = clock();
		poshuk(x, A, SIZE);
		clock_t end = clock();
		cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "Введите номер для удаления" << endl;
		cin >> x;
		del(x, A, SIZE);
		print(A, SIZE);
	}

}
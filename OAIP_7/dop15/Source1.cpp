#include "Header.h"

void insert(list*& p, int val)
{
	list* newp = new list;
	newp->next = p;
	newp->number = val;
	p = newp;
}

void del(list*& p)
{
	list* temp;
	temp = p;
	p = p->next;
	delete temp;
}

void print(list*& p)
{
	list* ptr;
	ptr = p;
	cout << endl;
	if (ptr == nullptr)
		cout << "Стек пуст" << endl;
	while (ptr != nullptr)
	{
		cout << ptr->number << endl;
		ptr = ptr->next;
	}
	cout << endl;
}

list* clear(list*& p)
{
	list* temp;
	while (p != nullptr)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	return p;
}

void inp(list*& p)
{
	list* ptr = p;
	ofstream f1("A.txt");
	while (ptr != nullptr)
	{
		f1 << ptr->number;
		f1 << endl;
		ptr = ptr->next;
	}
	f1.close();
}

void outp(list*& p)
{
	p = clear(p);
	ifstream f2("A.txt");
	int A[100];
	string str;
	int count = 0;
	while (getline(f2, str))
	{
		A[count] = stoi(str);
		count++;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		list* newp = new list;
		newp->next = p;
		newp->number = A[i];
		p = newp;
	}
	f2.close();
}

void check(list*& p)
{
	list* ptr = p;
	list* temp;
	bool x=false;
	while (ptr != nullptr)
	{
		if (ptr->number == ptr->next->number)
		{
			temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
			x = true;
			break;
		}
		ptr = ptr->next;
	}
	if (x == false)
		cout << "Таких элементов нет" << endl;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int number;
	list* next;
};

void insert(list*& p, int val);
int del(list*& p,list&phead);
void print(list*& p, list& phead);
void search(list*& p, list& phead);
void inp(list*& p, list& phead);
void outp(list*& p, list& phead);
void check(list& phead);

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	list phead;
	list* p;
	p = &phead;
	phead.next = nullptr;

	int value;

	while (choice != 0)
	{
		cout << "1 - добавление " << endl;
		cout << "2 - удаление" << endl;
		cout << "3 - поиск" << endl;
		cout << "4 - вывод" << endl;
		cout << "5 - запись" << endl;
		cout << "6 - считывание" << endl;
		cout << "7 - найти сумму отрицательных двухзначных" << endl;
		cout << "0 - выход" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Введите число" << endl;
			cin >> value;
			insert(p, value);
		}
		if (choice == 2)
		{
			del(p,phead);
		}
		if (choice == 3)
			search(p,phead);
		if (choice == 4)
			print(p, phead);
		if (choice == 5)
			inp(p,phead);
		if (choice == 6)
			outp(p, phead);
		if (choice == 7)
			check(phead);
	}
}

void insert(list*& p, int val)
{
	list* newp = new list;
	p->number = val;
	p->next = newp;
	p = newp;
	p->next = nullptr;
}

int del(list*& p,list&phead)
{
	list* ptr,*temp;
	int num;
	cout << "Введите номер удаляемого элемента" << endl;
	cin >> num;
	ptr = &phead;
	if (num == 1)
	{
		ptr = ptr->next;
		phead.number = ptr->number;
		phead.next = ptr->next;
		delete ptr;
		return 0;
	}
	for (int i = 0; i < num-2; i++)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;

}

void print(list*& p, list& phead)
{
	p = &phead;
	if (p->next == nullptr)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p->next != nullptr)
		{
			cout << p->number<<"--> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

void search(list*&p,list& phead)
{
	p = &phead;
	int x,n=0;
	cout << "Введите значение" << endl;
	cin >> x;
	if (p->next == nullptr)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Элементы номер:" << endl;
		while (p->next != nullptr)
		{
			n++;
			if (p->number == x)
				cout << n << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void inp(list*& p, list& phead)
{
	p = &phead;
	ofstream f1 ("A.txt");
	if (p->next == nullptr)
		cout << "Список пуст" << endl;
	else
	{
		while (p->next != nullptr)
		{
			f1 << p->number;
			f1 << endl;
			p = p->next;
		}
	}
	f1.close();
}

void outp(list*& p, list& phead)
{
	list* temp;
	p = phead.next;
	while (p != nullptr)
	{
		temp = p->next;
		delete p;
		p = temp;
	}
	phead.next = nullptr;
	phead.number = NULL;
	p = &phead;

	ifstream f2("A.txt");
	string str;
	while (getline(f2, str))
	{
		list* newp = new list;
		p->number = stoi(str);
		p->next = newp;
		p = newp;
		p->next = nullptr;
	}
	f2.close();
}

void check(list& phead)
{
	list* ptr;
	ptr = &phead;
	int sum = 0;
	while (ptr->next!= nullptr)
	{
		if (ptr->number < -9)
			sum += ptr->number;
		ptr = ptr->next;
	}
	if (sum != 0)
		cout << "сумма = " << sum << endl;
	else
		cout << "Таких элементов нет" << endl;
}
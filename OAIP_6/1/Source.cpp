#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int number;
	list* next;
};

void insert(list*& p, int val);
void del(list*& p);
void print(list*& p);
void search(list*& p);
void inp(list*& p);
void outp(list*& p, list*& phead);
void check(list*& p);

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	list* phead = nullptr;
	list* p;
	p = phead;

	int value;

	while (choice != 0)
	{
		cout << "1 - добавление " << endl;
		cout << "2 - удаление" << endl;
		cout << "3 - поиск" << endl;
		cout << "4 - вывод" << endl;
		cout << "5 - запись" << endl;
		cout << "6 - считывание" << endl;
		cout << "7 - найти сумму положительных элементов" << endl;
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
			del(p);
		}
		if (choice == 3)
			search(p);
		if (choice == 4)
			print(p);
		if (choice == 5)
			inp(p);
		if (choice == 6)
			outp(p, phead);
		if (choice == 7)
			check(p);
	}
}

void insert(list*& p, int val)
{
	list* newp = new list;
	newp->next = p;
	newp->number = val;
	p = newp;
}

void print(list*& p)
{
	list* ptr;
	ptr = p;
	if (ptr == nullptr)
		cout << "Список пуст" << endl;
	else
	{
		while (ptr != nullptr)
		{
			cout << ptr->number << " --> ";
			ptr = ptr->next;
		}
		cout << "NULL" << endl;
	}
}

void del(list*& p)
{
	list* ptr;
	list* temp;
	ptr = p;
	int x;
	cout << "Введите номер удаляемого элемента:" << endl;
	cin >> x;

	if (x == 1)
	{
		p = p->next;
		delete ptr;
	}
	else
	{
		for (int i = 0; i < x - 2; i++)
		{
			ptr = ptr->next;
		}
		temp = ptr->next;
		ptr->next = ptr->next->next;
		delete temp;
	}
}

void search(list*& p)
{
	list* ptr;
	ptr = p;
	int x;
	int i = 0;
	cout << "Введите число" << endl;
	cin >> x;
	while (ptr != nullptr)
	{
		i++;
		if (ptr->number == x)
			cout << i << " ";
		ptr = ptr->next;
	}
	cout << ":Номера элементов" << endl;
}

void inp(list*& p)
{
	list* ptr;
	int i = 0;
	ptr = p;
	while (ptr != nullptr)
	{
		i++;
		ptr = ptr->next;
	}
	ptr = p;
	int* A = new int[i];
	i = 0;
	while (ptr != nullptr)
	{
		*(A + i) = ptr->number;
		ptr = ptr->next;
		i++;
	}
	ofstream f1("A.txt");
	for (i = i - 1; i >= 0; i--)
	{
		f1 << *(A + i);
		f1 << endl;
	}
	delete[]A;
	f1.close();
}

void outp(list*& p, list*& phead)
{
	list* temp;
	while (p != nullptr)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	ifstream f2("A.txt");
	string str;
	while (getline(f2, str))
	{
		list* newp = new list;
		newp->next = p;
		newp->number = stoi(str);
		p = newp;
	}
	f2.close();
}

void check(list*& p)
{
	list* ptr;
	ptr = p;
	int sum = 0;

	while (ptr != nullptr)
	{
		if (ptr->number > 0)
			sum += ptr->number;
		ptr = ptr->next;
	}

	if (sum == 0)
		cout << "Таких элементов нет" << endl;
	else
	{
		cout << "Сумма равна:" << sum << endl;
	}
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct node
{
	string name;
	string city;
	node* next;
	node* prev;
};

void add(node*&);
void print(node*& p);
void poshuk(node*& p);
void del(node*& p);
void fin(node*& p);
void fout(node*& p);
void clear(node*& p);
void count(node*& p);

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	node* p = nullptr;
	while (choice != 0)
	{
		cout << "1-Запись" << endl;
		cout << "2-Вывод" << endl;
		cout << "3-Поиск по мин" << endl;
		cout << "4-Удаление элемента" << endl;
		cout << "5-Запись в файл" << endl;
		cout << "6-Чтение из файла" << endl;
		cout << "7-Очистка" << endl;
		cout << "8-Подсчет длины" << endl;
		cin >> choice;
		if (choice == 1)
			add(p);
		if (choice == 2)
			print(p);
		if (choice == 3)
			poshuk(p);
		if (choice == 4)
			del(p);
		if (choice == 5)
			fin(p);
		if (choice == 6)
			fout(p);
		if (choice == 7)
			clear(p);
		if (choice == 8)
			count(p);
	}
}

void add(node*& p)
{
	node* newp = new(node);
	cout << "Введите имя " << endl;
	cin >> newp->name;
	cout << "Введите город " << endl;
	cin >> newp->city;
	if (p == nullptr)
	{
		newp->next = nullptr;
		newp->prev = nullptr;
	}
	else
	{
		p->next = newp;
		newp->prev = p;
		newp->next = nullptr;
	}
	p = newp;
}

void print(node*& p)
{
	node* ptr = p;
	while (ptr != nullptr)
	{
		cout << ptr->name << " " << ptr->city << endl;
		ptr = ptr->prev;
	}
}

void poshuk(node*& p)
{
	node* ptr = p;
	int x;
	string str;
	cout << "1- поиск по имени" << endl;
	cout << "2- поиск по городу" << endl;
	cin >> x;
	if (x == 1)
	{
		str = ptr->name;
		while (ptr != 0)
		{
			if (str > ptr->name)
				str = ptr->name;
			ptr = ptr->prev;
		}
	}
	if (x == 2)
	{
		str = ptr->city;
		while (ptr != 0)
		{
			if (str > ptr->city)
				str = ptr->city;
			ptr = ptr->prev;
		}
	}
	cout << "Минимальный элемент " << str << endl;
}

void del(node*& p)
{
	node* ptr = p;
	node* temp;
	string str;
	cout << "Введите имя удаляемого элемента" << endl;
	cin >> str;
	while (ptr != nullptr)
	{
		if (ptr->name == str)
		{
			if (ptr->prev == nullptr)
			{
				temp = ptr;
				ptr = ptr->next;
				ptr->prev = nullptr;
				delete temp;
				break;
			}
			if (ptr->next == nullptr)
			{
				temp = ptr;
				ptr = ptr->prev;
				p = ptr;
				ptr->next = nullptr;
				delete temp;
				break;
			}
			temp = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			delete temp;
			break;
		}
		ptr = ptr->prev;
	}
}

void fin(node*& p)
{
	node* ptr = p;
	ofstream f1("A.txt");

	while (ptr != nullptr)
	{
		f1 << ptr->name << " " << ptr->city << endl;
		ptr = ptr->prev;
	}

	f1.close();
}

void fout(node*& p)
{
	node* temp;
	string str, buf;
	while (p != nullptr)
	{
		temp = p;
		p = p->prev;
		delete temp;
	}

	ifstream f2 ("A.txt");
	while (getline(f2,str))
	{
		node* newp = new(node);
		for (int i = 0; i < str.size()+1; i++)
		{
			if (str[i] == ' ')
			{
				newp->name = buf;
				if (p == nullptr)
				{
					newp->next = nullptr;
					newp->prev = nullptr;
				}
				else
				{
					p->next = newp;
					newp->prev = p;
					newp->next = nullptr;
				}
				p = newp;
				buf.clear();
				continue;
			}

			if (str[i] == '\0')
			{
				newp->city = buf;
				buf.clear();
				continue;
			}
			buf += str[i];
		}
	}
	f2.close();
}

void clear(node*& p)
{
	node* temp;
	while (p != nullptr)
	{
		temp = p;
		p = p->prev;
		delete temp;
	}
}

void count(node*& p)
{
	node* ptr = p;
	int i = 0;
	while (ptr != nullptr)
	{
		i++;
		ptr = ptr->prev;
	}
	cout << i << endl;
}

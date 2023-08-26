#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct list
{
	string surname;
	string name;
	string otec;
	unsigned date;
	unsigned kurs;
	unsigned group;
	unsigned ocen[5];
	list* next;
	list* prev;
};

void insert(list*& p, string surn, string name, string ot, unsigned d, unsigned k, unsigned g);
void print(list*& p);

void main()
{
	list* p = nullptr;
	setlocale(LC_CTYPE, "ru");

	insert(p, "ivanov", "ivan", "ivanovich", 2000, 3, 5);
	insert(p, "abvge", "markiz", "markizovich", 2000, 2, 1);
	insert(p, "jenya", "petrov", "sashevich", 2001, 1, 3);
	insert(p, "gosha", "tkachev", "neznayu", 2002, 3, 5);
	insert(p, "yan", "ushakov", "evgenevich", 2002, 2, 2);
	insert(p, "maksim", "smirnov", "aleshavich", 2003, 1, 4);
	insert(p, "sasha", "aaaaa", "kristinavich", 2003, 3, 7);
	insert(p, "lexza", "kakoyto", "yaustal", 2004, 2, 8);
	insert(p, "anya", "kupala", "yanovna", 2004, 1, 3);

	print(p);
}

void insert(list*& p,string surn,string name,string ot,unsigned d,unsigned k,unsigned g)
{
	list* newp = new(list);
	newp->surname=surn;
	newp->name = name;
	newp->otec = ot;
	newp->date = d;
	newp->kurs = k;
	newp->group = g;
	for (int i = 0; i < 5; i++)
		newp->ocen[i] = rand() % 1 - 5;
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

void print(list*& p)
{
	list* ptr = p;
	list* p1;
	

	while (ptr != nullptr)
	{
		p1 = ptr;
		while (p1 != nullptr)
		{
			if (ptr->kurs > p1->kurs)
			{
				if (ptr == p)
					p = p1;
				swap(ptr->surname,p1->surname);
				swap(ptr->name,p1->name);
				swap(ptr->otec,p1->otec);
				swap(ptr->date,p1->date);
				swap(ptr->group,p1->date);
				swap(ptr->kurs,p1->kurs);
				swap(ptr->next,p1->next);
				swap(ptr->prev,p1->prev);
				swap(ptr, p1);
				for (int i = 0; i < 5; i++)
				{
					swap(ptr->ocen[i], p1->ocen[i]);
				}
			}
			p1 = p1->prev;
		}
		ptr = ptr->prev;
	}
	
	ptr = p;
	

	ptr = p;
	while (ptr != nullptr)
	{
		cout << ptr->surname << endl;
		cout << ptr->name << endl;
		cout << ptr->otec << endl;
		cout << ptr->date << endl;
		cout << ptr->kurs << endl;
		cout << ptr->group << endl;
		for (int i = 0; i < 5; i++)
			cout << ptr->ocen[i] << " ";
		cout << endl;
		ptr = ptr->prev;
	}
}
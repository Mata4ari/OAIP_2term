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
void sred(list*& p);
void dat(list*& p);
void best(list*& p);

void main()
{
	list* p = nullptr;
	setlocale(LC_CTYPE, "ru");

	insert(p, "ivanov", "ivan", "ivanovich", 2000, 3, 3);
	insert(p, "abvge", "markiz", "markizovich", 2000, 2, 2);
	insert(p, "jenya", "petrov", "sashevich", 2001, 1, 3);
	insert(p, "gosha", "tkachev", "neznayu", 2002, 3, 1);
	insert(p, "yan", "ushakov", "evgenevich", 2002, 2, 1);
	insert(p, "maksim", "smirnov", "aleshavich", 2003, 1, 3);
	insert(p, "sasha", "aaaaa", "kristinavich", 2003, 3, 2);
	insert(p, "lexza", "kakoyto", "yaustal", 2004, 2, 1);
	insert(p, "anya", "kupala", "yanovna", 2004, 1, 2);

	print(p);
	sred(p);
	dat(p);
	best(p);
}

void insert(list*& p, string surn, string name, string ot, unsigned d, unsigned k, unsigned g)
{
	list* newp = new(list);
	newp->surname = surn;
	newp->name = name;
	newp->otec = ot;
	newp->date = d;
	newp->kurs = k;
	newp->group = g;
	for (int i = 0; i < 5; i++)
		newp->ocen[i] = rand() % 5+2;
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

	ptr = p;

	while (ptr != nullptr)
	{
		p1 = ptr;
		while (p1 != nullptr)
		{
			if (ptr->kurs > p1->kurs)
			{
				swap(ptr->surname, p1->surname);
				swap(ptr->name, p1->name);
				swap(ptr->otec, p1->otec);
				swap(ptr->date, p1->date);
				swap(ptr->group, p1->group);
				swap(ptr->kurs, p1->kurs);
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

	while (ptr != nullptr)
	{
		p1 = p;
		while (p1 != nullptr)
		{
			if (ptr->kurs == p1->kurs && ptr->surname < p1->surname)
			{
				swap(ptr->surname, p1->surname);
				swap(ptr->name, p1->name);
				swap(ptr->otec, p1->otec);
				swap(ptr->date, p1->date);
				swap(ptr->group, p1->group);
				swap(ptr->kurs, p1->kurs);
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
	cout << endl << endl;
}

void sred(list*& p)
{
	list* ptr = p;
	double s1 = 0,s2=0,s3=0;
	int c1 = 0, c2=0, c3 = 0;

	for (int i = 0; i < 5; i++)
	{
		ptr = p;
		while (ptr != nullptr)
		{
			if (ptr->group == 1)
			{
				c1++;
				s1 += ptr->ocen[i];
			}
			if (ptr->group == 2)
			{
				c2++;
				s2 += ptr->ocen[i];
			}
			if (ptr->group == 3)
			{
				c3++;
				s3 += ptr->ocen[i];
			}
			ptr = ptr->prev;
		}
		cout << s1 / c1 << "\t" << s2 / c2 << "\t" << s3 / c3 << endl;
	}
	cout << endl << endl;
}

void dat(list*& p)
{
	list* ptr = p;
	unsigned min, max;
	int c1 = 1, c2 = 1;
	min = p->date;
	max = p->date;
	int i = 0;

	while (ptr != nullptr)
	{
		i++;
		if (min < ptr->date)
		{
			min = ptr->date;
			c1 = i;
		}
		if (max > ptr->date)
		{
			max = ptr->date;
			c2 = i;
		}
		ptr = ptr->prev;
	}
	cout << "Старший:N" << c2 << endl;
	cout << "Младший:N" << c1 << endl << endl;
}

void best(list*& p)
{
	list* ptr = p;
	int sum = 0, res1 = 0,res2=0,res3=0,k=0;
	string b1, b2, b3;

	while (ptr != nullptr)
	{
		for (int i = 0; i < 5; i++)
			sum += ptr->ocen[i];
		if (ptr->group == 1)
		{
			if (sum > res1)
			{
				res1 = sum;
				b1 = ptr->name;
			}
		}
		if (ptr->group == 2)
		{
			if (sum > res2)
			{
				res2 = sum;
				b2 = ptr->name;
			}
		}
		if (ptr->group == 3)
		{
			if (sum > res3)
			{
				res3 = sum;
				b3 = ptr->name;
			}
		}
		ptr = ptr->prev;
		sum = 0;
	}
	cout << b1 << "\t" << b2 << "\t" << b3;
}

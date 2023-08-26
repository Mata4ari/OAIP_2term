#include <iostream>
using namespace std;

struct list
{
	string name;
	list* next;
	list* prev;
};

void postroenie(list*& p,list*&ptr);
void outp(list*& p, list*& ptr,int);

void main()
{
	setlocale(LC_CTYPE, "ru");
	list* p=nullptr;
	list* ptr;
	int k;
	postroenie(p,ptr);
	cout << "¬ведите k:" << endl;
	cin >> k;
	outp(p, ptr,k);
}

void postroenie(list*& p,list*& ptr)
{
	string str[] = { "perviy","vtoroy","tretiy","chetiri","five","six","seven","vosem","nine","ten" };
	list* newp = new(list);
	p = newp;
	newp->name = str[0];
	ptr = newp;
	for (int i = 1; i < 10; i++)
	{
		list* newp = new(list);
		newp->name = str[i];
		newp->prev = ptr;
		ptr->next = newp;
		ptr = newp;
	}
	ptr->next = p;
	p->prev = ptr;
}

void outp(list*& p, list*& ptr,int k)
{
	list* t = p;
	int i = 0;
	list* temp,*p1;
	bool x = false;
	while (true)
	{
		i++;
		if (t == ptr)
		{
			x = true;
		}
		if (i % k == 0)
		{
			if (t == ptr)
			{
				x = true;
				ptr = ptr->next;
			}
			temp = t;
			t->prev->next = t->next;
			t->next->prev = t->prev;
			delete temp;
		}
		cout << t->name << "\t";
		if (x == true)
		{
			cout << endl;
			x = false;
		}
		if (t->next == t)
			break;
		t = t->next;
	}
}
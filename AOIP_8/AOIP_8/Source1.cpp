#include "Header.h"

void insert(list*& p, int val)
{
	list* newp = new list;
	newp->num = val;
	newp->next = p;
	p = newp;
}

void print(list*& p)
{
	list* ptr = p;
	cout << endl;
	cout << "------INPUT-------" << endl;
	while (ptr != nullptr)
	{
		cout << ptr->num << endl;
		ptr = ptr->next;
	}
	cout << "------OUTPUT-------";
	cout << endl;
}

void del(list*& p)
{
	list* ptr = p;
	list* temp;
	while (ptr->next->next != nullptr)
	{
		ptr = ptr->next;
	}
	cout << endl;
	cout << "Из очереди вышел элемент " << ptr->next->num << endl;
	temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
}

void clear(list*& p)
{
	list* temp;
	while (p != nullptr)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}

void length(list*& p)
{
	list* ptr = p;
	int count = 0;
	while (ptr != nullptr)
	{
		count++;
		ptr = ptr->next;
	}
	cout << endl << "Длина очереди " << count << endl;
}

void check(list*& p)
{
	list* ptr = p;
	int max;
	cout << endl;
	while (ptr->num != 0)
	{
		cout << ptr->num << endl;;
		ptr = ptr->next;
	}
	cout << ptr->num << endl;
	ptr = ptr->next;
	length(ptr);
	ptr = p;
	if (ptr != nullptr)
		max = ptr->num;
	while (ptr != nullptr)
	{
		if (max < ptr->num)
		{
			max = ptr->num;
		}
		ptr = ptr->next;
	}
	cout << "Максимальный элемент " << max << endl;
}
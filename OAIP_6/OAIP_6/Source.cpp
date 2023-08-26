#include <iostream>
using namespace std;

struct list {
	int number;
	list* next;
};

void insert(list*& p, int val);
void del(list*& p);
void print(list*& p, list* phead);

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice=-1;
	list* p, * phead;
	phead = p;
	p = nullptr;

	int value;

	while (choice != 0)
	{
		cout << "1 - ���������� " << endl;
		cout << "2 - ��������" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - �����" << endl;
		cout << "5 - ������" << endl;
		cout << "6 - ����������" << endl;
		cout << "0 - �����" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "������� �����" << endl;
			cin >> value;
			insert(p,value);
		}
		if (choice == 2)
		{
			del(p);
		}
		if (choice == 4)
			print(p,phead);
	}
}

void insert(list*& p, int val)
{
	list* newp = new list;
	p = newp;
	p->number = val;
	p->next = nullptr;
}

void del(list*& p)
{
	int num;
	cout << "������� ����� ���������� ��������" << endl;
	cin >> num;
	num--;

}

void print(list*& p,list* phead)
{
	p = phead;
	if (p == nullptr)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p->next != nullptr)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}

}
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct abitur
{
	string name;
	string spec1;
	string spec2;
	string spec3;
	unsigned kon[3];
	unsigned cost;
};

union un1
{
	abitur abit;
};

void input(abitur* a, int& count);
void output(abitur* a, int& count);
void search(abitur* a, int& count);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	abitur a[10];
	int count = 0;
	int choice = -1;
	while (choice != 0)
	{
		cout << "1.���� ������ � ����������" << endl;
		cout << "2.����� ������ � �������" << endl;
		cout << "3.����� �� ��������" << endl;
		cout << "0.����� �� ���������" << endl;
		cout << "������� ����� ��������: " << endl;
		cin >> choice;
		if (choice == 1)
			input(a,count);
		if (choice == 2)
			output(a, count);
		if (choice == 3)
			search(a, count);
	}
}

void input(abitur* a, int& count)
{
	int x = 1;
	while (x != 0)
	{
		cout << "1.������ ������ ���" << endl;
		cout << "0.���������" << endl;
		cin >> x;
		if (x != 0)
		{
			cin.ignore();
			cout << "������� �������� ����" << endl;
			getline(cin,a.[count].name);
			cout << "������� �������� �������������" << endl;
			cin >> a[count].spec1;
			cout << "������� �������� �������������" << endl;
			cin >> a[count].spec2;
			cout << "������� �������� �������������" << endl;
			cin >> a[count].spec3;
			cout << "������� ������� �� ��������������" << endl;
			cin >> a[count].kon[0];
			cin >> a[count].kon[1];
			cin >> a[count].kon[2];
			cout << "������� ���� �� ��������" << endl;
			cin >> a[count].cost;
			count++;
		}
	}
}

void output(abitur* a, int& count)
{
	for (int i = 0; i < count; i++)
	{
		cout << a[i].name << endl;
		cout << a[i].spec1 << endl;
		cout << a[i].kon[0] << endl;
		cout << a[i].spec2 << endl;
		cout << a[i].kon[1] << endl;
		cout << a[i].spec3 << endl;
		cout << a[i].kon[2] << endl;
		cout << a[i].cost << endl;
		cout << endl;
	}
}

void search(abitur* a, int& count)
{
	int min = a[0].kon[0];
	for (int i = 0; i < count; i++)
	{
		if (a[i].kon[0] < min)
			min = a[i].kon[0];
		if (a[i].kon[1] < min)
			min = a[i].kon[1];
		if (a[i].kon[2] < min)
			min = a[i].kon[2];
	}
	cout << "����������� �������" << min << endl;
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct stock
{
	string name;
	int cost;
	int kol;
	int per;
};

void input(stock* stockes, int& count);
void output(stock* stockes, int& count);
void del(stock* stockes, int& count, int x);
void search(stock* stockes, int& count);
void fin(stock* stockes, int& count);
void fout(stock* stockes, int& count);

void main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 1;
	stock stockes[10];
	int count = 0;

	while (choice != 0)
	{
		cout << "1.Ввод данных с клавиатуры" << endl;
		cout << "2.Вывод данных в консоль" << endl;
		cout << "3.Удаление заданной переменной" << endl;
		cout << "4.Поиск по цене" << endl;
		cout << "5.Запись данных в файл" << endl;
		cout << "6.Чтение данных из файла" << endl;
		cout << "0.Выход из программы" << endl;
		cout << "Введите номер операции: " << endl;
		cin >> choice;

		if (choice == 1)
		{
			input(stockes, count);
		}
		if (choice == 2)
		{
			output(stockes, count);
		}
		if (choice == 3)
		{
			int x;
			cout << "Введите номер товара в списке который нужно удалить" << endl;
			cin >> x;
			del(stockes, count, x);
		}
		if (choice == 4)
		{
			search(stockes, count);
		}
		if (choice == 5)
		{
			fin(stockes, count);
		}
		if (choice == 6)
		{
			fout(stockes, count);
		}
	}
}

void input(stock* stockes, int& count)
{
	int x = 1;
	while (x != 0)
	{
		cout << "1.Ввести новый товар" << endl;
		cout << "0.Закончить" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "Введите название товара" << endl;
			cin >> stockes[count].name;
			cout << "Введите цену" << endl;
			cin >> stockes[count].cost;
			cout << "Введите количетсво товара" << endl;
			cin >> stockes[count].kol;
			cout << "Введите процент торговой надбавки" << endl;
			cin >> stockes[count].per;
			count++;
		}
	}
}

void output(stock* stockes, int& count)
{
	for (int i = 0; i < count; i++)
	{
		cout << stockes[i].name << endl;
		cout << stockes[i].cost << endl;
		cout << stockes[i].kol << endl;
		cout << stockes[i].per << endl;
		cout << endl;
	}
}

void del(stock* stockes, int& count, int x)
{
	for (int i = x; i < count; i++)
	{
		stockes[i].name = stockes[i + 1].name;
		stockes[i].cost = stockes[i + 1].cost;
		stockes[i].kol = stockes[i + 1].kol;
		stockes[i].per = stockes[i + 1].per;
	}
	count--;
}

void search(stock* stockes, int& count)
{
	int x;
	cout << "Введите цену" << endl;
	cin >> x;
	for (int i = 0; i < count; i++)
	{
		if (stockes[i].cost == x)
		{
			cout << stockes[i].name << endl;
			cout << stockes[i].cost << endl;
			cout << stockes[i].kol << endl;
			cout << stockes[i].per << endl;
			cout << endl;
		}
	}
}

void fin(stock* stockes, int& count)
{
	ofstream f1("A.txt");
	for (int i = 0; i < count; i++)
	{
		f1 << stockes[i].name;
		f1 << "\n";
		f1 << stockes[i].cost;
		f1 << "\n";
		f1 << stockes[i].kol;
		f1 << "\n";
		f1 << stockes[i].per;
		f1 << "\n";
	}
	f1.close();
}

void fout(stock* stockes, int& count)
{
	ifstream f2("A.txt");
	int n = 0;
	string str, temp;
	while (getline(f2, str))
	{

		n++;
	}
	f2.close();
	n = n / 4;
	count = n;
	ifstream f3("A.txt");
	for (int i = 0; i < n; i++)
	{

		getline(f3, str);
		stockes[i].name = str;
		getline(f3, str);
		stockes[i].cost = stoi(str);
		getline(f3, str);
		stockes[i].kol = stoi(str);
		getline(f3, str);
		stockes[i].per = stoi(str);
		

	}
	f3.close();
}
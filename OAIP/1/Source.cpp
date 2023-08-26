#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct cell {
	int key = NULL;
	string name;
	bool b = 0;
};

int has(int x, int SIZE, cell* A)
{
	int i = 0;
	int n = x % SIZE;
	while (A[n].key != NULL)
	{
		A[n].b = 1;
		i++;
		n = (n + i + i * i) % SIZE;
	}
	return n;
}

int has2(int x, int SIZE, cell* A)
{
	cout << endl;
	int i = 0;
	int n = x % SIZE;
	while (A[n].b != 0)
	{
		if (A[n].key == x)
			return n;
		else
		{
			if(A[n].key!=NULL)
			{
				cout << A[n].key << " " << A[n].name << endl;
			}
			i++;
			n = (n + i + i * i) % SIZE;
		}
	}
	if (A[n].key == x)
		return n;
}

void ins(int x, string str, cell* A, int SIZE)
{
	int n = has(x, SIZE, A);
	A[n].key = x;
	A[n].name = str;
}

void build(cell* A, int SIZE)
{
	int x;
	string str;
	for (int i = 0; i < SIZE / 2; i++)
	{
		x = rand() % 1000 + 1;
		str += "user";
		str += to_string(i);
		ins(x, str, A, SIZE);
		str.clear();
	}
}

void print(cell* A, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (A[i].key != NULL)
		{
			cout << A[i].key << " " << A[i].name << endl;
		}
	}
}

void del(int x, cell* A, int SIZE)
{
	int n = has2(x, SIZE, A);
	A[n].key = NULL;
	A[n].name.clear();
}

void poshuk(int x, cell* A, int SIZE)
{
	int n = has2(x, SIZE, A);
	cout << A[n].key << " " << A[n].name << endl;
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	srand(time(NULL));
	int SIZE;
	cin >> SIZE;
	cell* A = new cell[SIZE];
	build(A, SIZE);
	print(A, SIZE);
	cout << "Введите новый элемент" << endl;
	int x;
	string str;
	cin >> x;
	cin.ignore();
	getline(cin, str);
	ins(x, str, A, SIZE);
	print(A, SIZE);
	cout << "Введите ключ для удаления" << endl;
	cin >> x;
	del(x, A, SIZE);
	cout << endl;
	print(A, SIZE);
	cout << "Введите ключ для поиска" << endl;
	cin >> x;
	clock_t start = clock();
	poshuk(x, A, SIZE);
	clock_t end = clock();
	cout << endl << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
}
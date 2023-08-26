#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct cell{
	int key=NULL;
	string name;
	bool b=0;
};

int has(int x, int SIZE, cell* A)
{
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	if (A[z].key == NULL)
		return z;
	else
	{
		A[z].b = 1;
		return x * 13 % SIZE;
	}
}

int has2(int x, int SIZE, cell* A)
{
	double n = x * 0.43;
	int y = x * 0.43;
	n = (n - y) * SIZE;
	int z = (int)n;
	int l;
	if (A[z].key == x)
	{
		return z;
	}
	else
	{
		l= x * 13 % SIZE;
		if (A[l].key == x)
			return l;
	}
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
		x = rand() % 100 + 1;
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
	int n = has2(x,SIZE,A);
	A[n].key = NULL;
	A[n].name.clear();
}

void poshuk(int x, cell* A, int SIZE)
{
	int n = has2(x, SIZE, A);
	cout << A[n].key << " " << A[n].name << endl;
}

void poisk(int x, cell* A, int SIZE)
{
	int i = 0,k=0;
	while (true)
	{
		if (A[k].key != NULL)
			i++;
		if(i==x)
		{
			cout << A[k].key << " " << A[k].name << endl;
			break;
		}
		k++;
		if (k > SIZE)
			break;
	}
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
	cout << "¬ведите новый элемент" << endl;
	int x;
	string str;
	cin >> x;
	cin.ignore();
	getline(cin, str);
	ins(x, str, A, SIZE);
	print(A, SIZE);
	cout << "¬ведите ключ дл€ удалени€" << endl;
	cin >> x;
	del(x, A, SIZE);
	print(A, SIZE);
	cout << "¬ведите ключ дл€ поиска" << endl;
	cin >> x;
	clock_t start = clock();
	poshuk(x, A, SIZE);
	clock_t end = clock();
	cout << endl << "¬рем€ выполнени€: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	cout << "¬ведите пор€дковый номер в таблице" << endl;
	cin >> x;
	poisk(x, A, SIZE);
}
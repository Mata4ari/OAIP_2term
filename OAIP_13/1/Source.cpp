#include <iostream>
using namespace std;



void build()
{
	int n, x;
	cout << "¬ведите количество элементов" << endl;
	cin >> n;
	int*heap = new int[10];
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		heap[i] = x;
		if (i > 0 && heap[i] > heap[i - 1])
			for (int j = i; j > 0; j--)
				if (heap[j] > heap[j - 1])
					swap(heap[j], heap[j - 1]);
	}
	cout << sizeof(heap) / sizeof(int) << endl;
	for (int i = 0; i <  n; i++)
		cout << heap[i] << " ";
}

void print()
{
	
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	while (true)
	{
		cout << "1-построение" << endl;
		cout << "2-вывод" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		if (choice == 1)
			build();
		if (choice == 2)
			print();
	}
}
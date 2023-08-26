#include <iostream>
using namespace std;


void build(int*&heap)
{
	int n,x;
	cout << "¬ведите количество элементов" << endl;
	cin >> n;
	heap = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		heap[i] = x;
		if (i > 0 && heap[i] > heap[i - 1])
			for (int j = i; j > 0; j--)
				if (heap[j] > heap[j - 1])
					swap(heap[j], heap[j - 1]);
	}
}

void print(int*&heap)
{
	cout << sizeof(heap)/ sizeof(int) << endl;
	for (int i = 0; i < sizeof(heap)/sizeof(int) - 1; i++)
		cout << heap[i] << " ";
	cout << endl;
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	int* heap = nullptr;
	while (true)
	{
		cout << "1-построение" << endl;
		cout << "2-вывод" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		if (choice == 1)
			build(heap);
		if (choice == 2)
			print(heap);
	}
}
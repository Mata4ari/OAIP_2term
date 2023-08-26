#include <iostream>
#include <vector>
using namespace std;

void ins(vector<int>& heap)
{
	int x;
	cout << "¬ведите элемент" << endl;
	cin >> x;
	heap.push_back(x);
	if (heap.size() > 1)
	{
		for (int i = 0; i < heap.size(); i++)
			for (int j = i; j > 0; j--)
				if (heap[j] > heap[j - 1])
					swap(heap[j], heap[j - 1]);
	}
}

void print(vector<int>& heap)
{
	for (int i = 0; i < heap.size(); i++)
		cout << heap[i] << " ";
	cout << endl;
}

void delmax(vector<int>& heap)
{
	heap.erase(heap.begin());
}

void delmin(vector<int>& heap)
{
	heap.pop_back();
}

void del(vector<int>& heap)
{
	int n;
	cout << "¬ведите номер" << endl;
	cin >> n;
	heap.erase(heap.begin() + n);
}

void uni(vector<int>& heap, vector<int>& A)
{
	int x;
	for (int i = 0; i < A.size(); i++)
	{
		heap.push_back(A[i]);
	}
	for (int i = 0; i < heap.size(); i++)
		for (int j = i; j > 0; j--)
			if (heap[j] > heap[j - 1])
				swap(heap[j], heap[j - 1]);
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	vector<int> heap;
	vector<int>A = { 5,4,3,2 };

	while (true)
	{
		cout << "1-ввод элемента" << endl;
		cout << "2-вывод" << endl;
		cout << "3-удаление максимального" << endl;
		cout << "4-удаление минимального" << endl;
		cout << "5-удаление итого" << endl;
		cout << "6-объединение куч" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		if (choice == 1)
			ins(heap);
		if (choice == 2)
			print(heap);
		if (choice == 3)
			delmax(heap);
		if (choice == 4)
			delmin(heap);
		if (choice == 5)
			del(heap);
		if (choice == 6)
			uni(heap, A);
	}
}
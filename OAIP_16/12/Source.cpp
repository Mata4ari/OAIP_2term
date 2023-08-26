#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

void buble(int B[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (*(B + j) > *(B + j + 1))
				swap(*(B + j), *(B + j + 1));

	for (int i = 0; i < n; i++)
		cout << B[i] << " ";
	cout << endl << endl;
}

void vibor(int* A, int n)
{
	int min, num;
	for (int i = 0; i < n; i++)
	{
		min = A[i];
		num = i;
		for (int k = i + 1; k < n; k++)
		{
			if (A[k] < min)
			{
				min = A[k];
				num = k;
			}
		}
		swap(A[i], A[num]);
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl << endl;
}

void main()
{
	srand((unsigned int)time(NULL));
	setlocale(LC_CTYPE, "ru");
	int n;
	cout << "Введите n" << endl;
	cin >> n;
	int* A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % 100 - 50;
	int y = 0;
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			y++;
	int* B = new int[y];
	int* C = new int[y];
	y = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			B[y] = A[i];
			C[y] = A[i];
			y++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl << endl;
	clock_t start = clock();
	buble(B, y);
	clock_t end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	start = clock();
	vibor(C, y);
	end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;

}
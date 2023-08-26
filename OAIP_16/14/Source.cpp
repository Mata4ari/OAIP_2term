#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

void buble(int B[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (*(B + j) < *(B + j + 1))
				swap(*(B + j), *(B + j + 1));

	for (int i = 0; i < n; i++)
		cout << B[i] << " ";
	cout << endl << endl;
}

void shell(int B[], int n)
{
	int j, i, d = n;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && B[j] < B[j + d])
			{
				std::swap(B[j], B[j + d]);
				j--;
			}
		}
		d = d / 2;
	}

	for (int i = 0; i < n; i++)
		cout << B[i] << " ";
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
	int* Z = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 - 50;
		Z[i] = rand() % 100 - 50;
	}
	int y = 0, l = 0;
	for (int i = 0; i < n; i++)
		if (A[i] % 2 == 0)
			y++;
	for (int i = 0; i < n; i++)
		if (Z[i] % 2 != 0)
			y++;
	int* B = new int[y];
	int* C = new int[y];
	y = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] % 2 == 0)
		{
			B[y] = A[i];
			C[y] = A[i];
			y++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (Z[i] % 2 != 0)
		{
			B[y] = Z[i];
			C[y] = Z[i];
			y++;
		}
	}

	for (int i = 0; i < y; i++)
		cout << B[i] << " ";
	cout << endl << endl;
	clock_t start = clock();
	buble(B, y);
	clock_t end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	start = clock();
	shell(C, y);
	end = clock();
	cout << "Время выполнения: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;

}
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

void shell(int B[], int n)
{
	int j, i, d = n;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && B[j] > B[j + d])
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
	cout << "������� n" << endl;
	cin >> n;
	int* A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % 100 - 50;
	int y = 0;
	for (int i = 0; i < n; i++)
		if (A[i] % 2 == 0)
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
		cout << A[i] << " ";
	cout << endl << endl;
	clock_t start = clock();
	shell(B, y);
	clock_t end = clock();
	cout << "����� ����������: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	start = clock();
	vibor(C, y);
	 end = clock();
	cout << "����� ����������: " << (double)((double)end - (double)start) / CLOCKS_PER_SEC << endl;

}
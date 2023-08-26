#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "ru");
	int n;
	cout << "size ocheredi" << endl;
	cin >> n;
	double* A = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент" << endl;
		cin >> A[i];
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << "\t";
	cout << endl;
	int nom=0;
	double  max;
	max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (max < A[i])
		{
			max = A[i];
			nom = i;
		}
	}

	double buff;
	for (int i = 0; i < nom; i++)
	{
		buff = A[0];
		for (int k = 1; k < n; k++)
		{
			A[k-1] = A[k];
		}
		A[n-1] = buff;
	}
	for (int i = 0; i < n; i++)
		cout << A[i] << "\t";
	cout << endl;
}

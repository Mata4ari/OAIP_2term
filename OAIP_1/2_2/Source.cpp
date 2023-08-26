#include <iostream>
using namespace std;
int fsum(int n, ...);

void main()
{
	cout << fsum(3, 5, 6, 1) << endl;
	cout << fsum(4, 2, 6, 1,3) << endl;
	cout << fsum(5, 1, 6, 7,2,3) << endl;
}

int fsum(int n, ...)
{
	int* p = &n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *p * *(p + 2);
		p += 2;
	}
	return sum;
}
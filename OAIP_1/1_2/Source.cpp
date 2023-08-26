#include <iostream>
using namespace std;
int fmin(int,...);

void main()
{
	cout << fmin(3, 5, 7, 5) << endl;
	cout << fmin(2, 4, 5)<<endl;
	cout << fmin(4,11,22,43,1);
}

int fmin(int n,...)
{
	int min;
	int* p = &n;
	min = *p;
	for (int i = 0; i < n; i++)
	{
		if (min > *(p + 2))
			min = *(p + 2);
		p += 2;
	}
	return min;
}
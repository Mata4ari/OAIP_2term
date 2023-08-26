#include <iostream>
using namespace std;
int kvadr(int n, ...);

void main()
{
	cout << kvadr(4,2,3,4,9) << endl;
	cout << kvadr(6,4,9,9,7,16,4) << endl;
	cout << kvadr(7,13,7,7,8,16,25,27) << endl;
}

int kvadr(int n, ...)
{
	int* p = &n;
	int a=0;
	double x;
	for (int i = 0; i <= n; i++)
	{
		x = sqrt(*p);
		if (x == (int)x)
			a++;
		x = 0;
		p += 2;
	}
	return a;
}
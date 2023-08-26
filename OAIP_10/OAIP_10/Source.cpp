#include <iostream>
using namespace std;

double A(int m, int n)
{
	if (m == 0)
		return (n + 1);
	if (m > 0 && n > 0)
		return (A(m-1, n-1));
	if (m > 0)
		return (A(m-1, 0));
}

void main()
{
	unsigned m, n;
	cin >> m;
	cin >> n;
	cout<<A(m, n);
}

#include <iostream>
using namespace std;
int as(int,...);

void main()
{
	cout << as(2,4,5) << endl;
	cout << as(4,1,5,3,8) << endl;
	cout << as(3,5,9,8) << endl;
}

int as(int n,...)
{
	int* p = &n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(i==0||i%2==0)
			sum += *p * *(p + 2);
		else
			sum -= *p * *(p + 2);
		p+=2;
	}
	return sum;
}
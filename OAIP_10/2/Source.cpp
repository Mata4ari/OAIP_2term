#include <iostream>
using namespace std;

double f(double x)
{
	return x*x*x+x-4;
}

double dicho(double a,double b,double e)
{
	double x = (a + b) / 2;
	if (f(x) * f(a) <= 0)
		b = x;
	else
		a = x;
	if (abs(a - b) > 2 * e)
		dicho(a, b, e);
	else
		return x;
}

void main()
{
	double f, a, b, e = 0.0001;
	
	cin >> a;
	cin >> b;
	cout << dicho(a,b,e);
}
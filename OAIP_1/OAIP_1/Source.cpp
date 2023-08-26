#include <iostream>
using namespace std;
double fun(double a, double b, double e);
double fun1(double a, double b, double e);
double ur(double x);
double ur1(double x);

double fun(double a, double b,double e)
{
	while (true)
	{

		double x;
		x = (a + b) / 2;
		double (*p)(double);
		p = ur;
		if (p(x) * p(a) <= 0)
			b = x;
		else
			a = x;
		if (abs(a - b) < 2 * e)
			return (x);
	}
}
double fun1(double a, double b, double e)
{
	while (true)
	{

		double x;
		x = (a + b) / 2;
		double (*p1)(double);
		p1 = ur1;
		if (p1(x) * p1(a) <= 0)
			b = x;
		else
			a = x;
		if (abs(a - b) < 2 * e)
			return (x);
	}
}

double ur(double x)
{
	return (2 - x * x + x);
}

double ur1(double x)
{
	return (sin(x)*sin(x)+0.2);
}

void main()
{
	double e = 0.001, a, b;
	cin >> a;
	cin >> b;
	
	double (*f1)(double, double, double);
	f1 = fun1;
	
	cout << f1(a, b, e);
}
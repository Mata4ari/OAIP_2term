#include <iostream>
using namespace std;
double fun(double a, double b, double e, double(*f)(double));
double ur1(double x);
double ur2(double x);
double ur3(double x);
double ur4(double x);
double ur5(double x);
double ur6(double x);

void main()
{
	double a, b, e = 0.001;
	cin >> a;
	cin >> b;
	cout << "N1" << endl;
	cout << fun(a, b, e, ur1) << endl;
	cout << fun(a, b, e, ur2) << endl;
	cout << "N2" << endl;
	cout << fun(a, b, e, ur3) << endl;
	cout << fun(a, b, e, ur4) << endl;
	cout << "N5" << endl;
	cout << fun(a, b, e, ur5) << endl;
	cout << fun(a, b, e, ur6) << endl;
}

double fun(double a, double b, double e,double(*f)(double))
{
	while (true)
	{

		double x;
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
			b = x;
		else
			a = x;
		if (abs(a - b) < 2 * e)
			return (x);
	}
}

double ur1(double x)
{
	return(x * x + 4 * x - 2);
}

double ur2(double x)
{
	return(sin(x) + 0.1);
}
double ur3(double x)
{
	return(x*x*x+x-3);
}

double ur4(double x)
{
	return(cos(x)* cos(x)* cos(x));
}
double ur5(double x)
{
	return(exp(x)-3-1/x);
}

double ur6(double x)
{
	return(0.2-x*x);
}
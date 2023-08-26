#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str,temp;
	ifstream f1("A.txt");
	ofstream f2("B.txt");
	while (getline(f1, str))
	{
		if (str[0] == 'À')
		{
			f2 << str;
			f2 << '\n';
		}
	}
	f1.close();
	f2.close();

	ifstream f3("B.txt");

	int slov = 0;
	while (getline(f3, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				slov++;
		}
		slov++;
	}
	cout << slov;
}
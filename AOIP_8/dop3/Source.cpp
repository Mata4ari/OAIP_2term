#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	string str1, str2;
	ifstream f("A.txt");
	while (getline(f, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				str2 += str[i];
			}
			else
			{
				str1 += str[i];
			}
		}
		cout << str1<<"\t";
		cout << str2 << endl;;
		str1.clear();
		str2.clear();
	}
	f.close();
}
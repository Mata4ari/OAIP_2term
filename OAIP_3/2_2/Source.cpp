#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
void write(string str);
string read();

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str,temp,min;
	getline(cin, str);

	write(str);
	str = read();


	min = str;
	
	for (int i = 0; i < str.size(); i++)
	{
		temp += str[i];
		if (str[i] == ' ')
		{
			if (temp.size() < min.size())
			{
				min = temp;
			}
			temp.clear();
		}
	}
	cout << min;
}

void write(string str)
{
	ofstream f1("A.txt");
	f1 << str;
	f1.close();
}

string read()
{
	string str;
	ifstream f2("A.txt");

	getline(f2, str);
	f2.close();
	return str;
}
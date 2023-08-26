#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
void write(string str,ofstream &f);
string read();

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str,temp,str1;

	ofstream f1("A.txt");
	ofstream f3("B.txt");

	getline(cin, str);

	write(str,f1);

	str = read();

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			str1 += str[i];
		}
	}

	cout << str1;

	write(str1, f3);

}

void write(string str, ofstream &f)
{
	f << str;
	f.close();
}

string read()
{
	string str;
	ifstream f2("A.txt");

	getline(f2, str);
	f2.close();
	return str;
}
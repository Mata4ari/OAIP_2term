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

	string str,str1;

	
	getline(cin, str);

	write(str);

	str=read();
	int countsim = 0,j=0;
	string word;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			word += str[i];
		}
		else
		{
			if (word.size() % 2 == 0)
			{
				str1 += word;
				str1 += ' ';
			}
			word.clear();
		}
	}
	cout << str1;

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
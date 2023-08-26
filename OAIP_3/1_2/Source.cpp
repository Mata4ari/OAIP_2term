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

	string str,temp,str1;
	getline(cin,str);

	write(str);
	str = read();

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			temp += str[i];
			if (str[i + 1] <= 48 || str[i + 1] >= 57)
			{
				if (stoi(temp) % 2 != 0)
				{
					str1 += temp;
					str1 += ' ';
				}
				temp.clear();
			}
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
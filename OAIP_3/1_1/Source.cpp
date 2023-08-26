#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str,str1,str2;
	ofstream f2("B.txt");
	ifstream f1("A.txt");
	int count = 0;
	while (getline(f1, str))
	{
		str1 += str;
		count++;
		if (count % 2 == 0)
		{
			str += '\n';
			f2 << str;
		}
	}
	f1.close();
	f2.close();
	ifstream f3("B.txt");


	while (getline(f3, str))
	{
		str2 += str;
	}

	f3.close();

	cout<<"A.txt size= " << str1.size() <<" байт"<< endl;
	cout << "B.txt size= " << str2.size() << " байт" << endl;
}
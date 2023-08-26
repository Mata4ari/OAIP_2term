#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	getline(cin, str);
	int n = str.size();
	string str1, str2;
	for (int i = n/2-1,j=n-1; i >=0; i--,j--)
	{
		str1 += str[i];
		str2 += str[j];
	}
	cout << str1+str2 << endl;
}
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, k,count=0,sum=0;
	cin >> n;
	cin >> k;
	string str;

	ofstream f2("B.txt");
	ifstream f1("A.txt");
	while (getline(f1,str))
	{
		count++;
		if (count >= n && count <= k)
		{
			f2 << str;
			f2 << '\n';
		}
	}

	f1.close();
	f2.close();

	ifstream f3("B.txt");

	while (getline(f3, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' &&
				str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != ' ' && str[i] != '�' && str[i] != '�' && str[i] != '�' &&
				str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�' && str[i] != '�')
			{
				sum++;
			}
		}
	}
	cout << sum;
	f3.close();
}
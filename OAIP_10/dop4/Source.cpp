#include <iostream>
using namespace std;

void main()
{
	string str = "0123456789";
	string buf;
	for (int i = 0; i < 26; i++)
	{
		for (int k = str.size()-1; k >0; k--)
		{
			if (k == str.size() - 1)
				buf += str[k];
			str[k] = str[k - 1];
		}
		str[0] = buf[0];
		buf.clear();
	}
	
	cout << str << endl;
	unsigned n;
	cin >> n;
	cout << str[n-1];
}
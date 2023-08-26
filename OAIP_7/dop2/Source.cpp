#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int num;
	list* next;
};

void main()
{
	list* p = nullptr;
	ifstream f("A.txt");
	string str;
	while (getline(f,str))
	{
		list* newp = new list;
		newp->next = p;
		newp->num = str.size();
		p = newp;
	}
	f.close();
	int min, n=0,i=0;
	min = p->num;
	while (p != nullptr)
	{
		i++;
		if (min > p->num)
		{
			min = p->num;
			n = i;
		}
		cout << p->num << endl;
		p = p->next;
	}
	cout << "min dlina=" << min << " nomer=" << n << endl;
}
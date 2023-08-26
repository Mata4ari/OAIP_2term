#include <iostream>
#include <conio.h>  
#include <fstream>
#include <string>
using namespace std;
struct node
{
	int data;
	node* left, * right;
};
node* tree = nullptr;

void build()
{
	int n, x;
	node* ptr, * t;
	cout << "¬ведите количество элементов" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ptr = new(node);
		ptr->right = ptr->left = nullptr;
		cin >> x;
		ptr->data = x;
		if (tree == nullptr)
		{
			tree = ptr;
			continue;
		}
		t = tree;
		while (true)
		{
			if (t->data < x)
			{
				if (t->right == nullptr)
				{
					t->right = ptr;
					break;
				}
				else
				{
					t = t->right;
					continue;
				}
			}
			if (t->data > x)
			{
				if (t->left == nullptr)
				{
					t->left = ptr;
					break;
				}
				else
				{
					t = t->left;
					continue;
				}
			}
		}
	}
}

void print(node* t, int u)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{

		print(t->left, ++u);

		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;

	}

	print(t->right, ++u);

}

void insert()
{
	node* t;
	node* ptr;
	int x;
	cout << "¬ведите значение" << endl;
	cin >> x;
	ptr = new(node);
	ptr->right = ptr->left = nullptr;
	ptr->data = x;
	t = tree;
	while (true)
	{
		if (t->data < x)
		{
			if (t->right == nullptr)
			{
				t->right = ptr;
				break;
			}
			else
			{
				t = t->right;
				continue;
			}
		}
		if (t->data > x)
		{
			if (t->left == nullptr)
			{
				t->left = ptr;
				break;
			}
			else
			{
				t = t->left;
				continue;
			}
		}
	}
}

int del()
{
	node* t, * p, * pp = tree;
	int x;

	cout << "¬ведите удал€емый элемент" << endl;
	cin >> x;

	p = tree;
	while (true)
	{
		if (p->data == x)
			break;
		if (p->data < x)
		{
			pp = p;
			p = p->right;
		}
		if (p->data > x)
		{
			pp = p;
			p = p->left;
		}
	}
	if (p->left == nullptr && p->right == nullptr)
	{
		if (pp->right == p)
			pp->right = nullptr;
		else
			pp->left = nullptr;
		delete p;
		return 0;
	}
	if (p->left == nullptr || p->right == nullptr)
	{
		if (p->left == nullptr)
		{
			if (pp->right == p)
				pp->right = p->right;
			if (pp->left == p)
				pp->left = p->right;
			delete p;
			return 0;
		}
		if (p->right == nullptr)
		{
			if (pp->right == p)
				pp->right = p->left;
			if (pp->left == p)
				pp->left = p->left;
			delete p;
			return 0;
		}
	}
	if (p->left != nullptr && p->right != nullptr)
	{
		t = p->right;
		pp = p;
		while (t->left != nullptr && t->right != nullptr)
		{
			if (t->left != nullptr)
			{
				pp = t;
				t = t->left;
			}
			if (t->left == nullptr && t->right != nullptr)
			{
				pp = t;
				t = t->right;
			}
		}
		cout << p->data << endl;
		cout << t->data << endl;
		p->data = t->data;
		if (pp->left == t)
			pp->left = nullptr;
		if (pp->right == t)
			pp->right = nullptr;
		delete t;
		return 0;
	}
}

void clear(node* t)
{
	if (t == nullptr)  return;
	else
	{
		clear(t->left);
		clear(t->right);
		delete t;
	}
	tree = nullptr;
}

void read()
{
	node* ptr, * t;
	clear(tree);
	string str;
	int x;
	ifstream f1("A.txt");
	while (getline(f1, str))
	{
		x = stoi(str);
		ptr = new(node);
		ptr->right = ptr->left = nullptr;
		ptr->data = x;
		if (tree == nullptr)
		{
			tree = ptr;
			continue;
		}
		t = tree;
		while (true)
		{
			if (t->data < x)
			{
				if (t->right == nullptr)
				{
					t->right = ptr;
					break;
				}
				else
				{
					t = t->right;
					continue;
				}
			}
			if (t->data > x)
			{
				if (t->left == nullptr)
				{
					t->left = ptr;
					break;
				}
				else
				{
					t = t->left;
					continue;
				}
			}
		}
	}
	f1.close();
}

void write(node* t,ofstream& f2)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{
		write(t->left,f2);
		f2 << t->data << endl;
	}

	write(t->right,f2);
}

void sum(node* t,int* A, int& c,int& s)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{

		sum(t->left,A,c,s);
		
		A[c] = t->data;
		c++;
		if (t->right == nullptr && t->left == nullptr)
			s += t->data;
	}

	sum(t->right,A,c,s);
}

void alls(node* t, int& ss)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{
		alls(t->left,ss);
		ss += t->data;
	}

	alls(t->right,ss);
}

void chet(node* t, int& h)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{
		chet(t->left, h);
		if (t->data % 2 == 0)
			h++;
	}

	chet(t->right, h);
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	int s = 0,c=0,ss=0,h=0;
	int A[50];
	while (choice != 0)
	{
		cout << "1-построение" << endl;
		cout << "2-вывод" << endl;
		cout << "3-вставка элемента" << endl;
		cout << "4-удаление" << endl;
		cout << "5-очистка" << endl;
		cout << "6-чтение" << endl;
		cout << "7-запись" << endl;
		cout << "8-сумма листьев" << endl;
		cout << "9-сумма всех вершин" << endl;
		cout << "10-четных узлов" << endl;
		cin >> choice;
		if (choice == 1)
			build();
		if (choice == 2)
			print(tree, 0);
		if (choice == 3)
			insert();
		if (choice == 4)
			del();
		if (choice == 5)
			clear(tree);
		if (choice == 6)
			read();
		if (choice == 7)
		{
			ofstream f2("B.txt");
			write(tree,f2);
			f2.close();
		}
		if (choice == 8)
		{
			sum(tree, A,c,s);
			cout << endl << s << endl;
		}
		if (choice == 9)
		{
			alls(tree, ss);
			cout << endl << ss << endl;
			ss = 0;
		}
		if (choice == 10)
		{
			chet(tree, h);
			cout << endl << h << endl;
			h = 0;
		}
	}
}
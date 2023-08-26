#include <iostream>
#include <conio.h>  
#include <fstream>
#include <string>
using namespace std;
struct node
{
	int data;
	node* left, * right;
	string fio;
	int tar;
};
node* tree = nullptr;

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
		cout << t->data <<"\t"<<t->fio<<"\t"<<"Тарифный план "<<t->tar<<endl;
		u--;
	}
	print(t->right, ++u);
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
		getline(f1, str);
		ptr->fio = str;
		getline(f1, str);
		ptr->tar = stoi(str);
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

void poshuk(node*t,int n)
{
	while(true)
	{
		if (t == nullptr) return;
		if (n == t->data)
		{
			cout << t->fio << endl;
			return;
		}
		if (t->data < n)
			t = t->right;
		else
			t = t->left;
	}
}

void chek(node* t,int*A)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{
		chek(t->left,A);
		A[t->tar]++;
	}
	chek(t->right,A);
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	int num;
	const int N = 10;
	int A[N],max=0,maxi=0;
	while (choice != 0)
	{
		cout << "1-вывод" << endl;
		cout << "2-очистка" << endl;
		cout << "3-чтение" << endl;
		cout << "4-пошук" << endl;
		cin >> choice;
		if (choice == 1)
			print(tree, 0);
		if (choice == 2)
			clear(tree);
		if (choice == 3)
			read();
		if (choice == 4)
		{
			cin >> num;
			poshuk(tree, num);
		}
		if (choice == 5)
		{
			for (int i = 0; i < N; i++)
				A[i] = 0;
			chek(tree,A);
			for (int i = 0; i < N; i++)
			{
				if (A[i] > max)
				{
					max = A[i];
					maxi = i;
				}
			}
			cout << "Наиболее частый тарифный план " << maxi << endl;
		}
	}
}
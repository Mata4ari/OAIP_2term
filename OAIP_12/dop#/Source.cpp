#include <iostream>
#include <conio.h>  
#include <fstream>
#include <string>
using namespace std;
struct node
{
	int data;
	node* left, * right;
	string color;
	node* parent;
};
node* tree = nullptr;

void build()
{
	int n, x;
	node* ptr, * t;
	cout << "������� ���������� ���������" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ptr = new(node);
		ptr->right = ptr->left=ptr->parent = nullptr;
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
	cout << "������� ��������" << endl;
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

	cout << "������� ��������� �������" << endl;
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

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	int s = 0, c = 0, ss = 0, h = 0;
	int A[50];
	while (choice != 0)
	{
		cout << "1-����������" << endl;
		cout << "2-�����" << endl;
		cout << "3-������� ��������" << endl;
		cout << "4-��������" << endl;
		cout << "5-�������" << endl;
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
	}
}
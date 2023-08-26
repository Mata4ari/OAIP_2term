#include <iostream>
#include <conio.h>  
#include <fstream>
#include <string>
using namespace std;
struct node
{
	int data;
	node* left, * right;
	string color="b";
	node* parent;
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
		ptr->right = ptr->left = ptr->parent = nullptr;
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
					ptr->parent = t;
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
					ptr->parent = t;
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
		cout << t->data;
		if (t->color == "b")
			cout << "\t" << "black" << endl;
		else
			cout << "\t" << "red" << endl;
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
				ptr->parent = t;
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
				ptr->parent = t;
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
			{
				pp->right = p->right;
				p->right->parent = pp;
			}
			if (pp->left == p)
			{
				pp->left = p->right;
				p->right->parent = pp;
			}
			delete p;
			return 0;
		}
		if (p->right == nullptr)
		{
			if (pp->right == p)
			{
				pp->right = p->left;
				p->left->parent = pp;
			}
			if (pp->left == p)
			{
				pp->left = p->left;
				p->left->parent = pp;
			}
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

void color(node*t)
{
	if (t == nullptr) return;
	if (tree == t)
		t->color = "b";
	else
	{
		if (t->parent->color == "b")
			t->color = "r";
		else
			t->color = "b";
	}
	color(t->right);
	color(t->left);
}

void chek(node* t, int a,int&min)
{
	if (t == nullptr)
	{
		if (a < min)
			min = a;
		return;
	}
	else
	{
		if (t->color == "b")
			a++;
		chek(t->left, a,min);
	}
	chek(t->right,a,min);
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	int s = 0, c = 0, ss = 0, h = 0;
	int a=0,min=20;
	while (choice != 0)
	{
		cout << "1-построение" << endl;
		cout << "2-вывод" << endl;
		cout << "3-вставка элемента" << endl;
		cout << "4-удаление" << endl;
		cout << "5-очистка" << endl;
		cin >> choice;
		if (choice == 1)
			build();
		if (choice == 2)
		{
			color(tree);
			print(tree, 0);
		}
		if (choice == 3)
			insert();
		if (choice == 4)
			del();
		if (choice == 5)
			clear(tree);
		if (choice == 6)
		{
			chek(tree, 0, min);
			cout << min << endl;
		}
	}
}
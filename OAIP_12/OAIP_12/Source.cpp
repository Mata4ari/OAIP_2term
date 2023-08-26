#include <iostream>
#include <conio.h>  
#include <fstream>
#include <string>
using namespace std;
struct node
{
	int data;
	node* left, * right;
	int height=0;
};
node* tree = nullptr;

void build()
{
	int n, x;
	node* ptr, * t;
	cout << "Введите количество элементов" << endl;
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
	cout << "Введите значение" << endl;
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

	cout << "Введите удаляемый элемент" << endl;
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

void write(node* t, ofstream& f2)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{
		write(t->left, f2);
		f2 << t->data << endl;
	}

	write(t->right, f2);
}

void niz(node* t)
{
	if (tree == nullptr)
	{
		cout << "pusto" << endl;
		return;
	}
	if (t == nullptr)  return;
	else
	{
		cout << t->data << endl;
		niz(t->left);
	}
	niz(t->right);
}

int chek(node* t)
{
	if (t == nullptr)  return 0;
	
		t->height++;
		chek(t->left);
		chek(t->right);
		if(t->left!=nullptr||t->right!=nullptr)
		{
			if (t->left != nullptr && t->right != nullptr)
			{
				if (t->left->height >= t->right->height)
					t->height += t->left->height;
				else
					t->height += t->right->height;
			}
			if (t->left != nullptr && t->right == nullptr)
				t->height += t->left->height;
			if (t->left == nullptr && t->right != nullptr)
				t->height += t->right->height;
		}
}

void balance(node* t)
{
	if (t == nullptr)  return;
	else
	{
		if (t->left != nullptr && t->right != nullptr)
		{
			if (t->left->height - t->right->height > 1 || t->left->height - t->right->height < -1)
				cout << "Не сбалансировано" << endl;
		}
		else if (t->left != nullptr || t->right != nullptr)
		{
			if(t->left!=nullptr)
			{
				if (t->left->height > 1)
					cout << "Не сбалансировано" << endl;
			}
			else
			{
				if (t->right->height > 1)
					cout << "Не сбалансировано" << endl;
			}
		}
		balance(t->left);
	}
	balance(t->right);
}

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	int s = 0, c = 0, ss = 0, h = 0;
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
		cout << "8-нисходящий обход" << endl;
		cout << "9-Проверка" << endl;
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
			write(tree, f2);
			f2.close();
		}
		if (choice == 8)
		{
			niz(tree);
		}
		if (choice == 9)
		{
			chek(tree);
			balance(tree);
		}
	}
}
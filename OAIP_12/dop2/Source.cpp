#include <iostream>
#include <conio.h>  
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
struct node
{
	int data;
	node* left, * right;
};
node* tree = nullptr;

void build(int n)
{
	node* ptr, * t;
	srand(time(NULL));
	
	for (int i = 0; i < n; i++)
	{
		ptr = new(node);
		ptr->data = rand() % 1000 + 1;
		ptr->right = ptr->left = nullptr;
		if (tree == nullptr)
		{
			tree = ptr;
			continue;
		}
		t = tree;
		while(true)
		{
			if (ptr->data < t->data && t->left == nullptr)
			{
				t->left = ptr;
				break;
			}
			if (ptr->data > t->data && t->right == nullptr)
			{
				t->right = ptr;
				break;
			}
			if (ptr->data < t->data && t->right == nullptr&&t->left!=nullptr&&ptr->data<tree->data)
			{
				ptr->right = tree;
				tree = ptr;
				break;
			}
			else if(ptr->data < t->data && t->right == nullptr && t->left != nullptr && ptr->data > tree->data)
			{
				t = tree;
				while (true)
				{
					if (ptr->data > t->data && ptr->data < t->right->data)
					{
						ptr->right = t->right;
						t->right = ptr;
						break;
					}
					t = t->right;
				}
				break;
			}
			t = t->right;
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

void main()
{
	int n;
	cin >> n;
	build(n);
	print(tree, 0);
}
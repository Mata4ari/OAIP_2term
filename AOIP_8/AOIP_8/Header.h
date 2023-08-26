#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int num;
	list* next;
};

void insert(list*& p, int val);
void print(list*& p);
void del(list*& p);
void clear(list*& p);
void length(list*& p);
void check(list*& p);
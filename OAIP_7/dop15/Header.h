#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	int number;
	list* next;
};

void insert(list*& p, int val);
void del(list*& p);
void print(list*& p);
list* clear(list*& p);
void inp(list*& p);
void outp(list*& p);
void check(list*& p);
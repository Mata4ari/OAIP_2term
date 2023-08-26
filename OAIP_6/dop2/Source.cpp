#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cin; using std::endl; using std::cout;

struct Node
{
    double data;
    Node* next;
};

void insert(Node*& head, double data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void output(Node*& head)
{
    Node* p = head;
    while (p != nullptr)
    {
        cout << p->data << '\t';
        p = p->next;
    }
}

double averagePositive(Node*& head)
{
    //double sum = NULL;
    //int count = 0;

    //while (head != nullptr)
    //{
    //    cout << head->data << '\t';
    //    if (head->data > 0.0)
    //    {
    //        sum += head->data;
    //        count++;
    //    }
    //    head = head->next;
    //}

    //if (count == 0)
    //{
    //    return 0.0;
    //}
    //else
    //{
    //    return sum / count;
    //}
    return 0;
}

void del(Node*& head)
{
    while (head != nullptr)
    {
        delete head;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand((unsigned int)time(NULL));

    Node* head = nullptr;
    int n = NULL;

    cout << "¬ведите количество элементов в списке: "; cin >> n;


    for (int i = 0; i < n; i++)
    {
        double temp = i;
        double a = temp / 10;
        insert(head, a);
    }

    double avg = (double)averagePositive(head);

    cout << endl << "—реднее значение положительных элементов: " << avg << endl;

    return 0;
}
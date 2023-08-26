#include "Header.h";

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	list* phead = nullptr;
	list* p;
	p = phead;

	int value;

	while (choice != 0)
	{
		cout << "1 - добавление " << endl;
		cout << "2 - удаление" << endl;
		cout << "3 - очистка" << endl;
		cout << "4 - вывод" << endl;
		cout << "5 - запись" << endl;
		cout << "6 - считывание" << endl;
		cout << "7 - подсчитывает количество элементов стека, у которых равные соседи" << endl;
		cout << "0 - выход" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Введите число" << endl;
			cin >> value;
			insert(p, value);
		}
		if (choice == 2)
		{
			del(p);
		}
		if (choice == 3)
			clear(p);
		if (choice == 4)
			print(p);
		if (choice == 5)
			inp(p);
		if (choice == 6)
			outp(p);
		if (choice == 7)
			check(p);
	}
}

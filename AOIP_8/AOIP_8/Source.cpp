#include "Header.h";

void main()
{
	setlocale(LC_CTYPE, "ru");
	int choice = -1;
	list* phead = nullptr;
	list* pend;
	list* p;
	p = phead;

	int value;

	while (choice != 0)
	{
		cout << "1 - добавление элемента" << endl;
		cout << "2 - извлечение элемента" << endl;
		cout << "3 - очистка очереди" << endl;
		cout << "4 - вывод очереди" << endl;
		cout << "5 - определение длины" << endl;
		cout << "6 - элементы до первого 0" << endl;
		cout << "0 - выход" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "¬ведите число" << endl;
			cin >> value;
			insert(p, value);
		}
		if (choice == 2)
			del(p);
		if (choice == 3)
			clear(p);
		if (choice == 4)
			print(p);
		if (choice == 5)
			length(p);
		if (choice == 6)
			check(p);
	}
}

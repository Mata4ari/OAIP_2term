#include <iostream>
using namespace std;

struct dat
{
	unsigned da : 21;
};

enum marka
{
	audi =0, bmw, ford, honda, kia, lada, mazda, mercedes, toyota, skoda
};

struct car
{
	marka mark;
	string color;
	unsigned nomer;
	dat d;
	string kuzov;
	unsigned teh;
	string owner;
};

void input(car* cars, int& count);
void output(car* cars, int& count);
void del(car* cars, int& count, int& x);
void search(car* cars, int& count);

void main()
{
	setlocale(LC_CTYPE, "ru");
	car cars[10];
	int count = 0;
	int choice = -1;
	while (choice != 0)
	{
		cout << "1.Ввод данных с клавиатуры" << endl;
		cout << "2.Вывод данных в консоль" << endl;
		cout << "3.Удаление заданной переменной" << endl;
		cout << "4.Поиск по номеру" << endl;
		cout << "0.Выход из программы" << endl;
		cout << "Введите номер операции: " << endl;
		cin >> choice;
		if (choice == 1)
			input(cars,count);
		if (choice == 2)
			output(cars,count);
		if (choice == 3)
		{
			int x;
			cout << "Введите номер авто в списке которое нужно удалить" << endl;
			cin >> x;
			del(cars, count, x);
		}
		if (choice == 4)
			search(cars,count);
	}
}

void input(car*cars, int& count)
{
	int x = 1;
	unsigned nom;
	string A[10] = { "audi","bmw","ford","honda","kia","lada","mazda","mercedes","toyota","skoda" }, n;
	while (x != 0)
	{
		cout << "1.Ввести новый автомобиль" << endl;
		cout << "0.Закончить" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "Введите марку авто" << endl;
			cin >> n;
			if (n == A[0])
				cars[count].mark = audi;
			if (n == A[1])
				cars[count].mark = bmw;
			if (n == A[2])
				cars[count].mark = ford;
			if (n == A[3])
				cars[count].mark = honda;
			if (n == A[4])
				cars[count].mark = kia;
			if (n == A[5])
				cars[count].mark = lada;
			if (n == A[6])
				cars[count].mark = mazda;
			if (n == A[7])
				cars[count].mark = mercedes;
			if (n == A[8])
				cars[count].mark = toyota;
			if (n == A[9])
				cars[count].mark = skoda;

			cout << "Введите цвет авто" << endl;
			cin >> cars[count].color;
			cout << "Введите номер авто" << endl;
			cin >> cars[count].nomer;
			cout << "Введите дату выпуска авто" << endl;
			cin >> nom;
			cars[count].d.da = nom;
			cout << "Введите тип кузова авто" << endl;
			cin >> cars[count].kuzov;
			cout << "Введите дату тех осмотра авто" << endl;
			cin >> cars[count].teh;
			cout << "Введите владельца авто" << endl;
			cin >> cars[count].owner;
			count++;
		}
	}
}

void output(car*cars,int&count)
{
	string A[10] = { "audi","bmw","ford","honda","kia","lada","mazda","mercedes","toyota","skoda" };
	for (int i = 0; i < count; i++)
	{
		cout << A[cars[i].mark] << endl;
		cout << cars[i].color << endl;
		cout <<"nomer "<<cars[i].nomer << endl;
		cout <<"data "<< cars[i].d.da << endl;
		cout << cars[i].kuzov << endl;
		cout <<"tehosmotr"<< cars[i].teh << endl;
		cout << cars[i].owner << endl;
		cout << endl;
	}
}

void del(car*cars,int&count,int&x)
{
	for (int i = x; i < count; i++)
	{
		cars[i].mark = cars[i + 1].mark;
		cars[i].color = cars[i + 1].color;
		cars[i].nomer = cars[i + 1].nomer;
		cars[i].d.da = cars[i + 1].d.da;
		cars[i].kuzov = cars[i + 1].kuzov;
		cars[i].teh = cars[i + 1].teh;
		cars[i].owner = cars[i + 1].owner;
	}
	count--;
}

void search(car*cars,int&count)
{
	string A[10] = { "audi","bmw","ford","honda","kia","lada","mazda","mercedes","toyota","skoda" };
	int x;
	cout << "Введите номер авто" << endl;
	cin >> x;
	for (int i = 0; i < count; i++)
	{
		if (cars[i].nomer == x)
		{
			cout << A[cars[i].mark] << endl;
			cout << cars[i].color << endl;
			cout << "nomer " << cars[i].nomer << endl;
			cout << "data " << cars[i].d.da << endl;
			cout << cars[i].kuzov << endl;
			cout << "tehosmotr" << cars[i].teh << endl;
			cout << cars[i].owner << endl;
			cout << endl;
		}
	}
}
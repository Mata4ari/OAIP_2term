#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <ranges>

using std::cout; using std::cin; using std::endl;

struct birthday_bytes
{
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

struct citizen
{
	std::string name_surname;
	std::string product;
	int mark_size;
	int sum;
	birthday_bytes date_of_return;
	int shelf_life;

	friend std::ostream& operator<<(std::ostream& os, std::vector<citizen>& citizens);
};

std::ostream& operator<<(std::ostream& os, const citizen& citizens)
{
	os << citizens.name_surname << '\n' << citizens.product << '\n' << citizens.mark_size << '\n' << citizens.sum
		<< '\n' << citizens.shelf_life << '\n' << citizens.date_of_return.day << '.' << citizens.date_of_return.month
		<< '.' << citizens.date_of_return.year << '\n';
	return os;
}

void include_citizens(std::vector<citizen>& guesses, int& n)
{
	for (int i = 0; i < n; i++)
	{
		int count = NULL;
		int gender = NULL;
		int day = NULL, month = NULL, year = NULL;
		cout << endl << "ФИО: "; cin >> guesses[i].name_surname;
		cout << endl << "Наименование товара: "; cin >> guesses[i].product;
		cout << endl << "Оценочная стоимость: "; cin >> guesses[i].mark_size;
		cout << endl << "Сумма, выданная под залог: "; cin >> guesses[i].sum;
		cout << endl << "Дата сдачи: "; cin >> day; cin >> month; cin >> year;
		guesses[i].date_of_return.day = day;
		guesses[i].date_of_return.month = month;
		guesses[i].date_of_return.year = year;
		cout << endl << "Срок хранения: "; cin >> guesses[i].shelf_life;
	}
}

void find_citizens(std::vector<citizen>& citizens)
{
	int day = NULL, month = NULL, year = NULL;
	birthday_bytes date; cout << "Введите дату, по которому будет осуществляться поиск просрочки: "; cin >> day; cin >> month; cin >> year;
	date.day = day; date.month = month; date.year = year;
	auto output = citizens | std::ranges::views::filter([&](const auto& v) {return v.date_of_return.day + v.shelf_life >= v.date_of_return.day && v.date_of_return.month >= v.date_of_return.month && v.date_of_return.year >= v.date_of_return.year; });
	for (auto a : output)
	{
		cout << a << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = NULL;
	cout << "Количество товара: "; cin >> n;
	std::vector<citizen> citizens(n);
	include_citizens(citizens, n);

	for (auto a : citizens)
	{
		cout << a << endl;
	}
	cout << endl;
	find_citizens(citizens);
}
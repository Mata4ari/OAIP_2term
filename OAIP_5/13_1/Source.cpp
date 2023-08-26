#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <ranges>

using std::cout; using std::cin; using std::endl;

struct birthday_bytes
{
	unsigned int week_day : 3;
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

enum Gender
{
	ХТИТ = 1,
	ФИТ,
	Лесхоз
};

struct citizen
{
	std::string name_surname;
	birthday_bytes birthday_date;
	std::string speciality;
	Gender faculty;
	double sr_mark;

	friend std::ostream& operator<<(std::ostream& os, std::vector<citizen>& citizens);
};

std::ostream& operator<<(std::ostream& os, const citizen& citizens)
{
	os << citizens.name_surname << '\n' << citizens.speciality << '\n' << citizens.sr_mark << '\n' << citizens.birthday_date.day << '.' << citizens.birthday_date.month << '.' << citizens.birthday_date.year << '\n';
	switch (citizens.faculty)
	{
	case 1: os << "ХТИТ";
		break;
	case 2: os << "ИТ";
		break;
	case 3: os << "Лесхоз";
		break;
	}
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
		cout << endl << "Специальность: "; cin >> guesses[i].speciality;
		cout << endl << "Дата поступления:"; cin >> day; cin >> month; cin >> year;
		guesses[i].birthday_date.day = day;
		guesses[i].birthday_date.month = month;

		guesses[i].birthday_date.year = year;
		cout << endl << "Факультет: ХТИТ - 1, ИТ - 2, Лесхоз - 3 "; cin >> gender;
		cout << endl << "Средний балл:"; cin >> guesses[i].sr_mark;
		guesses[i].faculty = (Gender)gender;
	}
}

void find_citizens(std::vector<citizen>& citizens)
{
	double year = NULL; cout << "Введите среднюю оценку, по которому будет осуществляться поиск: "; cin >> year;
	auto output = citizens | std::ranges::views::filter([&](const auto& v) {return v.sr_mark == year; });
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
	cout << "Количество студентов: "; cin >> n;
	std::vector<citizen> citizens(n);
	include_citizens(citizens, n);

	for (auto a : citizens)
	{
		cout << a << endl;
	}
	cout << endl;
	find_citizens(citizens);
}


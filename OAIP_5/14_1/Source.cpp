#include <iostream>
#include <Windows.h>
#include <vector>
#include <ranges>
#include <regex>
#include <fstream>
#include <string>

using std::cout; using std::cin; using std::endl;

std::string include_phone_number();
std::string include_pasport_data();

enum room {
    апартаменты = 1,
    однокомнатная,
    двухкомнатная,
    люкс
};

struct date
{
    unsigned day : 5;
    unsigned month : 4;
    unsigned year : 12;
};

struct hotel_guess
{
    std::string surname;
    room room_level;
    date guess_in;
    date guess_out;
    std::string pasport_data;
    std::string phone_number;

    friend std::ostream& operator<<(std::ostream& os, const hotel_guess& dt);
};

std::ostream& operator<<(std::ostream& os, const hotel_guess& dt)
{
    os << dt.surname << '\n' << dt.pasport_data << '\n' << dt.phone_number << '\n' << dt.guess_in.day << '.' << dt.guess_in.month << '.' << dt.guess_in.year << '\n' << dt.guess_out.day << '.' << dt.guess_out.month << '.' << dt.guess_out.year << endl;
    switch (dt.room_level)
    {
    case 1:
        os << "апартаменты";
        break;
    case 2:
        os << "однокомнатная";
        break;
    case 3:
        os << "двухкомнатная";
        break;
    case 4:
        os << "люкс";
        break;
    }
    return os;
}

void classic_include_guess(std::vector<hotel_guess>& guesses, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int room_l = NULL;
        int day = NULL, month = NULL, year = NULL;
        cout << endl << "Фамилия: "; cin >> guesses[i].surname;
        cout << endl << "тип комнаты: апартаменты - 1, однокомнатная - 2, двухкомнатная - 3, люкс - 4"; cin >> room_l; guesses[i].room_level = (room)room_l;
        cout << endl << "паспортные данные: "; guesses[i].pasport_data = include_pasport_data();
        cout << endl << "номер гостя: "; guesses[i].phone_number = include_phone_number();
        cout << endl << "Дата приезда: "; cin >> day >> month >> year;
        guesses[i].guess_in.day = day;
        guesses[i].guess_in.month = month;
        guesses[i].guess_in.year = year;
        cout << endl << "Дата отъезда: "; cin >> day >> month >> year;
        guesses[i].guess_out.day = day;
        guesses[i].guess_out.month = month;
        guesses[i].guess_out.year = year;
    }
}

std::string include_phone_number()
{
    std::regex phone_regular("^[\+]+[0-9]{12}$");
    std::cmatch result_of_regular;
    std::string phone_number;

    cin >> phone_number;
    if (std::regex_match(phone_number.c_str(), result_of_regular, phone_regular) == 0)
    {
        cout << "Неправильный вид номера: ";
        return include_phone_number();
    }
    else return phone_number;
}

std::string include_pasport_data()
{
    std::regex pasport_regular("^[A-Z]{2}[0-9]{7}$");
    std::cmatch result_of_regular;
    std::string pasport_data;

    cin >> pasport_data;
    if (std::regex_match(pasport_data.c_str(), result_of_regular, pasport_regular) == 0)
    {
        cout << "Неправильный вид паспортных данных: ";
        return include_pasport_data();
    }
    else return pasport_data;
}

void find_guess(std::vector<hotel_guess>& guesses)
{
    int day = NULL, month = NULL, year = NULL;
    cout << endl << "Введите дату, по которой будет поиск гостей: " << endl;
    cin >> day >> month >> year;
    auto output = guesses | std::ranges::views::filter([&](const auto& v) {return v.guess_in.day == day && v.guess_in.month == month && v.guess_in.year == year; });
    cout << endl << "Результат поиска: " << endl << endl;
    for (auto a : output)
    {
        cout << a << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = NULL; cout << "Введите количество гостей: " << endl; cin >> n;
    std::vector<hotel_guess> guesses(n);
    classic_include_guess(guesses, n);
    for (auto a : guesses)
    {
        cout << a << endl;
    }
    find_guess(guesses);
}
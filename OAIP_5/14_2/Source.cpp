#include <iostream>
#include <Windows.h>
#include <vector>
#include <ranges>
#include <regex>

using std::cout; using std::cin; using std::endl;

std::string include_phone_number();
std::string include_pasport_data();

struct hotel_guess
{
    std::string surname;
    std::string room_level;
    std::string guess_in;
    std::string guess_out;
    std::string pasport_data;
    std::string phone_number;

    friend std::ostream& operator<<(std::ostream& os, const hotel_guess& dt);
};

std::ostream& operator<<(std::ostream& os, const hotel_guess& dt)
{
    os << dt.surname << '\n' << dt.room_level << '\n' << dt.pasport_data << '\n' << dt.phone_number << '\n' << dt.guess_in << '\n' << dt.guess_out << endl;
    return os;
}

void classic_include_guess(std::vector<hotel_guess>& guesses, int& n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Фамилия: "; cin >> guesses[i].surname;
        cout << endl << "тип комнаты: "; cin >> guesses[i].room_level;
        cout << endl << "паспортные данные: "; guesses[i].pasport_data = include_pasport_data();
        cout << endl << "номер гостя: "; guesses[i].phone_number = include_phone_number();
        cout << endl << "Дата приезда: "; cin >> guesses[i].guess_in;
        cout << endl << "Дата отъезда: "; cin >> guesses[i].guess_out;
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

void find_guess(std::vector<hotel_guess>& guesses, std::string& surname)
{
    cin >> surname;
    auto output = guesses | std::ranges::views::filter([&](const auto& v) {return v.surname == surname; });
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
    std::string surname;
    std::vector<hotel_guess> guesses(n);
    classic_include_guess(guesses, n);
    find_guess(guesses, surname);
}
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <ranges>

using std::cout; using std::cin; using std::endl;

struct trains
{
    std::string name;
    std::string number;
    std::string time;

    friend std::ostream& operator<<(std::ostream& os, const trains& dt);
};

std::ostream& operator<<(std::ostream& os, const trains& dt)
{
    os << dt.name << '\n' << dt.number << '\n' << dt.time << endl;
    return os;
}

void include_trains(std::vector<trains>& guesses, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int count = NULL;
        cout << endl << "Название пункта назначения: "; cin >> guesses[i].name;
        cout << endl << "Номер поезда: "; cin >> guesses[i].number;
        cout << endl << "Время отправления:"; cin >> guesses[i].time;
    }
}

void check_trains(std::vector<trains>& vector_of_trains)
{
    std::ranges::sort(vector_of_trains, [](const auto& v1, const auto& v2) {return v1.name < v2.name; });
    for (auto a : vector_of_trains)
    {
        cout << a << '\n';
    }
}

void check_time(std::vector<trains>& vector_of_trains)
{
    std::string timeout;
    cout << "Введите время отправления: "; cin >> timeout;
    auto output = vector_of_trains | std::ranges::views::filter([&](const auto& v) {return v.time > timeout; });
    cout << endl;
    for (auto a : output)
    {
        cout << a << '\n';
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = NULL; cout << "Введите количество поездов: " << endl; cin >> n;
    std::vector<trains> vector_of_trains(n);
    include_trains(vector_of_trains, n);
    check_trains(vector_of_trains);
    check_time(vector_of_trains);
}
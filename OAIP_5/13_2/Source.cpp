#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <ranges>

using std::cout; using std::cin; using std::endl;

struct trains
{
    std::string name;
    std::string capital;
    int population;
    long int size;
    std::string president_surname;

    friend std::ostream& operator<<(std::ostream& os, const trains& dt);
};

std::ostream& operator<<(std::ostream& os, const trains& dt)
{
    os << dt.name << '\n' << dt.capital << '\n' << dt.population << '\n' << dt.size << '\n' << dt.president_surname << endl;
    return os;
}

void include_trains(std::vector<trains>& guesses, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int count = NULL;
        cout << endl << "Название страны: "; cin >> guesses[i].name;
        cout << endl << "Название столицы: "; cin >> guesses[i].capital;
        cout << endl << "Население:"; cin >> guesses[i].population;
        cout << endl << "Площадь страны: "; cin >> guesses[i].size;
        cout << endl << "Фамилия президента: "; cin >> guesses[i].president_surname;
    }
}

void check_trains(std::vector<trains>& vector_of_trains, int& n)
{
    std::string name;
    cout << "Введите название страны: "; cin >> name;
    auto output = vector_of_trains | std::ranges::views::filter([name](const auto& v) {return v.name == name; });
    for (auto a : output)
    {
        cout << a << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = NULL; cout << "Введите количество стран: " << endl; cin >> n;
    std::vector<trains> vector_of_trains(n);
    include_trains(vector_of_trains, n);
    check_trains(vector_of_trains, n);
}
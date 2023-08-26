#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using std::cout; using std::cin; using std::endl;

struct trains
{
    std::string name;
    std::string number;
    std::string color;
    std::string time;
    std::string type;
    std::string last_time;
    std::string own;

    friend std::ostream& operator<<(std::ostream& os, const trains& dt);

    void operator=(std::vector<std::string>& dt)
    {
        name = dt[0];
        number = dt[1];
        color = dt[2];
        time = dt[3];
        type = dt[4];
        last_time = dt[5];
        own = dt[6];
    }
};

std::ostream& operator<<(std::ostream& os, const trains& dt)
{
    os << dt.name << ' ' << dt.number << ' ' << dt.color << ' ' << dt.time << ' ' << dt.type << ' ' <<
        dt.last_time << ' ' << dt.own << endl;
    return os;
}

void include_trains(std::vector<trains>& guesses, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int count = NULL;
        cout << endl << "марка автомобиля: "; cin >> guesses[i].name;
        cout << endl << "Цвет машины: "; cin >> guesses[i].color;
        cout << endl << "Заводской номер: "; cin >> guesses[i].number;
        cout << endl << "дата выпуска:"; cin >> guesses[i].time;
        cout << endl << "Тип кузова: "; cin >> guesses[i].type;
        cout << endl << "Пследний тех. осмотр: "; cin >> guesses[i].last_time;
        cout << endl << "Владелец: "; cin >> guesses[i].own;
    }
}

void check_trains(std::vector<trains>& vector_of_trains, int& n)
{
    std::string own;
    cout << "Введите ФИО владельца: "; cin >> own;
    for (int i = 0; i < n; i++)
    {
        if (vector_of_trains[i].own == own)
        {
            cout << vector_of_trains[i];
        }
    }
}

void file_include_guess(std::vector<trains>& guesses, int& n)
{
    std::ifstream input_file("cars.txt");

    std::string line;
    std::string word;
    std::vector<std::string> buffer;

    int k = 0;

    while (std::getline(input_file, line, '\n'))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                word += line[i];
            }
            else
            {
                buffer.push_back(word);
                word.clear();
            }
        }
        guesses[k] = buffer;
        k++;
        buffer.clear();
        if (k == n)break;
    }
    cout << endl;
    for (auto a : guesses)
    {
        cout << a << '\n';
    }
    input_file.close();
}

void file_output_file(std::vector<trains>& guesses)
{
    std::ofstream file_output("Cars.txt");
    for (auto a : guesses)
    {
        file_output << a << ' ';
    }
}

void delete_guess(std::vector<trains>& guesses)
{
    std::string n;
    cout << endl << "Введите имя владельца: "; cin >> n;
    for (int i = 0; i < guesses.size(); i++)
    {
        if (guesses[i].own == n)
        {
            guesses.erase(std::next(guesses.begin(), i));
        }
    }
    for (auto a : guesses)
    {
        cout << a << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = NULL; cout << "Введите количество машин: " << endl; cin >> n;
    std::vector<trains> vector_of_trains(n);
    //file_include_guess(vector_of_trains, n);
    include_trains(vector_of_trains, n);
    check_trains(vector_of_trains, n);
    delete_guess(vector_of_trains);
    //file_output_file(vector_of_trains);
}
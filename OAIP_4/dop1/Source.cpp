#include <iostream>
#include <Windows.h>
#include <vector>
#include <ranges>
#include <algorithm>

using std::cout; using std::cin; using std::endl;

struct students
{
    std::string name_surname_other;
    int exam_count;
    std::vector<int> exam_marks;

    friend std::ostream& operator<<(std::ostream& os, const students& dt);
};

std::ostream& operator<<(std::ostream& os, const students& dt)
{
    os << dt.name_surname_other << '\n' << dt.exam_count << endl;
    for (auto a : dt.exam_marks)
    {
        os << a << '\t';
    }
    return os;
}

void include_students(std::vector<students>& guesses, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int count = NULL;
        cout << endl << "ФИО: "; cin >> guesses[i].name_surname_other;
        cout << endl << "Количество экзаменов: "; cin >> guesses[i].exam_count;
        count = guesses[i].exam_count;
        cout << endl << "Оценки за экзамены: ";
        for (int j = 0; j < count; j++)
        {
            int h = NULL; cin >> h;
            guesses[i].exam_marks.push_back(h);
        }
    }
}

void check_students(std::vector<students>& vector_of_students)
{
    int count = NULL;
    auto output = vector_of_students | std::ranges::views::filter([](const auto& v)
        {
            return std::all_of(v.exam_marks.begin(), v.exam_marks.end(), [](const auto& v1) {return v1 >= 4; });
        });
    for (auto a : output)
    {
        count++;
        cout << '\n' << a << '\t';
    }
    cout << endl << count << endl;
    cout << endl << "Успеваемость студентов: " << (double)count / (double)vector_of_students.size();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = NULL; cout << "Введите количество студентов: " << endl; cin >> n;
    std::string name_surname_other;
    std::vector<students> vector_of_students(n);
    include_students(vector_of_students, n);
    check_students(vector_of_students);
}
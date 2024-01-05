// functions with array objects(C++11)
#include <iostream>
#include <array>
#include <string>

// constant data
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(std::array<double, Seasons>* pa);
// function that uses array object without modifying it
void show(std::array<double, Seasons> da);

int main()
{
    std::array<double, Seasons> expenses;

    fill(&expenses);
    show(expenses);

    return 0;
}

void fill(std::array<double, Seasons>* pa)
{
    using namespace std;

    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";

        cin >> (*pa)[i]; // pa是一个指向array<double,4>对象的指针，因此*pa是这种对象，而(*pa)[i]是该对象的一个元素，由于运算符优先级影响，其中括号必不可少。
    }
}

void show(std::array<double, Seasons> da)
{
    using namespace std;

    double total = 0.0;
    
    cout << "\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

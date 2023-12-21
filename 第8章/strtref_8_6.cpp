#include <iostream>
#include <string>

struct free_throws
{
    std::string name;       //使用string类
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
    free_throws one = {"Ifelsa Branch", 13, 14};        //初始化剩余的percent设为0
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    display(accumulate(team, two));     //accumulate函数返回结构引用，作为display函数的参数
    accumulate(accumulate(team, three), four);
    display(team);

    dup = accumulate(team, five);       //函数返回的是引用对象，左值是结构体变量，所以将右边的值赋值到左边
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignment:\n";
    display(dup);
    set_pc(four);

    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);

    return 0;
}

void display(const free_throws & ft)    //使用引用，与按值传递结构，使用引用可节省时间和内存
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << " Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
    if(ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);      //赋值percent
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;      //函数返回的是引用对象
}


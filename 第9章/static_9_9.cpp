#include <iostream>

const int ArSize = 10;

void strcount(const char * str);

int main()
{
    using namespace std;

    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);     //cin.get将一直读取，直到达到行尾或读取了ArSize-1个字符为止。它把换行符留在输入队列中，使用cin.get(next)来读取后面的字符

    while(cin)                  //读取空行将导致cin为false
    {
        cin.get(next);
        while(next != '\n')     //如果是换行符，则说明读取了一行，否则意味着还有剩余字符没有读取（字串长度超过数组可存储范围），通过循环来丢弃剩余的字符
            cin.get(next);

        strcount(input);

        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }

    cout << "Bye\n";

    return 0;
}

void strcount(const char * str)
{
    using namespace std;

    static int total = 0;          //静态变量total只在程序启动时被初始化为0，函数调用时不会被再次初始化，在函数调用之间值不会被改变
    int count = 0;              //自动变量count在函数被调用时都会被置为0

    cout << "\"" << str << "\" contains ";
    while(*str++)
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
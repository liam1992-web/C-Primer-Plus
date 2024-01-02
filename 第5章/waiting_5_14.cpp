// using clock() in a time delay loop

#include <iostream>
#include <ctime>    // describes clock() function, clock_t type

int main()
{
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;    // CLOCKS_PER_SEC该常量等于每秒钟包含的系统时间单位数
    cout << "starting\a\n";
    clock_t start = clock();    //start存储开始时间，clock()的返回类型为clock_t,编译器将把它转换为当前系统使用的类型
    while(clock() - start < delay)      //clock函数提供目前时间，当当前时间与开始时间到达限值时，循环结束
        ;
    cout << "done \a\n";
    return 0;
}
// 该程序以系统时间为单位（而不是以秒为单位）计算延迟时间，避免了在每轮循环中将系统时间转换为秒。

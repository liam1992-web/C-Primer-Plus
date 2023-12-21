#include <iostream>
#include <ctime>

int main()
{
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";
    clock_t start = clock();    //start存储开始时间
    while(clock() - start < delay)      //clock函数提供目前时间，当当前时间与开始时间到达限值时，循环结束
        ;
    cout << "done \a\n";
    return 0;
}
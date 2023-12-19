#include <iostream>

int main()
{
    using namespace std;

    int rats = 101;
    int & rodents = rats;       //类型说明符

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;     //地址

    return 0;
}
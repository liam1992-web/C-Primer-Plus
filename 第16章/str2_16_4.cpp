//capacity() and reserve()
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";
    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;    //size方法中为使用的字符长度
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;    //capacity方法为当前对象可容纳的字符长度
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;
    empty.reserve(50);                                  //reserve方法改变当前对象的可容纳字符长度
    cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;
    return 0;
}
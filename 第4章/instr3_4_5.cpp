// reading more than one word with get()&get()
#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.get(name,ArSize).get();    //后面的get()将换行符消耗掉，get()没有参数时读取一个字符
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert,ArSize).get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}

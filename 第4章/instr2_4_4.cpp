// reading more than one string

#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    //cin >> name;       cin使用空白（空格、制表符、换行符）来确定字符串的结束位置，这意味着cin在获取字符数组时只读取一个单词
    // 且输入的字符串长度可能会比目标数组长
    cin.getline(name,ArSize);               //面向行的输入
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert,ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}

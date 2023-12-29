// line input

#include <iostream>
#include <string>
#include <cstring>

int main()
{
    using namespace std;

    char charr[20];
    string str;

    cout << "Length of string in charr before input: " << strlen(charr) << endl;
    cout << "Length of string in str before input: " << str.size() << endl;
    cout << "Enter a line of text:\n";
    cin.getline(charr, 20);     // istream类有考虑到基本类型，所有有类方法可以使用，而string类型是后面出现的
    cout << "You entered: " << charr << endl;
    cout << "Enter another lien of text:\n";
    getline(cin, str);          // 故此处使用函数，此为string类的友元函数
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: " << strlen(charr) << endl;
    cout << "Length of string in str after input: " << str.size() << endl;

    return 0;
}
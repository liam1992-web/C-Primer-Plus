// comparing strings using arrays

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string word = "?ate";
    //strcmp()函数接受两个字符串地址作为参数，参数可以是地址、字符串常量或字符数组名。如果两个字符串相同，函数返回零。如果第一个字符串按
    //字母顺序排在第二个字符串之前，则函数返回一个负数值。第一个字符串按字母顺序排在第二个字符串之后，函数返回正数值。
    for(char ch = 'a'; word != "mate"; ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }   // 循环通过数组下标访问string第一个元素，再比较，待相同时停止循环
    cout << "After loop ends, word is " << word << endl;

    return 0;
}
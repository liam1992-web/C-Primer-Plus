// different designs

#include <iostream>
#include <string>

using namespace std;

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);
const string & version3(string & s1, const string & s2);

int main()
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);    // 从输入流中读取一行字符串，直到遇到换行符
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");                        //第二个参数，将char指针赋值给string引用
    // 在version1()中，temp是一个新的string对象，只在函数中有效，函数执行完毕后，它将不再存在，因此返回指向temp的引用不可行，因此该函数返回类型为string
    // 这意味着temp的内容被复制到一个临时存储单元中，然后再main()中，该存储单元的内容被复制到一个名为result的string中
    cout << "Your string as enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "***");
    cout << "Your string as enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "***");            //当指向到此处时程序会崩溃，程序试图引用已经释放的内存
    cout << "Your string as enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    return 0;
}

string version1(const string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
}

const string & version2(string & s1, const string & s2)    // has side effect
{
    s1 = s2 + s1 + s2;
    return s1;    // safe to return reference passed to function
}

const string & version3(string & s1, const string & s2)    // bad design
{
    string temp;
    temp = s2 + s1 + s2;    // unsafe to return reference to local variable
    return temp;    //return的是临时对象，函数调用时引用导致崩溃,程序试图引用已经释放的内存
}

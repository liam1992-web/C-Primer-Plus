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
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");                        //第二个参数，将char指针赋值给string引用
    cout << "Your string as enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "***");
    cout << "Your string as enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "***");            //当指向到此处时程序会崩溃
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

const string & version2(string & s1, const string & s2)
{
    s1 = s2 + s1 + s2;
    return s1;
}

const string & version3(string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;    //return的是临时对象，函数调用时引用导致崩溃    
}
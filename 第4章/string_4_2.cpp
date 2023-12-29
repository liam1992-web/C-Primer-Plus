// storing strings in an array

#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    
    const int Size = 15;
    
    char name1[Size];
    char name2[Size] = "C++owboy";
    
    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";    // strlen()返回存储在数组中字符串的长度，不是数组本身的长度，另外长度不包含最后的空字符
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    
    return 0;
}
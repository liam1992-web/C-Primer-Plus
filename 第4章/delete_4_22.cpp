// using the delete operator

#include <iostream>
#include <cstring>

using namespace std;
char* getname(void);

int main()
{
    char * name;
    name = getname();
    cout << name << " at " << (int*)name << "\n";
    delete [] name;

    name = getname();
    cout << name << " at " << (int*)name << "\n";
    delete [] name;

    return 0;
}

char* getname()
{
    char temp[80];          // temporary storage
    cout << "Enter last name: ";
    cin >> temp;
    char* pn = new char[strlen(temp) + 1];      // 使用new申请空间
    strcpy(pn, temp);                           // 使用库函数复制内容

    return pn;                                  // 返回地址
}
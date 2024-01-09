// overloading the left() function
#include <iostream>

unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);

int main()
{
    using namespace std;

    char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    char * temp;

    for(i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;     // 第一种
        temp = left(trip, 1);           // 第二种
        cout << temp << endl;
        delete [] temp;                 // point to temporary storage
    }

    return 0;
}

// This function returns the first ct digits of the number num
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if(ct == 0 || num == 0)
        return 0;           // return 0 iff no digits

    while(n /= 10)
        digits++;       // 计算数值位数

    if(digits > ct)     // 可行性
    {
        ct = digits - ct;   // 去掉后几位
        while(ct--)
            num /= 10;

        return num;     // return left ct digits
    }
    else                // if ct >= number of digits
        return num;     // return the whole number
}

// This function returns a pointer to a new string consisting of the first n characters in the str string
char * left(const char * str, int n)
{
    if(n < 0)       // 可行性
        n = 0;

    char * p = new char[n+1];   // 申请堆空间
    int i;
    for(i = 0; i < n && str[i]; i++)    // 判定条件 需要的长度以及字符本身不是空字符
        p[i] = str[i];          // copy characters

    while(i <= n)       // 针对字符本身较短的情况增加结尾的空字符
        p[i++] = '\0';  // set rest of string to '\0'
    
    return p;   
}
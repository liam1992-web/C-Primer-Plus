#include <iostream>

const int ArSize = 8;

int sum_arr(int arr[], int n);

int main()
{
    using namespace std;

    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    
    int sum = sum_arr(cookies, ArSize);
    
    cout << "Total cookies eaten: " << sum << "\n";
    
    return 0;      
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    
    for(int i = 0; i < n; i++)
        total = total + arr[i];
    
    return total;
}
/*
    大多数情况下，数组名被视为指针
    数组声明使用数组名来标记存储位置，对数组名使用sizeof将得到整个数组的长度（以字节为单位），将地址运算符&用于数组名时将返回整个数组的地址

*/
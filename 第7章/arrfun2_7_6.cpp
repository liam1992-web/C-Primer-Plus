#include <iostream>

const int ArSize = 8;

int sum_arr(int arr[], int n);

int main()
{
    //using namespace std;

    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    
    std::cout << cookies << " = array address, ";
    std::cout << sizeof cookies << " = sizeof cookies\n";       //输出的时数组的长度

    int sum = sum_arr(cookies, ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;
    
    sum = sum_arr(cookies, 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;      
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    std::cout << arr << " = arr, ";
    std::cout << sizeof arr << " = sizeof arr\n";       //输出的是指针变量的长度
//作为函数参数传入的数组名，在函数内部作为指针变量，这是必须显式传递数组长度而不能在函数内使用sizeof计算数组长度的原因，指针本身并没有指出数组的长度
    for(int i = 0; i < n; i++)
        total = total + arr[i];
    
    return total;
}

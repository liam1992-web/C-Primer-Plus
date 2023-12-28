// small arrays of integers

#include <iostream>

int main()
{
    using namespace std;
    
    int yams[3];//creates arraywiththree elements
    
    yams[0] = 7;//asgign value to_first element
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {20, 30, 5};//ceate, initialize array
    
    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;

    cout << "The package with" << yams[1] << "yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    
    cout << "The total yam expense is" << total << "cents.\n";
    cout << "\nSize of yams array = " << sizeof yams;   // sizeof运算符用于数组名，得到的将是整个数组中的字节数
    cout << " bytes.\n";
    cout << "Size of one element  = " << sizeof yams[0];  // sizeof用于数组元素，得到的将是元素的长度，单位为字节
    cout << " byrtes.\n";

    return 0;
}
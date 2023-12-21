#include <iostream>
int main()
{
    using namespace std;
    float hats,heads;

    cout.setf(ios_base::fixed,ios_base::floatfield);    //这种调用迫使输出使用定点表示法，以便更好地了解精度，它防止程序把较大的值切换为E表示法，并使程序显示到小数点后6位
                                                        //参数ios_base::fixed和ios_base::floatfield时通过包含iostream来提供的常量
    
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;      //float，C++只保证6位有效位，将结果四舍五入成6位，可保证精度下的正确值
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;
    return 0;
}
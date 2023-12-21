#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    float tree = 3;
    int guess(3.9832);
    int debt = 7.2E12;
    cout << " tree = " << tree << endl;         //整型赋给浮点，增加小数位
    cout << "guess = " << guess << endl;        //浮点赋给整型，截断
    cout << "debt = " << debt << endl;          //浮点赋给整型，超出范围
    return 0;
}
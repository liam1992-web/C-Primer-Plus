// display values in hex and octal

#include <iostream>
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;
    // 可使用控制符dec、hex、oct，分别用于指示cout以十进制、十六进制和八进制格式显示整数
    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct;
    cout << "inseam = " << inseam << " (octal for 42)" << endl;
    return 0;
}

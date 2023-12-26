// shoes hex and octal literals

#include <iostream>
int main()
{
    using namespace std;
    int chest = 42;        // decimal integer literal
    int waist = 0x42;      // hexadecimal integer literal
    int inseam = 042;      // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";    // cout以十进制格式显示整数，而不管这些整数在程序中是如何书写的
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    return 0;
}

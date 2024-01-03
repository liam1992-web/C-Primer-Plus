// using enum

#include <iostream>

enum{red,orange,yellow,green,blue,violet,indigo};

int main()
{
    using namespace std;
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;
    while(code >= red && code <= indigo)	// 当switch语句将int值和枚举标签进行比较时，将枚举量提升为int，在while循环中也是如此
    {
        switch(code)
        {
            case red: cout << "Her lips were red.\n"; break;
            case orange: cout << "Her hair was orange.\n"; break;
            case yellow: cout << "Her shoes were yellow.\n"; break;
            case green: cout << "Her nails were green.\n"; break;
            case blue: cout << "Her sueatsuit was blue.\n"; break;
            case violet: cout << "Her eyes were violet.\n"; break;
            case indigo: cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    }
    cout << "Bye\n";
    return 0;
}

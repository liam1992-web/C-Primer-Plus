#include <iostream>
#include "tabtenn0_13_1.h"

int main(void)
{
    using std::cout;
    TableTennisPlayer player1("Chunk", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    //调用接受const char*作为参数的string构造函数

    player1.Name();
    if(player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();
    if(player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    return 0;
}
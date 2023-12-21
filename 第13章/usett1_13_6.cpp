#include <iostream>
#include "tabtenn1_13_4.h"

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

    rplayer1.Name();        //派生类对象可以使用基类的方法，但不能是私有的

    if(rplayer1.HasTable())
        cout << ":has a table.\n";
    else
        cout << ":hasn't a table.\n";
    cout << "Name: ";
    rplayer1.Name();
    cout << ";Rating: " << rplayer1.Rating() << endl;

    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << ";Rating: " << rplayer2.Rating() << endl;

    return 0;
}
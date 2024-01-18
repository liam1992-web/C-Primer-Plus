// user defined conversion functions

#include <iostream>
#include "stonewt1_11_19.h"

int main()
{
    using std::cout;

    Stonewt poppins(9, 2.8);
    double p_wt = poppins;      //隐式转换
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";

    return 0;
}

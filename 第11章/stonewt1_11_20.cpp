// Stonewt class methods + conversion functions

#include <iostream>
using std::cout;
#include "stonewt1_11_19.h"


// 1英石 = 14 磅
Stonewt::Stonewt(double lbs)        //输入磅 换算 英石
{
    stone = int (lbs) / Lbs_per_stn; //整数除法 得到英石的整数部分
    pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);   //左边的求模得到英石整数除法的剩余部分（单位时磅），右边得到磅的小数部分
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;        //输入英石
    pds_left = lbs;     //输入英石的剩余部分，单位时磅
    pounds = stn * Lbs_per_stn + lbs;   //将输入数据换算为磅
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{

}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// conversion functions
Stonewt::operator int() const
{
    return int (pounds + 0.5);		// 四舍五入
}

Stonewt::operator double() const
{
    return pounds;
}

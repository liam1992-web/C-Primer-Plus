#include <iostream>
#include "stock20_10_7.h"

const int STKS = 4;

int main()
{
    Stock stocks[STKS] = {      //对象数组创建，初始化
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for(st = 0; st < STKS; st++)
        stocks[st].show();           //数组-对象-方法
    const Stock *top = &stocks[0];      //数组-对象-地址
    for(st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);     //指针-对象-方法（对象）-对象-地址
    std::cout << "\nMost valuable holding:\n";
    top->show();    //指针-对象-方法

    return 0;
}
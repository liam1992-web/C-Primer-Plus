// some type combinations

#include <iostream>

struct antarctica_years_end
{
    int year;
    /* some really interesting data, etc. */
};

int main()
{
    antarctica_years_end s01,s02,s03;   //定义结构体变量
    s01.year = 1998;                    //结构体成员赋值

    antarctica_years_end *pa = &s02;    //定义结构体指针pa
    pa->year = 1999;                    //指向结构体成员运算符 进行赋值
    
    antarctica_years_end trio[3];       //结构体数组
    trio[0].year = 2003;                
    std::cout << trio->year << std::endl;   // 数组名是指向数组第一个元素的指针，类型为元素

    const antarctica_years_end *arp[3] = {&s01,&s02,&s03};      //数组-指针,指向结构体
    std::cout << arp[1]->year << std:: endl;

    const antarctica_years_end **ppa = arp;     //指针-指向结构体指针  二级指针
    auto ppb = arp;                             //ppb与ppa类型相同，为 结构体指针 的指针
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb + 1))->year << std::endl;       // 二级指针做指针运算，然后间接访问变为一级指针，再通过指向结构体成员运算符访问结构体成员
                                                        //二级指针，其指向结构体指针，而其为数组的首元素， 而二级指针运算的导致其指向数组的下一个元素，间接访问后变为了数组元素，数组元素本身是结构体指针，故使用 指向结构体成员运算符访问其成员
                                                        // 将指针变量加1后，其增加的值等于指向的类型占用的字节数。帮助理解ppb+1的意义
    return 0;
}


//1.第一种情况：派生类不使用new

//Base Class Using DMA，假设基类使用了动态内存分配
class baseDMA
{
    private:
        char * label;
        int rating;
    public:
        baseDMA(const char * l = "null", int r = 0);    //构造函数,默认构造函数
        baseDMA(const baseDMA & rs);                    //复制构造函数
        virtual ~baseDMA();                             //析构函数
        baseDMA & operator=(const baseDMA & rs);        //赋值运算符重载
};

/*声明中包含了构造函数使用new时需要的特殊方法：析构函数、复制构造函数和重载赋值运算符
现在，从baseDMA派生出lackDMA类，而后者不适用new，也未包含其它一些不常用的、需要特殊处理的设计特性*/

//derived class without DMA
class lacksDMA :public baseDMA
{
    private:
        char color[40];
    public:

};

/*不需要显式定义析构函数，在没有定义的情况下，编译器会定义一个不执行任何操作的默认析构函数，在执行完自身代码后会调用基类的析构函数
因为lackDMA成员不需要执行任何特殊操作，所以默认析构函数是合适的

不需要显式定义复制构造函数，在没有定义的情况下，编译器会定义一个默认复制构造函数，
派生类数据进行常规赋值，
基类的成员会使用基类的复制构造函数来复制，

对于赋值重载来说，类的默认赋值运算符将自动使用基类的赋值运算符来对基类组件进行赋值，因此，默认赋值运算符也是合适的
*/
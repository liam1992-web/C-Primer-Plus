//2.第二种情况：派生类使用new

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

//derived class with DMA
class hasDMA :public baseDMA
{
    private:
        char * style;       //use new in constructors
    public:

};

/*在这种情况下，必须为派生类定义显式析构函数、复制构造函数和赋值运算符
派生类析构函数自动调用基类的析构函数，故其自身的职责是对派生类构造函数执行工作的进行清理
因此，hasDMA析构函数必须释放指针style管理的内存，并依赖与baseDMA的析构函数来释放指针label管理的内存
*/

baseDMA::~baseDMA()
{
    delete [] label;
}

hasDMA::~hasDMA()
{
    delete [] style;
}

/*对于复制构造函数，baseDMA的复制构造函数遵循用于char数组的常规模式，即使用strlen()来获悉存储C风格字符串所需的空间、分配足够的内存
（字符数加上存储空字符所需的1个字节）并使用函数strcpy()将原始字符串复制到目的地*/
baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}
/*hasDMA复制构造函数只能访问hasDMA的数据，因此它必须调用baseDMA复制构造函数来处理共享的baseDMA数据*/
hasDMA::hasDMA(const hasDMA & hs) :baseDMA(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

/*对于赋值运算符，baseDMA遵循下述常规模式*/
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

/*由于hasDMA也使用动态内存分配，所以需要一个显式赋值运算符
作为hasDMA的方法，它只能直接访问hasDMA的数据。
但是派生类的显式赋值运算符必须负责所有继承的baseDMA基类对象的赋值，可通过显式调用基类赋值运算符来完成这项工作*/
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if(this == &hs)
        return *this;
    baseDMA::operator=(hs);     //copy base portion
    delete [] style;            //prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
/*
baseDMA::operator=(hs);     //copy base portion
通过使用函数表示法，而不是运算符表示法，可以使用作用域解析运算符
该句的含义是
    *this = hs;     //use baseDMA::operator=()
    但是如果使用运算符方式，编译器将会使用hasDMA::operator=()，从而形成递归调用
    所以使用函数表示法使得赋值运算符被正确调用
*/

//总之，当基类和派生类都采用动态内存分配时，派生类的析构函数、复制构造函数、赋值运算符都必须使用相应的基类方法来处理基类元素。
//这种要求是通过三种不同的方式来满足的。
//对于析构函数，这是自动完成的；
//对于复制构造函数，这是通过在初始化成员列表中调用基类的复制构造函数来完成的；如果不这样做，将自动调用基类的默认构造函数；
//对于赋值运算符，这是通过使用作用域解析运算符显式调用基类的赋值运算符来完成的。
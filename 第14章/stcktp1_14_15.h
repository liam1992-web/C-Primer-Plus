// modified stack template

#ifndef STCKTP1_H_
#define STCKTP1_H_

template<class Type>
class Stack
{
    private:
        enum{SIZE = 10};
        int stacksize;
        Type * items;
        int top;
    public:
        explicit Stack(int ss = SIZE);
        Stack(const Stack & st);
        ~Stack() {delete [] items;}     //析构函数删除数组，不是数组元素指向的字符串
        bool isempty() {return top == 0;};
        bool isfull() {return top == stacksize;}
        bool push(const Type & item);
        bool pop(Type & item);
        Stack & operator=(const Stack & st);
        //Stack是Stack<Type>的缩写，这种缩写只能在类中使用，即可以在模板声明或模板函数定义内使用Stack
        //在类的外面，即指定返回类型或使用作用域解析运算符时，必须使用完整的Stack<Type>
};

template <class Type>
Stack<Type>::Stack(int ss) :stacksize(ss), top(0)
{
    items = new Type [stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.items[i];
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if(top < stacksize)
    {
        items[top++] = item;        //将一个指针放在指针数组中
        return true;
    }
    else
         return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
         return false;
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if(this == &st)
        return *this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.items[i];
    return *this;
}

#endif
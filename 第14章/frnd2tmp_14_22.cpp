//template class with non template friends

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T & i) : item(i) {ct++;}
        ~HasFriend() {ct--;}
        friend void counts();  //模板所有实例化的友元，非约束友元
        friend void reports(HasFriend<T> &);    //template parameter，约束模板友元
};      //report()本身并不是模板函数，而只是使用一个模板作参数，因此要为 使用的友元定义 显式具体化

//each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;

//non template friend to all HasFriend<T> classes
void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

//non template friend to the HasFriend<int> class
void reports(HasFriend<int> & hf)       //explicit specialization for int
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

//non template friend to the HasFriend<double> class
void reports(HasFriend<double> & hf)    //explicit specialization for double 
{
    cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();
    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();
    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();
    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);

    return 0;
}
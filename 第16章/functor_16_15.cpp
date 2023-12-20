//using a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>
class TooBig
{
    private:
        T cutoff;
    public:
        TooBig(const T & t) : cutoff(t) {}
        bool operator() (const T & v) {return v > cutoff;}
};

void outint(int n) {std::cout << n << " ";}

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100);
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    
    yadayada.remove_if(f100);                   //将链表中的元素与 f100的cutoff作比较,调用operator()
    etcetera.remove_if(TooBig<int>(200));          //将链表中的元素进行构造，然后与200进行比较，调用operator()
    
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    
    return 0;
}

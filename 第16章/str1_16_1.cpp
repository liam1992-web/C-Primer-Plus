//introducing the string class
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string one("Lottery Winner!");  //string(const char * s) ,将string对象初始化为s指向的NBTS,即以空字符结束的字符串，即传统的C字符串
    cout << one << endl;
    
    string two(20, '$');    //string(size_type n, char c) ,创建一个包含n个元素的string对象，其中每个元素都被初始化为字符c
    cout << two << endl;

    string three(one);      //string(const string & str) ,将一个string对象初始化为string对象str(复制构造函数)
    cout << three << endl;

    one += "Oops!";
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';

    string four;        //创建一个默认的string对象，长度为0（默认构造函数）
    four = two + three;
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 20);      //string(const char * s, size_type n) ,将string对象初始化为s指向的NBTS的前n个字符，即使超过了NBTS结尾
    cout << five << "!\n";
    
    string six(alls+6, alls + 10);  //template<class Iter>
    cout << six << ", ";            //string(Iter begin, Iter end)  ,将string对象初始化为区间[begin,end)内的字符，其中begin和end的行为就像指针，用于指定位置，范围保活begin在内，但不包括end

    string seven(&five[6], &five[10]);  //不能使用five[6],这这是一个char值，此处需要的是地址
    cout << seven << "...\n";

    string eight(four, 7, 16);      //string(const string & str, string size_type pos = 0, size_type n = npos) ,将一个string对象初始化为对象str中从位置pos开始到结尾的字符,或从位置pos开始的n个字符
    cout << eight << " in motion!" << endl;

    return 0;
}
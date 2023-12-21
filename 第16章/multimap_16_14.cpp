//use a multimap
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;

    MapCode codes;
    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    cout << "Number of cities with area code 415: "
        << codes.count(415) << endl;    //成员函数count()接受键作为参数，并返回具有该键的元素数目
    cout << "Number of cities with area code 718: "
        << codes.count(718) << endl;
    cout << "Number of cities with area code 510: "
        << codes.count(510) << endl;

    cout << "Area Code City\n";
    MapCode::iterator it;
    for(it = codes.begin(); it != codes.end(); ++it)
        cout << "   " << (*it).first << "   " << (*it).second << endl;

    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);  //equal_range()用键作为参数，且返回两个迭代器，它们表示的区间与该键匹配。
                                                                                //为返回两个值，该方法将它们封装在一个pair对象中，这里pair的两个模板参数都是迭代器
    cout << "Cities with area code 718:\n";
    for(it = range.first; it != range.second; ++it)     //对于pair对象，可以使用first和second成员来访问其两个部分
    {
        printf("range.first = %p",range.first);
        printf("range.second = %s",range.second);
        cout << (*it).second << endl;
    }
    return 0;
}
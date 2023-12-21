//some set operations
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
    using namespace std;

    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A(s1, s1 + N);  //initialize set A using a range from array
    set<string> B(s2, s2 + N);  //对于set来说，值就是键，键是唯一的，在数组中出现过两次的，在集合中只会出现一次，而且集合被排序

    ostream_iterator<string, char> out(cout, " ");

    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);     //集合A与集合B的并集：两个集合合并后的内容，如果两个集合包含相同的值，这这个值只会出现一次
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);      //集合的交集：两个集合都有的元素
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);        //集合的差：第一个集合减去两个集合都有的元素
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));  //对于要将结果放到集合C中，而不是显示它，最后一个参数应是一个指向C的迭代器
    //不能使用C.begin()，关联集合将键看作常量，C.begin()返回的迭代器是常量迭代器，不能用作输出迭代器
    //另外set_union()将覆盖容器中已有的数据，并要求容器有足够的空间容纳新信息，C是空的，不能满足这种要求
    //模板insert_iterator可以解决这两个问题，它可以将复制转换为插入，另外它还模拟了输出迭代器概念，可以用它将信息写入容器
    //因此可以创建一个匿名的 insert_iterator，将信息复制给C，其构造函数将容器名称和迭代器作为参数 insert_iterator<set<string>>(C, C.begin())
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);       //插入后会自动排序
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    /*
    set方法 lower_bound()和 upper_bound()
    方法 lower_bound()将键作为参数并返回一个迭代器，该迭代器指向集合中第一个不小于键参数的成员。
    方法 upper_bound()将键作为参数，并返回一个迭代器，该迭代器指向集合中第一个大于键参数的成员。
    */
    cout << endl;

    return 0;
}
//copy() and iterators
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    using namespace std;

    int casts[10] = {6,7,2,9,4,11,8,7,10,5};

    vector<int> dice(10);
    
    copy(casts, casts + 10, dice.begin());
    //copy()前两个迭代器参数表示要复制的范围[),最后一个参数表示要将第一个元素复制到什么位置
    //前两个参数最好是输入迭代器，最后一个参数是输出迭代器
    cout << "Let the dice be cast!\n";

    ostream_iterator<int, char> out_iter(cout, " ");
    //out_iter迭代器现在是一个接口，使得可以使用cout来显示信息
    //第一个模板参数(int)指出了被发送给输出流的数据类型；第二个模板参数(char)指出了输出流使用的字符类型
    //构造函数的第一个参数(cout)指出了要使用的输出流，它也可以是用于文件输出的流
    //最后一个字符串参数是在发送给输出流的每个数据项后显示的分隔符

    copy(dice.begin(), dice.end(), out_iter);   //copy vector to output stream
    cout <<endl;

    cout << "Implicit use of reverse iterator.\n";
    copy(dice.rbegin(), dice.rend(), out_iter); //display in reverse order
    cout << endl;
    //vector类有一个名为rbegin()的成员函数和一个名为rend()的成员函数
    //前者返回一个指向超尾的反向迭代器，后者返回一个指向第一个元素的反向迭代器
    //对迭代器执行递增操作将导致它被递减

    cout << "Explicit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri;
    //对reverse_iterator执行递增操作将导致它被递减，使用此种迭代器主要是为了简化对已有函数的使用
    //反向指针通过先递减，再解除引用来解决普通指针方式下的问题
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;

    return 0;
}
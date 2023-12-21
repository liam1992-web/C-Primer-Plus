//use several STL elements
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;
//得到一个按输入顺序排列的单词列表、一个按字母顺序排列的单词列表，并记录每个单词被输入的次数
char toLower(char ch) {return tolower(ch);}
string & ToLower(string & st);
void display(const string & s);

int main()
{
    vector<string> words;

    cout << "Enter words (enter quit to quit):\n";
    string input;
    while(cin >> input && input != "quit")
        words.push_back(input);     //输入，保存
    
    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;       //显示

    set<string> wordset;  
    //set容器是一个有序集合，其中每个元素都是唯一的。它内部使用红黑树实现，可以保证元素的自动排序和快速查找。set容器中的元素类型必须支持小于运算符（<）或等于运算符（==）。
    transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);     
    //将矢量中的单词复制（使用插入迭代器）到集合中，集合自动对其内容进行排序，且同一个键只出现一次
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    map<string, int> wordmap;
    /*
    C++中的map容器是STL（标准模板库）中的一个关联容器，它提供了一个键值对（key-value）的存储结构，非常适合用于一对一的数据映射。
    map内部实现是基于红黑树，因此它能提供自动排序的功能，并且插入、删除和查找操作的平均时间复杂度为O(log n)。
    另外，map容器中的元素是有序的，这使得我们可以轻松地通过键来查找对应的值。
    创建map容器的方式有多种。例如，可以通过调用默认构造函数创建一个空的map容器，
    如：`std::map<std::string, int> myMap;` 这种方式可以创建出一个空的没有任何键值对的map容器。
    此外，也可以在创建的同时进行初始化，比如：`std::map<std::string, int> myMap = {{"apple", 1}, {"banana", 2}, {"orange", 3}};` 这样就可以创建一个含有若干键值对的map容器。
    */
    set<string>::iterator si;
    for(si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] = count(words.begin(), words.end(), *si);
    /*
    要获得每个单词在输入中出现的次数，可以使用count()函数。它将一个区间和一个值作为参数，并返回这个值在区间中出现的次数。
    可以使用 vector 对象来提供区间，并使用 set 对象来提供要计算其出现次数的单词列表。
    即对于集合中的每个词，都计算它在矢量中出现的次数。
    要将单词与其出现的次数关联起来，可将单词和计数作为pair<const string,int>对象存储在map 对象中。
    单词将作为键（只出现一次);计数作为值。这可以通过一个循环来完成:
    */
    /*
    map类有一个有趣的特征:可以用数组表示法（将键用作索引）来访问存储的值。
    例如，wordmap[“the”]表示与键“the”相关联的值，这里是字符串“the”出现的次数。
    因为wordset容器保存了wordmap 使用的全部键，因为 si 指向wordset 容器中的一个字符串，所以*si是一个字符串，可以用作 wordmap 的键。
    上述代码将键和值都放到 wordmap 映象中。
    */
    cout << "\nWord frequency:\n";
    for(si = wordset.begin(); si != wordset.end(); si++)
        cout << *si << ": " << wordmap[*si] << endl;
    
    return 0;
}

string & ToLower(string & st)   //将字串按引用传递和返回意味着算法不必复制字符串，而可以直接操作原始字符串
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string & s)
{
    cout << s << " ";
}
//copy() and insert iterators
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

void output(const std::string & s) {std::cout << s << " ";}

int main()
{
    using namespace std;

    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};
    
    vector<string> words(4);
/*
创建一个包含4个空字符串的vector容器的语句。
解析：
- `vector` 是一个动态数组，它可以自动调整大小以适应元素的数量。
- `<string>` 是一个模板参数，表示这个vector容器的元素类型是字符串（string）。
- `words` 是这个vector容器的名称。
- `(4)` 是构造函数的参数，表示这个vector容器的初始容量为4。这意味着在创建这个容器时，它已经分配了足够的内存来存储4个字符串。但是，这些字符串还没有被初始化，所以它们的值是未定义的。
*/
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    //construct anonymous back_insert_iterator object
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    //construct anonymous insert_iterator object
    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), output);
    cout << endl;
    
    return 0;
}

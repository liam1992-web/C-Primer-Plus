// reversing an array

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;
    
    char temp;    // temp在循环外声明，若将其放在循环体中会在每轮循环中都被分配和释放，这样允许速度会慢一些，另外在内部时循环结束temp将消失
    int i,j;     //comma is a separator here, not an operator，在此处声明i,j 在for循环控制的初始化部分无法声明两条语句
    for(j = 0,i = word.size() - 1; j < i; --i,++j)    //使用逗号运算符，将两条或更多语句放到C++句法只能放一条语句的地方
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << "\nDone\n";
    return 0;
}

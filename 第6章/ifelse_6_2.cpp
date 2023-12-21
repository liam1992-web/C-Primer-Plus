#include <iostream>

int main()
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";
    std::cin.get(ch);
    while(ch != '.')
    {
        if(ch == '\n')
            std::cout << ch;
        else
            std::cout << ++ch;      //使用自增后，输出下一个字符
            //std::cout << ch+1;        使用+1后，输出为数值
        std::cin.get(ch);
    }
    std::cout << "\nPlease excuse the slight confusion.\n";
    return 0;
}
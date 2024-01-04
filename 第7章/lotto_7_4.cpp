// probability of winning

#include <iostream>
// Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;

    double total, choices;

    cout << "Enter the total number of choices on the game card and\n"
        "the number of picks allowed:\n";

    while((cin >> total >> choices) && choices <= total)        //使用cin输入两个值
    {
        cout << "You have one chance in ";
        cout << probability(total, choices);            //在使用cout输出字符串中 输出数值（函数返回值）,compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }

    cout << "bye\n";

    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;	// here come some local variables
    long double n;
    unsigned p;

    for(n = numbers,p = picks; p > 0; n--, p--)
        result = result * n / p;        //交替进行乘除运算可以防止中间结果过大，超出范围
    
    return result;
}

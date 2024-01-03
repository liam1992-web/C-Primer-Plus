// use the ctype.h library

#include <iostream>
#include <cctype>	// prototypes for character functions

int main()
{
    using namespace std;
    cout << "Enter text for  analysis, and type @"
            " to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);	// get first character
    while(ch != '@')
    {
        if(isalpha(ch))	// is it an alphabetic character? 如果使用'a''z'来进行判断，默认字母的字符编码是连续的，其他字符编码不在这个范围内，这个假设对于ASCII是成立的，但通常并非如此
            chars++;
        else if(isspace(ch))	//is it an whitespace character? 空白字符计数包括换行符
            whitespace++;
        else if(isdigit(ch))	// is it a digit?
            digits++;
        else if(ispunct(ch))	// is it punctuation?
            punct++;
        else 
            others++;
        cin.get(ch);		// get next character
    }
    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    return 0;
}

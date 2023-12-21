//some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;

const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal", 
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy"};

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower; //C++标准库中的函数，用于将大写字母转换为小写字母，头文件为<cctype>
    using std::endl;

    std::srand(std::time(0));
    char play;

    cout << "Will you play a word game? <y/n> ";

    cin >> play;
    play = tolower(play);

    while(play == 'y')  //开始游戏
    {
        string target = wordlist[std::rand() % NUM];    //target中为wordlist数组中的随机元素
        int length = target.length();       //length()返回字符串的长度/整数，不包含空字符'\0'
        string attempt(length, '-');        //将attempt构造为由length个'-'构成的string对象
        string badchars;                    //创建一个默认的string对象，长度为0
        int guesses = 6;

        cout << "Guess my secret word. It has " << length << " letters, and you guess\n" << "one letter at a time. You get " << guesses << " wrong guesses.\n";         //游戏信息：单词长度，试错次数
        cout << "Your word: " << attempt << endl;       //初始字符
        while(guesses > 0 && attempt != target)     //运算符重载，比较对象 进行猜字符
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if(badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)       //find()查找字符letter在对象中首次出现的位置，否则返回string::npos  此处确认字符是否在猜对字符或猜错字符串中出现过
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);
            if(loc == string::npos)         //无此字符时进行记录
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;     //将一个字符添加到字符串中
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while(loc != string::npos)          //进行循环查找相同字符
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;       //输出当前字符

            if(attempt != target)
            {
                if(badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }

        if(guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}
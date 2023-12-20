//auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>

int main()
{
    using namespace std;
    auto_ptr<string> films[5] =
    {
        auto_ptr<string> (new string("Fowl Balls")),        //<string>将获得指向string类型的auto_ptr； new string是new返回的指针，指向新分配的内存块
        auto_ptr<string> (new string("DUck Walks")),
        auto_ptr<string> (new string("Chicken Runs")),
        auto_ptr<string> (new string("Turkey Errors")),
        auto_ptr<string> (new string("Goose Eggs"))
    };
    auto_ptr<string> pwin;
    pwin = films[2];        //此处导致出现错误
    cout << "The nominees for best avian baseball film are\n";
    for(int i = 0; i < 5; i++)
        cout << *films[i] << endl;      //films[2]为空
    cout << "The winner is " << *pwin << "!\n";
    cin.get();
    return 0;
}
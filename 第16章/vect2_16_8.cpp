//methods and iterators
#include <iostream>
#include <string>
#include <vector>

struct Review{
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::vector;

    vector<Review> books;   //对象
    Review temp;        //结构体

    while(FillReview(temp))
        books.push_back(temp);  //向对象中添加元素
    
    int num = books.size();

    if(num > 0)
    {
        cout << "Thank you. You entered the following:\n" 
            << "Rating\tBook\n";
        for(int i = 0; i < num; i ++)
            ShowReview(books[i]);

        cout << "Reprising:\n" 
            << "Rating\tBook\n";

        vector<Review>::iterator pr;    //迭代器
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        vector<Review>oldlist(books);   //构造

        if(num > 3)
        {
            books.erase(books.begin() + 1, books.begin() + 3);  //删除
            cout << "After erasure:\n";
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);

            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);  //插入
            cout << "After insertion:\n";
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }

        books.swap(oldlist);       //交换两个容器的内容
        cout << "Swapping oldlist with books:\n";
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin)
        return false;
    while(std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}
//using valarray slices
#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;
void show(const vint & v, int cols);

int main()
{
    using std::slice;
    using std::cout;

    vint valint(SIZE);

    int i;
    for(i = 0; i < SIZE; ++i)
        valint[i] = std::rand() % 10;   //初始化
    
    cout << "Original array:\n";
    show(valint, 3);                    //输出，一列3个元素

    vint vcol(valint[slice(1, 4, 3)]);      //重载(),用slice类对象初始化vint vcol
    cout << "Second column:\n";
    show(vcol, 1);

    vint vrow(valint[slice(3, 3, 1)]);      //重载(),用slice类对象初始化vint vrow
    cout << "Second row:\n";
    show(vrow, 3);

    valint[slice(2, 4, 3)] = 10;        //对一组值进行赋值
    cout << "Set last column to 10:\n";
    show(valint, 3);
    
    cout << "Set first column to sum of next two:\n";
    valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);   //创建完整的valint对象执行加法运算
    show(valint, 3);
    
    return 0;
}

void show(const vint & v, int cols)
{
    using std::cout;
    using std::endl;

    int lim = v.size();
    for(int i = 0; i < lim; ++i)
    {
        cout.width(3);
        cout << v[i];
        if(i % cols == cols - 1)
            cout << endl;
        else    
            cout << ' ';
    }
    if(lim %  cols != 0)
        cout << endl;
}
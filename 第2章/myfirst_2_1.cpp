//displays a message
#include <iostream>
//使用cin和cout进行输入和输出程序必须包含文件iostream
int main()
{
	using namespace std;
	cout << "Come up and C++ me some time.";
	cout << endl;
	cout << "You won't regret it!" << endl;
	cin.get();	//保证窗口一直打开，直到按下任何按键
	return 0;
}
//endl将导致屏幕光标移动到下一行开头

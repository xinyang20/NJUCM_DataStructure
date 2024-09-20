#include <iostream>
#include <string.h>
using namespace std;
#include "LinkPriorityQueue.h"

/*
编写一个程序，模拟病人（基本信息有就诊号和姓名，其中就诊号每天从1开始累计）到医院看病，排队看医生的情形。在病人排队的过程中，主要发生两件事。
1）、病人挂号，到诊室门口候诊。
2）、轮到某个号，该号对应的病人进入诊室就诊。
要求程序采用菜单方式，其选项及功能说明如下：
1）挂号候诊——更新待诊病人信息，新挂号的出现在最后。
2）叫号就诊——输出即将就诊的病人（队列中排最前面的病人）信息，该病人进入诊室就诊，更新待诊病人信息,已就诊的病人不再出现。
3）查询——输出前面需要等的人数。
4） 退出——退出运行。
*/



class sicker {
public:
	sicker();
	sicker(string num, string name);
	sicker(const sicker& other);
	string GetNumber() { return number; }
	string GetName() { return name; }
private:
	string number;//就诊号
	string name;//姓名
};
sicker::sicker()
{
	number = "None";
	name = "None";
}
sicker::sicker(string num, string name)
{
	this->number = num;
	this->name = name;
}
sicker::sicker(const sicker& other)
{
	this->name = other.name;
	this->number = other.number;
}
const string priority_char[4] = { "","危","急","普" };
int num[4] = { 0,1,1,1 };
LinkPriorityQueue<sicker> SL;

void Register(string name, int priority) {
	string number = priority_char[priority];
	number += (char)(num[priority] + (int)('0'));
	num[priority]++;
	sicker s(number, name);
	SL.Push(s, priority);
	cout << "挂号成功，您的就诊号为：" << number << endl;
}

void call() {
	sicker s(SL.Get());
	cout << "请" << s.GetNumber() << "号：" << s.GetName() << "就诊。" << endl;
	SL.Pop();
}

int wait_number(string x) {
	int priority;
	if (x.substr(0, 2) == "危")priority = 1;
	else if (x.substr(0, 2) == "急")priority = 2;
	else if (x.substr(0, 2) == "普")priority = 3;
	else throw"就诊号不合法";
	int np = 1, count = 0;
	while (np < priority) {
		count = SL.Priority_Length(np);
		np++;
	}
	int now_num = 0, num = 0;
	for (int i = 2; x[i] != '\0'; i++)
		num = num * 10 + (int)(x[i] - (int)('0'));
	string nx = SL.Priority_Get(priority).GetNumber();
	for (int i = 2; nx[i] != '\0'; i++)
		now_num = now_num * 10 + (int)(nx[i] - (int)('0'));
	count += num - now_num;
	return count;
}

void guahao() {
	system("cls");
	string name;
	int priority;
	cout << "---------- 挂  号 ----------" << endl;
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入紧急程度（1为危重，2为紧急，3为普通）：";
	cin >> priority;
	Register(name, priority);
	system("pause");
}

void Call() {
	call();
	system("pause");
}

void search() {
	system("cls");
	cout << "---------- 挂  号 ----------" << endl;
	cout << "请输入就诊号：";
	string num;
	cin >> num;
	cout << "等待人数：" << wait_number(num) << endl;
	system("pause");
}

void test() {
	Register("张三", 1);
	Register("李四", 2);
	Register("王五", 2);
	Register("李六", 3);
	call();
	call();
	Register("赵七", 3);
	Register("钱八", 2);
	Register("孙九", 2);
	cout << "插入危2前，急3前面还有：" << wait_number("急3") << "人" << endl;
	Register("李十", 1);
	cout << "插入危2后，急3前面还有：" << wait_number("急3") << "人" << endl;
	Register("高玖", 2);
	call();
	call();
	Register("顾十", 2);
	Register("夏菲", 3);
	system("pause");
}

void menu(bool& IsRun, bool clear = true) {
	int input;
	if (clear)system("cls");
	cout << "---------- 菜 单 ----------" << endl;
	cout << "1.患者挂号" << endl;
	cout << "2.医生叫号" << endl;
	cout << "3.查询等待人数" << endl;
	cout << "4.运行测试" << endl;
	cout << "0.退出系统" << endl;
	cin >> input;
	switch (input)
	{
	case 0:
		IsRun = false;
		break;
	case 1:
		guahao();
		break;
	case 2:
		Call();
		break;
	case 3:
		search();
		break;
	case 4:
		test();
		break;
	default:
		system("cls");
		cout << "输入非法,请重新输入：" << endl;
		menu(IsRun, false);
		break;
	}
}

int main() {
	bool IsRun = true;
	while (IsRun)
		menu(IsRun);
	return 0;
}
#include <iostream>
using namespace std;
#include "LinkQueue.h"

/*
编写一个程序，模拟病人（基本信息有就诊号和姓名，其中就诊号每天从1开始累计）到医院看病，排队看医生的情形。
在病人排队的过程中，主要发生两件事。
1）、病人挂号，到诊室门口候诊。
2）、轮到某个号，该号对应的病人进入诊室就诊。
要求程序采用菜单方式，其选项及功能说明如下：
1）挂号候诊——更新待诊病人信息，新挂号的出现在最后。
2）叫号就诊——输出即将就诊的病人（队列中排最前面的病人）信息，该病人进入诊室就诊，更新待诊病人信息，
   已就诊的病人不再出现。
3）查询——输出前面需要等的人数。
4） 退出——退出运行。
*/



class sicker {
public:
	sicker();
	sicker(int num, char* name);
	sicker(const sicker& other);
	int GetNumber() { return number; }
	char* GetName() { return name; }
private:
	int number;//就诊号
	char* name;//姓名
};
sicker::sicker()
{
	number = -1;
	char Name[5] = "none";
	name = Name;
}
sicker::sicker(int num, char* name)
{
	number = num;
	this->name = name;
}
sicker::sicker(const sicker& other)
{
	this->name = other.name;
	this->number = other.number;
}

int num = 1;//当前挂号量+1
LinkQueue<sicker> SL;

void Register(char* name) {
	sicker* s = new sicker(num, name);
	SL.EnQueue(*s);
	cout << "挂号成功，您的就诊号为：" << num << endl;
	num++;
}

void call() {
	sicker s(SL.GetQueue());
	cout << "请" << s.GetNumber() << "号：" << s.GetName() << "就诊。" << endl;
	SL.DeQueue();
}

int wait_number(int x) {
	sicker shead(SL.GetQueue());
	int count = x - shead.GetNumber();
	return count;
}

void guahao() {
	system("cls");
	char a[10];
	cout << "---------- 挂  号 ----------" << endl;
	cout << "请输入姓名：";
	cin >> a;
	Register(a);
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
	int num;
	cin >> num;
	cout << "等待人数：" << wait_number(num) << endl;
	system("pause");
}

void menu(bool &IsRun) {
	int input;
	system("cls");
	cout << "---------- 菜 单 ----------" << endl;
	cout << "1.患者挂号" << endl;
	cout << "2.医生叫号" << endl;
	cout << "3.查询等待人数" << endl;
	cout << "0.退出系统" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		guahao();
		break;
	case 2:
		Call();
		break;
	case 3:
		search();
		break;
	default:
		IsRun = false;
		break;
	}
}

int main() {
	bool IsRun = true;
	while (IsRun) {
		menu(IsRun);
	}
	return 0;
}



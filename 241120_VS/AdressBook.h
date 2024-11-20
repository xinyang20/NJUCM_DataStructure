#pragma once
#include <string>
#include <algorithm>
typedef long long ll;


struct User {
	ll ID;
	string Name;
	string Telephone;
	User& operator=(const User& other) {
		if (this != &other) {
			ID = other.ID;
			Name = other.Name;
			Telephone = other.Telephone;
		}
		return *this;
	}
};

class AdressBook {
public:
	AdressBook(int MaxSize);
	AdressBook(AdressBook* other);
	bool Insert(string name, string tel);
	//bool Delete(std::string name, ll id = -1);
	//bool Delete(std::string name, std::string tel);
	//bool ChangeName(std::string name, std::string newname, ll id = -1);
	//bool ChangeTel(std::string name, std::string newtel, ll id = -1);
	void SeqSearch(string name, ll id = -1);
	void HalfSearch(string name, ll id = -1);
	void Show(bool ShowID = false);
	void Sort(int way);
private:
	User* user;
	int Num;
	int MaxSize;
	void QuickSort();
};


AdressBook::AdressBook(int size)
{
	user = new User[size + 5];
	MaxSize = size;
	Num = 0;
}

AdressBook::AdressBook(AdressBook* other)
{
	this->MaxSize = other->MaxSize;
	this->Num = other->Num;
	user = new User[MaxSize+5];
	for (int i = 1; i <= Num; i++)
	{
		this->user[i].ID = other->user[i].ID;
		this->user[i].Name = other->user[i].Name;
		this->user[i].Telephone = other->user[i].Telephone;
	}
}

bool AdressBook::Insert(string name, string tel)
{
	Num++;
	user[Num].ID = Num;
	user[Num].Name = name;
	user[Num].Telephone = tel;
	cout << "����ɹ�,��ǰ������"<<Num<<"/"<<MaxSize<<"\n";
	return true;
}

//bool AdressBook::Delete(std::string name, ll id = -1)
//{
//	if (id != -1) {
//		std::cout << "�ݲ�֧��ͨ��IDɾ��\n";
//	}
//	else {
//		for (int i = 1; i <= Num; i++) {
//			if (user[i].Name != name)
//				continue;
//			else {
//
//			}
//		}
//	}
//	return false;
//}
//
//bool AdressBook::Delete(std::string name, std::string tel)
//{
//	return false;
//}
//
//bool AdressBook::ChangeName(std::string name, std::string newname, ll id)
//{
//	return false;
//}
//
//bool AdressBook::ChangeTel(std::string name, std::string newtel, ll id)
//{
//	return false;
//}

void AdressBook::SeqSearch(string name, ll id )
{
	cout << "SeqSearch������Num=" << Num << endl;
	for (int i = 1; i <= Num; i++) {
		if (user[i].Name != name) {
			cout << "���ҵ�������Ϣ��\n";
			cout << user[i].Name << "\t" << user[i].Telephone << '\n';
			continue;
		}
		else {
			cout << "����\t\t����\n";
			cout << user[i].Name << "\t\t" << user[i].Telephone << endl;
		}
	}
	cout << "δ���ҵ���Ӧ����Ϣ\n";
}

void AdressBook::HalfSearch(string name, ll id )
{
	int head = 1, tail = Num;
	int mid;
	while (head < tail) {
		mid = (head + tail) / 2;
		if (user[mid].Name == name) {
			cout << "����\t\t����\n";
			cout << user[mid].Name << "\t\t" << user[mid].Telephone << endl;
		}
		else if (user[mid].Name > name)
			tail = mid;
		else if (user[mid].Name < name)
			head = mid;
	}
}

void AdressBook::Show(bool ShowID )
{
	if (ShowID)cout << "  ID\t\t";
	cout << "����\t\t����\n";
	for (int index = 1; index <= Num; index++) {
		if (ShowID)cout << user[index].ID << "\t\t";
		cout << user[index].Name << "\t\t" << user[index].Telephone << endl;
	}
}

bool cmp(User a, User b) {
	if (a.Name < b.Name)return true;
	else return false;
}

void AdressBook::Sort(int way)
{
	switch (way) {
	case 1:
		QuickSort();
		break;
	default:
		std::sort(user, user + Num, cmp);
	}
}

void AdressBook::QuickSort()
{

}

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool isalpha(char ch) {
	if (ch >= 'a' && ch <= 'z')return true;
	return false;
}

int main() {
	map<string, int> words;
	string word;
	ifstream artical;
	ofstream artical_processed;
	artical_processed.open("artical_processed.txt");
	artical.open("artical.txt", ios::in);
	while (artical >> word) {
		for (char& ch : word)
			ch = tolower(ch);
		string new_word;

		for (const char& ch : word)
			if(isalpha(ch)||ch=='\'')new_word += ch;

		artical_processed << new_word << "\n";
	}
	artical.close();
	artical_processed.close();
	artical.open("artical_processed.txt", ios::in);
	while (artical >> word) {
		if (words.find(word) == words.end())
			words[word] = 0;
		words[word]++;
	}
	cout << "文件读取完成。" << '\n';
	cout << "请输入需要查询的单词：";
	string searchword;
	cin >> searchword;
	if (words.find(searchword)==words.end())
		cout << "所查询的单词在该文章中不存在\n";
	else cout << "单词 " << searchword << " 在文章中出现了： " << words[searchword] << " 次。" << '\n';
	return 0;
}
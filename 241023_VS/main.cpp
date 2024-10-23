#include <iostream>
#include <string>
#include <climits>
#include <map>

using namespace std;

struct HuffmanNode {
	char ch;
	int weight;
	int parent, lchild, rchild;
};

HuffmanNode charArr[200 + 10];

void ShowHaff(const HuffmanNode arr[], const int index, string haff, map<string, char>& decode, map<char, string>& encode) {
	if (arr[index].ch != '\\') {
		cout << arr[index].ch << " : " << haff << "\n";
		encode[arr[index].ch] = haff;
		decode[haff] = arr[index].ch;
		return;
	}
	ShowHaff(arr, arr[index].lchild, haff + "0", decode, encode);
	ShowHaff(arr, arr[index].rchild, haff + "1", decode, encode);
}

void SelectMinTwo(HuffmanNode arr[], int length, int& i1, int& i2) {
	if (arr[0].weight < arr[1].weight)
		i1 = 0, i2 = 1;
	for (int i = 0; i < length; i++) {
		if (arr[i].weight < arr[i1].weight) {
			i2 = i1;
			i1 = i;
		}
		else if (arr[i].weight < arr[i2].weight) {
			i2 = i;
		}
	}
}

void Encode(const map<char, string>& encode) {
	string input, output;
	cout << "请输入需要编码的文本串：";
	cin >> input;
	int i = 0;
	while (input[i] != '\0') {
		output = output + encode.at(input[i]);
		i++;
	}
	cout << "编码结果：" << output << endl;
}

void Decode(const map<string, char>& decode) {
	string input, output;
	cout << "请输入需要解码的文本串：";
	cin >> input;
	char first = input[0];
	string ins;
	ins = ins + first;
	int i = 1;
	while (input[i] != '\0') {
		ins = ins + input[i];
		if (decode.count(ins) != 0) {
			output = output + decode.at(ins);
			ins.clear();
		}
		i++;
	}
	cout << "解码结果：" << output << endl;
}

int main() {
	map<string, char> decode;
	map<char, string> encode;
	int n;
	cout << "输入字符集长度：";
	cin >> n;
	cout << "请逐个输入字符与权值\n";
	for (int i = 0; i < n; i++) {
		cin >> charArr[i].ch >> charArr[i].weight;
		charArr[i].parent = charArr[i].lchild = charArr[i].rchild = -1;
	}
	for (int i = n; i < 2 * n - 1; i++) {
		int i1, i2;
		SelectMinTwo(charArr, i, i1, i2);
		charArr[i].weight = charArr[i1].weight + charArr[i2].weight;
		charArr[i].lchild = i1;
		charArr[i].rchild = i2;
		charArr[i].ch = '\\';
		charArr[i1].weight = INT_MAX;
		charArr[i1].parent = i;
		charArr[i2].weight = INT_MAX;
		charArr[i2].parent = i;
	}

	string haff;
	ShowHaff(charArr, 2 * n - 2, haff, decode, encode);

	Encode(encode);

	Decode(decode);

	return 0;
}
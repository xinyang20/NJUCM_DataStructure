#include<iostream>
#include<fstream>
#include<string.h>
#include<climits>
using namespace std;
#define MAXLEN 2000
typedef struct {
	char chars;
	int weight;
	int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode;

typedef struct {
	char chars;
	int weight;
} InputData;



//inputData存储了每个叶子节点对应的字符和权值（从1号单元开始），n为叶子节点个数
//返回构造好的哈夫曼树的首地址
HuffmanTree CreatHuffmanTree(int n, InputData* inputData) {
	//代码开始
	HuffmanTree HT = new HTNode[2 * n];
	for (int i = 1; i <= n; i++) {
		HT[i].chars = inputData[i].chars;
		HT[i].weight = inputData[i].weight;
		HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
	}
	for (int num = n + 1; num < 2 * n; num++) {
		int p = -1, q = -1;
		for (int i = 1; i < num; i++) {
			if (HT[i].parent == 0) {
				if (p == -1 || HT[i].weight < HT[p].weight) {
					q = p;
					p = i;
				} else if (q == -1 || HT[i].weight < HT[q].weight) {
					q = i;
				}
			}
		}
		HT[num].chars = '\\';
		HT[num].weight = HT[p].weight + HT[q].weight;
		HT[num].lchild = p;
		HT[num].rchild = q;
		HT[p].parent = num;
		HT[q].parent = num;
	}
	return HT;
	//代码结束
}


//用HC返回每个叶子节点的哈夫曼编码
HuffmanCode CreatHuffmanCode(HuffmanTree HT, int n) {
	//代码开始
	HuffmanCode HC = new char*[n + 3];
	for (int i = 1; i <= n; i++) {
		HC[i] = new char[n + 5];
		// HC[i][0]=HT[i].chars;//字符自身
		int lastNode = 0, nowNode = i;
		int length = 0;
		while (HT[nowNode].parent != 0) {
			lastNode = nowNode;
			nowNode = HT[nowNode].parent;
			if (lastNode == HT[nowNode].lchild)
				HC[i][length++] = '0';
			else if (lastNode == HT[nowNode].rchild)
				HC[i][length++] = '1';
		}
		HC[i][length] = '\0';
		length;
		for (int j = 0; j < length / 2; j++) {
			char temp = HC[i][j];
			HC[i][j] = HC[i][length - j - 1];
			HC[i][length - j - 1] = temp;
		}
		// HC[i][length]='|';
		// HC[i][length+1]='\0';
	}
	return HC;
	//代码结束
}

//利用编码表HC对存放在input中（从1号单元开始）的字符串进行哈夫曼编码,将编码结果存储在encode中
//需要在encode最后添加一个'\0'
void Encoded(HuffmanTree HT, HuffmanCode HC, int n, char input[], char *encode) {
	//代码开始
	int pos = 0;

	for (int i = 0; i < strlen(input); i++) {
		char currentChar = input[i];
		for (int j = 1; j <= n; j++) {
			if (HT[j].chars == currentChar) {
				strcpy(&encode[pos], HC[j]);
				pos += strlen(HC[j]);
				break;
			}
		}
	}
	encode[pos] = '\0';

	//代码结束
}

//利用哈夫曼树HT对存放在encode中的编码串进行译码，将译码结果存储在decode中
//需要在decode最后添加一个'\0'
void Decoded(HuffmanTree HT, int n, char *encode, char *decode) {
	//代码开始
	int p = 2 * n - 1;
	int pos = 0;

	for (int i = 0; encode[i] != '\0'; i++) {
		if (encode[i] == '0')
			p = HT[p].lchild;
		else if (encode[i] == '1')
			p = HT[p].rchild;
		if (HT[p].chars != '\\') {
			decode[pos++] = HT[p].chars;
			// cout<<"in i="<<i<<",add char:"<<HT[p].chars<<"\n";
			p = 2 * n - 1;
		}
	}
	decode[pos] = '\0';

	//代码结束
}

//处理输入数据input
//用inputData返回每个叶子节点对应的字符、权值，用n返回叶子节点总数
void InputProcess(InputData* &inputData, int &n, char input[]) {
	int i, j;
	int len = strlen(input);
	inputData = new InputData[len + 1];
	for (i = 1; i <= len; i++)
		inputData[i].weight = 0;
	inputData[1].chars = input[0];
	inputData[1].weight++;
	n = 1;
	for (i = 1; i < len; i++) {
		for (j = 1; j <= n; j++)
			if (inputData[j].chars == input[i])
				break;
		if (j > n)
			inputData[++n].chars = input[i];
		inputData[j].weight++;
	}
}

//输出函数
void show(HuffmanTree HT, HuffmanCode HC, int n, char *encode, char *decode) {
	for (int i = 1; i < n; i++)
		cout << HT[i].chars << ":" << HT[i].weight << " ";
	cout << HT[n].chars << ":" << HT[n].weight;
	cout << endl;
	for (int i = 1; i <= 2 * n - 1; i++)
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
	for (int i = 1; i <= n; i++)
		cout << HT[i].chars << ":" << HC[i] << " ";
	cout << endl;
	cout << encode << endl;
	cout << decode << endl;
}

int main() {
	char input[MAXLEN]; //输入数据
	cin >> input;

	InputData* inputData;  //对输入数据input进行处理，保存字符和权值（从1号单元开始）
	int n;  //输入数据中的字符个数
	InputProcess(inputData, n, input);

	HuffmanTree HT = CreatHuffmanTree(n, inputData);
	HuffmanCode HC = CreatHuffmanCode(HT, n);

	char *encode = new char[n * MAXLEN];
	Encoded(HT, HC, n, input, encode);

	char *decode = new char[MAXLEN];
	Decoded(HT, n, encode, decode);

	show(HT, HC, n, encode, decode);

	return 0;
}

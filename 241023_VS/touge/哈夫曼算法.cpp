#include<iostream>
#include<fstream>
#include<string.h>
#include<climits>
using namespace std;
#define MAXLEN 2000
typedef struct{
	char chars;
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

typedef struct{
	char chars;
	int weight;
}InputData;



//inputData�洢��ÿ��Ҷ�ӽڵ��Ӧ���ַ���Ȩֵ����1�ŵ�Ԫ��ʼ����nΪҶ�ӽڵ����
//���ع���õĹ����������׵�ַ
HuffmanTree CreatHuffmanTree(int n, InputData* inputData){
	//���뿪ʼ
    HuffmanTree HT = new HTNode[2*n];
    for(int i=1;i<=n;i++){
        HT[i].chars=inputData[i+1].chars;
        HT[i].weight=inputData[i+1].weight;
        HT[i].parent=HT[i].lchild=HT[i].rchild=0;
    }
    for(int num=n+1;num<2*n;num++){
    	int p = -1, q = -1;
	    for (int i = 0; i < num; i++) {
	        if (HT[i].parent == 0) {
	            if (p == -1 || HT[i].weight < HT[p].weight) {
	                q = p;
	                p = i;
	            } else if (q == -1 || HT[i].weight < HT[q].weight) {
	                q = i;
	            }
	        }
	    }
        HT[num].chars='\\';
        HT[num].weight=HT[p].weight+HT[q].weight;
        HT[num].lchild=p;
        HT[num].rchild=q;
        HT[p].parent=num;
        HT[q].parent=num;
    }
    return HT;
    //�������
}


//��HC����ÿ��Ҷ�ӽڵ�Ĺ���������
HuffmanCode CreatHuffmanCode(HuffmanTree HT, int n){
	//���뿪ʼ
    HuffmanCode HC =new char*[n+3];
    for(int i=1;i<=n;i++){
        HC[i]=new char[n+5];
        HC[i][0]=HT[i].chars;//�ַ�����
        int lastNode=0,nowNode=i;
        int length=1;
        while(HT[nowNode].parent!=0){
            lastNode=nowNode;
            nowNode=HT[nowNode].parent;
            if(lastNode==HT[nowNode].lchild)
                HC[i][length++]='0';
            else if(lastNode==HT[nowNode].rchild)
                HC[i][length++]='1';
        }
        HC[i][length]='\0';
        length--;
        for(int j=1;j<=length/2;j++){
            char temp=HC[i][j];
            HC[i][j]=HC[i][length-j+1];
            HC[i][length-j+1]=temp;
        }
    }
    return HC;
    //�������
}

//���ñ����HC�Դ����input�У���1�ŵ�Ԫ��ʼ�����ַ������й���������,���������洢��encode��
//��Ҫ��encode������һ��'\0'
void Encoded(HuffmanTree HT, HuffmanCode HC, int n, char input[], char *encode){
	//���뿪ʼ
    int pos = 0;

    for (int i = 1; i <= n; i++) {
        char currentChar = input[i];
        for (int j = 1; j <= n; j++) {
            if (HC[j][0] == currentChar) {
                int k = 1;
                while (HC[j][k] != '\0') {
                    encode[pos++] = HC[j][k];
                    k++;
                }
                break;
            }
        }
    }
    encode[pos] = '\0';

    //�������
}

//���ù�������HT�Դ����encode�еı��봮�������룬���������洢��decode��
//��Ҫ��decode������һ��'\0'
void Decoded(HuffmanTree HT, int n, char *encode, char *decode){
	//���뿪ʼ
    int p=2*n-2;
    int pos=0;

    for(int i=0;encode[i]!='\0';i++){
        if(encode[i] == '0') p = HT[p].lchild;
		else if(encode[i] == '1') p = HT[p].rchild;
        if(HT[p].chars!='\\'){
            decode[pos++]=HT[p].chars;
            p=2*n-2;
        }
    }
    decode[pos]='\0';

    //�������
}

//������������input
//��inputData����ÿ��Ҷ�ӽڵ��Ӧ���ַ���Ȩֵ����n����Ҷ�ӽڵ�����
void InputProcess(InputData* &inputData, int &n, char input[]){
	int i,j;
	int len = strlen(input);
	inputData = new InputData[len+1];
	for(i=1;i<=len;i++)
		inputData[i].weight = 0;
	inputData[1].chars = input[0];
	inputData[1].weight++;
	n=1;
	for(i=1;i<len;i++){
		for(j=1;j<=n;j++)
			if(inputData[j].chars == input[i])
				break;
		if(j>n)
			inputData[++n].chars = input[i];
		inputData[j].weight++;
	}
}

//�������
void show(HuffmanTree HT, HuffmanCode HC, int n, char *encode, char *decode){
	for(int i=1;i<=n;i++)
		cout<<"i:"<<i<<" "<<HT[i].chars<<":"<<HT[i].weight<<" "<<endl;
	cout<<endl;
	for(int i=1;i<=2*n-1;i++)
		cout<<"i:"<<i<<" "<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
	for(int i=1;i<=n;i++)
		cout<<HT[i].chars<<":"<<HC[i]<<" ";
	cout<<endl;
	cout<<encode<<endl;
	cout<<decode<<endl;
}

int main(){
	char input[MAXLEN]; //��������
	cin>>input;

	InputData* inputData;  //����������input���д��������ַ���Ȩֵ����1�ŵ�Ԫ��ʼ��
	int n;  //���������е��ַ�����
	InputProcess(inputData, n, input);

	HuffmanTree HT = CreatHuffmanTree(n, inputData);
	HuffmanCode HC = CreatHuffmanCode(HT, n);

	char *encode = new char[n*MAXLEN];
	Encoded(HT, HC, n, input, encode);

	char *decode = new char[MAXLEN];
	Decoded(HT, n, encode, decode);

	show(HT, HC, n, encode, decode);

	return 0;
}


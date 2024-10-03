//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//#include "LinkStack.h"
//
//void solve() {
//    LinkStack<char> optr;  // ������ջ
//    LinkStack<double> opnd; // ������ջ
//    string input;
//    map<char, int> mp;  // ���������ȼ�ӳ��
//    mp['+'] = 1;
//    mp['-'] = 1;
//    mp['*'] = 2;
//    mp['/'] = 2;
//    mp['('] = 0;  // ���ŵ����ȼ�Ϊ0
//    int i = 0;
//    optr.Push('#');  // ջ�׷�һ���ڱ�������
//    cin >> input;
//
//    while (input[i] != '#') {
//        if (input[i] >= '0' && input[i] <= '9') {
//            // �������ַ�תΪ��������ѹ�������ջ
//            opnd.Push((double)(input[i] - '0'));
//        }
//        else if (input[i] == '(') {
//            // ������ֱ����ջ
//            optr.Push('(');
//        }
//        else if (input[i] == ')') {
//            // ���������ţ����������������ڵĲ�����
//            while (optr.GetTop() != '(') {
//                char op = optr.Pop();
//                double b = opnd.Pop();
//                double a = opnd.Pop();
//                double c = 0;
//                if (op == '+') c = a + b;
//                else if (op == '-') c = a - b;
//                else if (op == '*') c = a * b;
//                else if (op == '/') c = a / b;
//                opnd.Push(c);
//            }
//            optr.Pop();  // ���������� '('
//        }
//        else {
//            // ��ǰ�����������ȼ�����
//            while (mp[input[i]] <= mp[optr.GetTop()]) {
//                char op = optr.Pop();
//                double b = opnd.Pop();
//                double a = opnd.Pop();
//                double c = 0;
//                if (op == '+') c = a + b;
//                else if (op == '-') c = a - b;
//                else if (op == '*') c = a * b;
//                else if (op == '/') c = a / b;
//                opnd.Push(c);  // �����ѹ�������ջ
//            }
//            // �²�������ջ
//            optr.Push(input[i]);
//        }
//        i++;
//    }
//
//    // ����ʣ��Ĳ�����
//    while (optr.GetTop() != '#') {
//        char op = optr.Pop();
//        double b = opnd.Pop();
//        double a = opnd.Pop();
//        double c;
//        if (op == '+') c = a + b;
//        else if (op == '-') c = a - b;
//        else if (op == '*') c = a * b;
//        else if (op == '/') c = a / b;
//        opnd.Push(c);
//    }
//
//    // ������ս��
//    cout << opnd.GetTop() << endl;
//}
//

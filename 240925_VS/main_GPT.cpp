//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//#include "LinkStack.h"
//
//void solve() {
//    LinkStack<char> optr;  // 操作符栈
//    LinkStack<double> opnd; // 操作数栈
//    string input;
//    map<char, int> mp;  // 操作符优先级映射
//    mp['+'] = 1;
//    mp['-'] = 1;
//    mp['*'] = 2;
//    mp['/'] = 2;
//    mp['('] = 0;  // 括号的优先级为0
//    int i = 0;
//    optr.Push('#');  // 栈底放一个哨兵操作符
//    cin >> input;
//
//    while (input[i] != '#') {
//        if (input[i] >= '0' && input[i] <= '9') {
//            // 将数字字符转为整数，并压入操作数栈
//            opnd.Push((double)(input[i] - '0'));
//        }
//        else if (input[i] == '(') {
//            // 左括号直接入栈
//            optr.Push('(');
//        }
//        else if (input[i] == ')') {
//            // 遇到右括号，弹出并处理括号内的操作符
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
//            optr.Pop();  // 弹出左括号 '('
//        }
//        else {
//            // 当前操作符的优先级处理
//            while (mp[input[i]] <= mp[optr.GetTop()]) {
//                char op = optr.Pop();
//                double b = opnd.Pop();
//                double a = opnd.Pop();
//                double c = 0;
//                if (op == '+') c = a + b;
//                else if (op == '-') c = a - b;
//                else if (op == '*') c = a * b;
//                else if (op == '/') c = a / b;
//                opnd.Push(c);  // 将结果压入操作数栈
//            }
//            // 新操作符入栈
//            optr.Push(input[i]);
//        }
//        i++;
//    }
//
//    // 处理剩余的操作符
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
//    // 输出最终结果
//    cout << opnd.GetTop() << endl;
//}
//

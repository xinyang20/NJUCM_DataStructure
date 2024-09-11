#include <iostream>
#include <time.h>
#include <cmath>
#include <string>

using namespace std;

const int MaxSize = 100;

// ��С�������� N ����������
void findPrimes(int N) {
    clock_t t1, t2;
    t1 = clock();

    int count = 0;
    for (int i = 2; i < N; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
            count++;
        }
    }
    cout << endl << "С�� " << N << " ���������� " << count << " ����" << endl;

    t2 = clock();
    cout << "�㷨ִ��ʱ��: " << ((double)(t2 - t1)) / CLOCKS_PER_SEC << " ��" << endl;
}

// ��һ�����������㷨
void findPrimes2(int N) {
    clock_t t1, t2;
    t1 = clock();

    int count = 0;
    bool* isPrime = new bool[N];
    for (int i = 2; i < N; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            cout << i << " ";
            count++;
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    cout << endl << "С�� " << N << " ���������� " << count << " ����" << endl;

    t2 = clock();
    cout << "�㷨ִ��ʱ��: " << ((double)(t2 - t1)) / CLOCKS_PER_SEC << " ��" << endl;

    delete[] isPrime;
}

// ������ģ��
template <typename DataType>
class Set {
public:
    Set(DataType a[], int n) {
        length = 0;
        for (int i = 0; i < n; i++) {
            InsertData(a[i]);
        }
    }

    ~Set() {}

    bool GetData(DataType x) {
        for (int i = 0; i < length; i++) {
            if (data[i] == x) {
                return true;
            }
        }
        return false;
    }

    bool InsertData(DataType x) {
        if (!GetData(x)) {
            data[length++] = x;
            return true;
        }
        return false;
    }

    void printSet() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    DataType data[MaxSize];
    int length;
};

int main() {
    int N = 100;
    cout << "��С�� " << N << " ������������" << endl;
    findPrimes(N);
    cout << endl;

    N = 10000;
    cout << "��С�� " << N << " ������������" << endl;
    findPrimes(N);
    cout << endl;

    int a[MaxSize] = {2022, 1954, 2003, 10315, 1123};
    int n = 5;
    Set<int> A(a, n);
    cout << "���� A ��Ԫ��Ϊ��";
    A.printSet();

    string b[MaxSize] = {"njucm", "nju", "seu", "nuaa", "njust"};
    Set<string> B(b, n);
    cout << "���� B ��Ԫ��Ϊ��";
    B.printSet();

    return 0;
}

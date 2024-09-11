#include <iostream>
#include <time.h>
#include <cmath>
#include <string>

using namespace std;

const int MaxSize = 100;

// 求小于正整数 N 的所有素数
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
    cout << endl << "小于 " << N << " 的素数共有 " << count << " 个。" << endl;

    t2 = clock();
    cout << "算法执行时间: " << ((double)(t2 - t1)) / CLOCKS_PER_SEC << " 秒" << endl;
}

// 另一种求素数的算法
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
    cout << endl << "小于 " << N << " 的素数共有 " << count << " 个。" << endl;

    t2 = clock();
    cout << "算法执行时间: " << ((double)(t2 - t1)) / CLOCKS_PER_SEC << " 秒" << endl;

    delete[] isPrime;
}

// 集合类模板
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
    cout << "求小于 " << N << " 的所有素数：" << endl;
    findPrimes(N);
    cout << endl;

    N = 10000;
    cout << "求小于 " << N << " 的所有素数：" << endl;
    findPrimes(N);
    cout << endl;

    int a[MaxSize] = {2022, 1954, 2003, 10315, 1123};
    int n = 5;
    Set<int> A(a, n);
    cout << "集合 A 的元素为：";
    A.printSet();

    string b[MaxSize] = {"njucm", "nju", "seu", "nuaa", "njust"};
    Set<string> B(b, n);
    cout << "集合 B 的元素为：";
    B.printSet();

    return 0;
}

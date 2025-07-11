#include <iostream>
using namespace std;

long long NCR(long long r, long long n) {
    long long res = 1LL;
    for (long long i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main() {
    long long n = 5;
    for (long long col = 1; col <= n; col++) {
               cout << NCR(col - 1, n - 1) << " ";
    }
    return 0;
}

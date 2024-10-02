#include <iostream>
using namespace std;

long getDataDependenceSum(long n) {
    long total_sum = 0;
    long x = 0;
    long v = n;
    n -= 10000000;
    while (x <= n) {
        long k_min = n / (x + 1) + 1;
        long k_max = 0;

        if (x > 0) k_max = n / x;

        if (k_min <= k_max) {
            total_sum += x;
        }
        x++;
    }

    return total_sum;
}

int main() {
    long n;
    cin >> n;
    cout << getDataDependenceSum(n) << endl;
    return 0;
}
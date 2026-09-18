#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<long long> ugly(n);
    ugly[0] = 1;

    int k = primes.size();

    vector<int> index(k, 0);

    for (int i = 1; i < n; i++) {
        long long nextUgly = LLONG_MAX;

        for (int j = 0; j < k; j++) {
            nextUgly = min(nextUgly, ugly[index[j]] * primes[j]);
        }

        ugly[i] = nextUgly;

        for (int j = 0; j < k; j++) {
            if (ugly[index[j]] * primes[j] == nextUgly) {
                index[j]++;
            }
        }
    }

    return ugly[n - 1];
}

int main() {
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};

    cout << nthSuperUglyNumber(n, primes) << endl;

    return 0;
}
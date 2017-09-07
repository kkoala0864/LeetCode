#include <Solution.h>
#include <vector>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(7);
    primes.push_back(13);
    primes.push_back(19);
    cout << test->nthSuperUglyNumber(12, primes) << endl;

    return 0;
}


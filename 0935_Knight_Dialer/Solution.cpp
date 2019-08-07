#include <Solution.h>
#include <iostream>
#include <math.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int Solution::knightDialer(int N) {
    if (1 == N) return 10;
    unsigned long long int ret(0);
    unsigned long long base = 1000000007;
    vector<unsigned long long> dp(10,0), last = {1,1,1,1,1,0,1,1,1,1};

    for (int i = 2 ; i <= N ; ++i) {
	dp.at(0) = last.at(4) + last.at(6);
	dp.at(1) = last.at(6) + last.at(8);
	dp.at(2) = last.at(7) + last.at(9);
	dp.at(3) = last.at(4) + last.at(8);
	dp.at(4) = last.at(0) + last.at(3) + last.at(9);
	dp.at(6) = last.at(0) + last.at(1) + last.at(7);
	dp.at(7) = last.at(2) + last.at(6);
	dp.at(8) = last.at(1) + last.at(3);
	dp.at(9) = last.at(2) + last.at(4);
	for (int idx = 0 ; idx < 10 ; ++idx) {
		last.at(idx) = dp.at(idx) % base;
	}
    }
    for (const auto& iter : last) {
	ret = (ret + iter) % base;
    }
    return ret;
}


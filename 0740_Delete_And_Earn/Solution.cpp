#include <Solution.h>
#include <iostream>

using namespace std;

int getMaxValInterval(const vector<int>& numRecord, int start, int end) {
    if (start > end) return 0;
    if (end - start == 0) {
	return start * numRecord.at(start);
    } else if (end - start == 1) {
	return max(start * numRecord.at(start), end * numRecord.at(end));
    }

    vector<int> dp(end - start + 1, 0);
    dp.at(0) = start * numRecord.at(start);
    dp.at(1) = max((start + 1) * numRecord.at(start + 1), dp.at(0));
    for (int i = 2 ; i < (end-start+1) ; ++i) {
	dp.at(i) = max((start+i) * numRecord.at(start+i) + dp.at(i-2), dp.at(start+i-1));
    }
    return dp.at(end-start);
}

int Solution::deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> numRecord(10001, 0);
    int maxValue(0);
    for (const auto& val : nums) {
	maxValue = max(maxValue, val);
	++numRecord[val];
    }

    return getMaxValInterval(numRecord, 0, maxValue);
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::greater;

bool gatherPacket(const vector<int>& nums, vector<bool>& flag, int target, int index, int& cnt) {
    if (0 > target) return false;
    if (0 == target) {
	++cnt;
	return true;
    }

    for (int i = index ; i < nums.size() ; ++i) {
	if (flag.at(i)) continue;
	flag.at(i) = true;
	if (gatherPacket(nums, flag, target - nums.at(i), index + 1, cnt)) return true;
	flag.at(i) = false;
    }
    return false;
}

bool Solution::canPartition(vector<int>& nums) {
    if (nums.empty()) return false;
    vector<bool> flag(nums.size(), false);
    int sum(0);
    for (const auto& iter : nums) sum += iter;
    if ((sum % 2) > 0) return false;
    int target = sum / 2;

    sort(nums.begin(), nums.end(), greater<int>());
    if (nums.at(0) > target) return false;

    int cnt(0);
    for (int i = 0 ; i < nums.size() ; ++i) {
	if (flag.at(i)) continue;
	gatherPacket(nums, flag, target, 0, cnt);
    }
    return 2 == cnt ? true : false;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::greater;

bool help(vector<int>& msVec, const vector<int>& nums, int idx, const int& LimitSize) {
    if (idx == nums.size()) return
	msVec.at(0) == msVec.at(1) &&
	msVec.at(1) == msVec.at(2) &&
	msVec.at(2) == msVec.at(3);

    for (int i(0) ; i < 4 ; ++i) {
	msVec.at(i) += nums.at(idx);
	if ((msVec.at(i) <= LimitSize) && help(msVec, nums, idx+1, LimitSize)) return true;
	msVec.at(i) -= nums.at(idx);
    }
    return false;
}

bool Solution::makesquare(vector<int>& nums) {
    if (nums.empty()) return false;
    int MaxSize(0);
    int TotalSize(0);
    for (const auto& val : nums) {
	if (val > MaxSize) MaxSize = val;
	TotalSize += val;
    }
    int SizePerSide = TotalSize / 4;
    if (TotalSize % 4 || MaxSize > SizePerSide) return false;
    sort(nums.begin() ,nums.end(), greater<int>());
    vector<int> msVec(4, 0);
    return help(msVec, nums, 0, SizePerSide);
}

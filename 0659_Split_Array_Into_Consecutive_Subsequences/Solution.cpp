#include <Solution.h>
#include <iostream>
#include <unordered_map>
using namespace std;

bool Solution::isPossible(vector<int>& nums) {
    if (3 == nums.size()) {
	for (int i = 1 ; i < nums.size() ; ++i) {
	    if (nums.at(i) - nums.at(i-1) != 1) {
		return false;
	    }
	}
	return true;
    }
    unordered_map<int, int> Cnt;

    for (const int& val : nums) ++Cnt[val];

    vector<pair<int, int>> CntVec;
    for (const auto& ele : Cnt) CntVec.emplace_back(ele.first, ele.second);

    auto cmp = [] (const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.first < rhs.first; };
    sort(CntVec.begin(), CntVec.end(), cmp);
    int consecCnt(0);
    for (int i = 0 ; i < CntVec.size() ; ++i) {
	while (CntVec.at(i).second > 0) {
	    int consecutiveCnt(1);
	    int idx = i+1;
	    while (consecutiveCnt < 3 && idx < CntVec.size() && CntVec.at(idx).second > 0) {
		if (CntVec.at(idx).first - CntVec.at(idx-1).first == 1) {
		    ++consecutiveCnt;
		    ++idx;
		} else {
		    break;
		}
	    }
	    if (consecutiveCnt == 3) {
		--CntVec.at(i).second;
		--CntVec.at(i+1).second;
		--CntVec.at(i+2).second;
		++consecCnt;
		if (consecCnt > 1) return true;
	    } else
		break;
	}
    }
    return (consecCnt < 2) ? false : true;
}

// each subsequence should continuous and can't be duplicated, can't be single
bool Solution::isPossible2(vector<int>& nums) {
    unordered_map<int, int> freq, tail;
    for (const auto& val : nums) {
	++freq[val];
    }

    for (const auto& val : nums) {
	if (freq[val] > 0) {
	    --freq[val];
	    if (tail[val-1] > 0) {
		++tail[val];
		--tail[val-1];
	    } else if (freq[val+1] > 0 && freq[val+2]) {
		--freq[val+1];
		--freq[val+2];
		++tail[val+2];
	    } else {
		return false;
	    }
	}
    }
    return true;
}



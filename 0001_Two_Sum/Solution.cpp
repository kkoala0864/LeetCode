#include <Solution.h>
#include <unordered_map>

using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    if (nums.empty()) return ret;
    unordered_map<int, int> numMap;
    for(int i = 0 ; i < nums.size() ; ++i) {
	numMap.emplace(nums.at(i), i);
    }

    for (int i = 0 ; i < nums.size() ; ++i) {
	auto findRes = numMap.find(target-nums.at(i));
	if (findRes != numMap.end() && findRes->second != i) {
	    ret.emplace_back(i);
	    ret.emplace_back(findRes->second);
	    break;
	}
    }
    return ret;
}


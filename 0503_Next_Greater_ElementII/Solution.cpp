#include <Solution.h>
#include <iostream>
using namespace std;

vector<int> Solution::nextGreaterElements(vector<int>& nums) {
    if (nums.empty())
	return vector<int>();

    int size = nums.size();
    vector<int> retVec(size, INT_MIN);


    for (int vIdx = size - 1 ; vIdx >= 0 ; --vIdx) {
	for (int compIdx = 1 ; compIdx < size ; ++compIdx) {
	    int cmpIdx = (vIdx + compIdx) % size;
	    if (nums.at(cmpIdx) > nums.at(vIdx)) {
		retVec.at(vIdx) = nums.at(cmpIdx);
		break;
	    } else if (nums.at(cmpIdx) < nums.at(vIdx)) {
		if (retVec.at(cmpIdx) > nums.at(vIdx)) {
		    retVec.at(vIdx) = retVec.at(cmpIdx);
		    break;
		}
	    } else {
		retVec.at(vIdx) = retVec.at(cmpIdx);
	    }
	}
    }
    for (auto& idx : retVec) {
	if (idx == INT_MIN) idx = -1;
    }
    return retVec;
}

vector<int> Solution::nextGreaterElements2(vector<int>& nums) {
    vector<int> st;
    vector<int> res(nums.size(), -1);
    for(int i = 0 ; i < nums.size() ; ++i)
    {
	while(!st.empty() && nums[i] > nums[st.back()]) {
	    res[st.back()] = nums[i];
	    st.pop_back();
	}
	st.push_back(i);
    }
    for (int i = 0 ; i < nums.size() ; ++i)
    {
	while(!st.empty() && nums[i] > nums[st.back()]) {
	    res[st.back()] = nums[i];
	    st.pop_back();
	}
	st.push_back(i);
    }
    return res;
}

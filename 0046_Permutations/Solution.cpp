#include <Solution.h>

using std::size_t;
using std::swap;

static void permuteRec(vector<vector<int> >& ret, vector<int>& nums, size_t cur, size_t size) {

	if (cur == (size - 1)) {
		ret.push_back(nums);
	}

	for(int i = cur ; i < size ; ++i) {
		if( cur != i)
			swap(nums[cur], nums[i]);
		permuteRec(ret, nums, cur+1, size);
		if( cur != i)
			swap(nums[cur], nums[i]);
	}
}

vector<vector<int> > Solution::permute(vector<int>& nums) {
	vector<vector<int> > ret;
	permuteRec(ret, nums, 0, nums.size());
	return ret;
}

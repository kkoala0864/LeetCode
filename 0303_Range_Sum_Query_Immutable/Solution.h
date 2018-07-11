#include <vector>

using std::vector;

class NumArray {
    public:
	NumArray(vector<int> nums) {
	    int total = 0;
	    for (const auto& idx : nums) {
		_nums.emplace_back(total + idx);
		total += idx;
	    }
	}

	int sumRange(int i, int j) {
	    if (i > 0)
		return _nums.at(j) - _nums.at(i-1);
	    else
		return _nums.at(j);
	}
    private :
	vector<int> _nums;
	virtual ~NumArray() {}
	NumArray& operator=(const NumArray& source);
	NumArray(const NumArray&);
};


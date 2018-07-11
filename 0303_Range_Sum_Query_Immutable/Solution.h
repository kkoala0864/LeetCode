#include <vector>

using std::vector;

class NumArray {
    public:
	NumArray(vector<int> nums) {
	    total = 0;
	    for (const auto& idx : nums) {
		total += idx;
		_nums.emplace_back(idx);
	    }
	}

	int sumRange(int i, int j) {
	    int ret = total;
	    for (int front = 0 ; front < i ; ++front) {
		ret -= _nums.at(front);
	    }
	    for (int tail = j+1 ; tail < _nums.size() ; ++tail) {
		ret -= _nums.at(tail);
	    }
	    return ret;
	}
    private :
	int total;
	vector<int> _nums;
	virtual ~NumArray() {}
	NumArray& operator=(const NumArray& source);
	NumArray(const NumArray&);
};


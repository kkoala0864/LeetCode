#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	vector<int> input = {1,8,6,2,5,4,8,3,7};
	//vector<int> input = {4,3,2,1,4};
	//vector<int> input = {1,2,1};
	cout << test->maxArea(input) << endl;
	return 0;
}


#include <Solution.h>
#include <iostream>
#include <iterator>

using namespace std;

int main(void) {
	Solution test;
	vector<int> ret = test.countBits(5);
	for ( vector<int>::iterator iter = ret.begin() ; iter != ret.end() ; ++iter) {
		cout << *iter << endl;
	}
	return 0;
}


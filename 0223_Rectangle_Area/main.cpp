#include <Solution.h>
#include <iostream>
using namespace std;
int main() {
	Solution* test = new Solution();
	cout << test->computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;
	cout << test->computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
	cout << test->computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
	cout << test->computeArea(-2, -2, 2, 2, -3, -3, 3, -1) << endl;
	cout << test->computeArea(-5, -2, 5, 1, -3, -3, 3, 3) << endl;
	cout << test->computeArea(-2, -2, 2, 2, -1, 4, 1, 6) << endl;

	return 0;
}

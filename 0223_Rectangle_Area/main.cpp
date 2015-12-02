#include <Solution.h>
#include <iostream>
using namespace std;
int main() {
	Solution* test = new Solution();
	cout << test->computeArea(-2, -2, 2, 2, -4, -4, -3, -3) << endl;
	return 0;
}

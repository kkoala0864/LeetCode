#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
	string hay("hellow");
	string need("ll");
	Solution* test = new Solution();
	cout << test->strStr(hay, need) << endl;

	return 0;
}


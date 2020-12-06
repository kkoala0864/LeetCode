#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
	string s("a");
	string t("a");
	//string s("ADOBECODEBANC");
	//string t("ABC");
	//string s("bba");
	//string t("ab");
	cout << test->minWindow(s, t) << endl;
    return 0;
}


#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {

	string s("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc");
	string t("bcddceeeebecbc");
	Solution* test = new Solution();
	cout << test->numDistinct(s,t) << endl;

	return 0;
}


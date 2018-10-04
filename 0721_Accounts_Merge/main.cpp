#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<vector<string>> input = {{"John", "johnsmith@mail.com", "john00@mail.com"},
	{"John", "johnnybravo@mail.com"},
	{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
	{"Mary", "mary@mail.com"}};
    Solution* test = new Solution();
    auto res = test->accountsMerge(input);
    for (const auto& account : res) {
	for (const auto& email : account) {
	    cout << email << " ";
	}
	cout << endl;
    }
    return 0;
}


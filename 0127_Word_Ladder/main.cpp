#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
	vector<string> input = {"hot","dot","dog","lot","log","cog"};
    Solution* test = new Solution();
    cout << test->ladderLength("hit", "cog", input) << endl;

    return 0;
}


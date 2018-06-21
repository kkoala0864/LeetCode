#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<string> input = {"i", "love", "leetcode", "i", "love", "coding"};
    Solution* test = new Solution();
    vector<string> ret = test->topKFrequent(input, 2);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}


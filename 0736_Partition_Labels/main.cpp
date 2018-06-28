#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    string input("ababcbacadefegdehijhklij");
    Solution* test = new Solution();
    vector<int> ret = test->partitionLabels(input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;
    return 0;
}


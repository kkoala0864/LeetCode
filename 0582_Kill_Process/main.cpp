#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> pid = {1,3,10,5};
    vector<int> ppid = {3,0,5,3};
    Solution* test = new Solution();
    vector<int> ret = test->killProcess(pid, ppid, 5);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}


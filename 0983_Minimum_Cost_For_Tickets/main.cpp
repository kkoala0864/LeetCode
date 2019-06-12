#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {7, 2, 15};
    cout << test->mincostTickets(days, costs) << endl;
    return 0;
}


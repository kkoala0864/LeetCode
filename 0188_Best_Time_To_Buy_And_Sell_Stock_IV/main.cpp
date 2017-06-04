#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(4);
    cout << test->maxProfit(2, input) << endl;

    return 0;
}


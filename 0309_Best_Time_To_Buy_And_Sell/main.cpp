#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();

    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(0);
    input.push_back(2);
    cout << "result :" << test->maxProfit(input) << endl;
    return 0;
}


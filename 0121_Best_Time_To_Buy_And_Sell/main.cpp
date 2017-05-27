#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(5);
    input.push_back(2);
    input.push_back(9);
    input.push_back(7);
    cout << "output: " << test->maxProfit(input) << endl;

    return 0;
}


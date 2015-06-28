#include <Solution.h>

using namespace std;
int main(void) {
    Solution* test = new Solution();

    vector<int> input;
    input.push_back(3);
    input.push_back(2);
    input.push_back(4);
    test->DebugPrint(input);
    test->DebugPrint(test->twoSum(input, 6));


    return 0;
}


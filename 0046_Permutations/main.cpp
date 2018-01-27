#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    Solution* test = new Solution();
    int inputA[3] = {1, 2, 3};
    vector<int> inputV(inputA, inputA + sizeof(inputA) / sizeof(int));
    test->permute(inputV);

    return 0;
}


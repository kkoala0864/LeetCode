#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {8,5,1,7,10,12};
    //vector<int> input = {19, 4, 8, 11};
    test->bstFromPreorder(input);
    return 0;

}


#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    vector<int> input = {4,5,6,7,0,1,2};
    Solution* test = new Solution();
    cout << test->search(input, 0) << endl;

    return 0;
}


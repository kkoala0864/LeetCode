#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1, 3, 4 , 2 ,2};
    Solution* test = new Solution();
    cout << test->findDuplicate(input) << endl;

    return 0;
}


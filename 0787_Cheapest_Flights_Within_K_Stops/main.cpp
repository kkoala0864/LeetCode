#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

using namespace std;
int main(void) {
    vector<vector<int>> input = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    Solution* test = new Solution();
    cout << test->findCheapestPrice(4, input, 0, 3, 1) << endl;

    return 0;
}


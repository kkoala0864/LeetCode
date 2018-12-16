#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
//    vector<int> prices = {2,5};
//    vector<vector<int>> special = {{3,0,5},{1,2,10}};
//    vector<int> needs = {3,2};
    vector<int> prices = {2,3,4};
    vector<vector<int>> special = {{1,1,0,4},{2,2,1,9}};
    vector<int> needs = {1,2,1};
//    vector<int> prices = {0,0,0};
//    vector<vector<int>> special = {{1,1,0,4},{2,2,1,9}};
//    vector<int> needs = {1,1,1};
    Solution* test = new Solution();
    cout << test->shoppingOffers(prices, special, needs) << endl;
    return 0;
}


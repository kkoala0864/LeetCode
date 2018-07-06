#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> prices = {1,3,7,5,10,3};
    Solution* test = new Solution();
    cout << test->maxProfit(prices, 3) << endl;
    cout << test->maxProfit2(prices, 3) << endl;
    cout << test->maxProfit3(prices, 3) << endl;

    return 0;
}


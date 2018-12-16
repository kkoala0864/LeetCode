#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool checkZero(const vector<int>& src) {
    for (const auto& val : src)
	if (val != 0) return false;
    return true;
}

int DFS(vector<int>& target, const vector<int>& price, const vector<vector<int>>& special) {
    if (checkZero(target)) return 0;

    int localCost(0);
    int size = target.size();

    for (int i(0) ; i < size ; ++i)
	localCost += target.at(i) * price.at(i);

    if (0 == localCost) return 0;
    for (int i(0) ; i < special.size() ; ++i) {
	int j(0);
	for (; j < size ; ++j) {
	    if (special.at(i).at(j) > target.at(j)) break;
	}
	if (j == size) {
	    vector<int> nextTarget(target);
	    for (int k(0) ; k < size ; ++k) {
		nextTarget.at(k) -= special.at(i).at(k);
	    }
	    int tmpCost = DFS(nextTarget, price, special);
	    tmpCost += special.at(i).at(size);
	    if (tmpCost < localCost) localCost = tmpCost;
	}
    }
    return localCost;
}

int Solution::shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    if (price.empty()) return 0;
    return DFS(needs, price, special);
}

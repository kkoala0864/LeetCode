#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    if (0 == size) return 0;
    if (1 == size) return gas.at(0) >= cost.at(0) ? 0 : -1;
    vector<int> rest(size, 0);
    int total(0);
    for (int i = 0 ; i < size ; ++i) {
	rest.at(i) = gas.at(i) - cost.at(i);
	total += rest.at(i);
    }

    if (total < 0) return -1;

    int cur_idx(0), start_idx(0), left_over(0);
    while (cur_idx < size) {
	if ((left_over + rest.at(cur_idx)) >= 0) {
	    left_over += rest.at(cur_idx);
	} else {
	    start_idx = cur_idx+1;
	    left_over = 0;
	}
	++cur_idx;
    }
    return start_idx;
}

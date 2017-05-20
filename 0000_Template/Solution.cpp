#include <Solution.h>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int target) {

    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());

    vector<int> result;
    int front = 0;
    int tail = sorted.size() - 1;
    while ( 1 ) {
        if ( (sorted[front] + sorted[tail]) == target ) {
            break;
        } else if ( (sorted[front] + sorted[tail]) < target ) {
            ++front;
        } else {
            --tail;
        }
    }
    int front_loc(0), tail_loc(0);
    for( int index = 0 ; index < nums.size() ; ++index) {
        if ( nums[index] == sorted[front] && front_loc == 0) {
            front_loc = index + 1;
        }
        if ( nums[index] == sorted[tail] && tail_loc == 0) {
            tail_loc = index + 1;
            if ( front_loc == tail_loc )
                tail_loc = 0;
        }
    }
    result.push_back(front_loc);
    result.push_back(tail_loc);
    sort(result.begin(), result.end());
    return result;
}

void Solution::DebugPrint(vector<int> nums) {
    for ( vector<int>::iterator iter = nums.begin() ; iter != nums.end() ; ++iter ) {
        cout << *iter << " " << endl;
    }
}

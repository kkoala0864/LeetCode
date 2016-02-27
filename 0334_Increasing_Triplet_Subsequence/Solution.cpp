#include <Solution.h>
#include <iterator>

bool increasingTriplet(vector<int>& nums) {

	bool conted(false);
	if ( nums.size() < 3 )
		return false;

	vector<int> orderArray;
	orderArray.push_back(nums[0]);
	for (vector<int>::iterator iter = (nums.begin() + 1); iter != nums.end() ; ++iter) {
		size_t order_size = orderArray.size();
		if ( *iter > orderArray[order_size - 1] ) {
			orderArray.push_back(*iter);
		} else {
			if ( order_size > 1) {
				if ( *iter < orderArray[0] ) {
					orderArray[0] = *iter;
				} else if ( *iter > orderArray[0] ) {
					orderArray[1] = *iter;
				}
			} else if ( 1 == order_size ) {
				orderArray[0] = *iter;
			}
		}
		if ( 3 == orderArray.size() ) {
			return true;
		}
	}
	if ( 3 > orderArray.size() ) {
		return false;
	} else {
		return true;
	}
}

#include <Solution.h>
#include <iterator>

bool increasingTriplet(vector<int>& nums) {

	bool conted(false);
	if ( nums.size() < 3 )
		return false;

	for (vector<int>::iterator iter = (nums.begin() + 1); iter != nums.end() ; iter++) {
		if ( *(iter - 1) < *iter ) {
			if ( !conted ) {
				conted = true;
			} else {
				return true;
			}
		} else {
			conted = false;
		}
	}
	return false;
}

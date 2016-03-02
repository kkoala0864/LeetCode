#include <iostream>
#include <Solution.h>
#include <vector>

using namespace std;

Solution::Solution() {};

Solution::~Solution() {};

int Solution::lengthOfLongestSubstring(string s) {
	if ( s.empty() )
		return 0;
	int hash[256];
	int ret = 0;
	int start = 0;
	int i = 0;
	for ( i = 0 ; i < 256 ; ++i ) {
		hash[i] = -1;
	}
	for ( i = 0 ; i < s.length() ; ++i ) {
		if ( -1 != hash[s[i]] ) {
			if ( ret < (i - start) ) ret = i - start;
			for( int j = start ; j < hash[s[i]] ; ++j ) {
				hash[s[j]] = -1;
			}
			start = hash[s[i]] + 1;
		}
		hash[s[i]] = i;
	}
	if ( ret < (i - start) ) ret = i - start;
	return ret;
}

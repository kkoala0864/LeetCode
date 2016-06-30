#include <Solution.h>
#include <iostream>
#include <string>

using namespace std;

string Solution::reverseString(string s) {
	if( s.empty() )
		return s;

	string retStr;
	while( !s.empty() ) {
		retStr.push_back(s.back());
		s.pop_back();
	}
	return retStr;
}

void Solution::DebugPrint(string nums) {
}

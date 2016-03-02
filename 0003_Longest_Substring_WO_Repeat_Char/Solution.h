#ifndef __SOLUTION_H__
#define __SOLUITON_H__
#include <string>

class Solution {
	public :
		Solution();
		virtual ~Solution();
		int lengthOfLongestSubstring(std::string s);
	private :
		Solution(const Solution&);
		Solution& operator=(const Solution& source);
};

#endif /* __SOLUTION_H__ */

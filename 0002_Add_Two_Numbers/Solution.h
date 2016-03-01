#ifndef __SOLUTION_H__
#define __SOLUITON_H__
#include <stddef.h>
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public :
		Solution();
		virtual ~Solution();
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	private :
		Solution(const Solution&);
		Solution& operator=(const Solution& source);
};



#endif /* __SOLUTION_H__ */

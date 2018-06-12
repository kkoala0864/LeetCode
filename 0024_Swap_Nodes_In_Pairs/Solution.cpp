#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::swapPairs(ListNode* head) {
    if (head && head->next) {
	ListNode *cur_node = head, *next_node;
	head = head->next;
	while (cur_node && cur_node->next){
	    next_node = cur_node->next;
	    cur_node->next = next_node->next;
	    next_node->next = cur_node;
	    cur_node = cur_node->next;
	    if (cur_node && cur_node->next)
		next_node->next->next = cur_node->next;
	}
    }
    return head;

}

#include <Solution.h>
#include <iostream>

using namespace std;

TreeNode* Solution::sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    ListNode *pre = head, * slow = head, * fast = head;

    while (fast && fast->next) {
	pre = slow;
	slow = slow->next;
	fast = fast->next->next;
    }
    pre->next = nullptr;
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}

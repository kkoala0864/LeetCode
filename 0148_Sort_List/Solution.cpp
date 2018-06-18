#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* merge(ListNode* left, int leftCnt, ListNode* right, int rightCnt) {
    ListNode* beAdd = left->val < right->val ? left : right;
    ListNode* add = beAdd == left ? right : left;
    int beAddCnt = beAdd == left ? leftCnt : rightCnt;
    int addCnt = beAddCnt == leftCnt ? rightCnt : leftCnt;

    while (addCnt-- > 0) {
	ListNode* node = add;
	add = add->next;
	ListNode* iter = beAdd;
	ListNode* pre = nullptr;
	int i = 0;
	bool isAppend(false);
	while (i++ < beAddCnt) {
	    if (node->val < iter->val) {
		node->next = iter;
		pre->next = node;
		++beAddCnt;
		isAppend = true;
		break;
	    }
	    pre = iter;
	    iter = iter->next;
	}
	if (!isAppend) {
	    pre->next = node;
	    break;
	}
    }
    return beAdd;
}

ListNode* mergeSort(ListNode* start, int size) {
    if (1 == size) return start;
    if (2 == size) {
	if (start->val > start->next->val)
	    swap(start->val, start->next->val);
	return start;
    }

    int count = size / 2;
    ListNode* iter = start;
    ListNode* pre = nullptr;
    int i = 1;
    while (i++ <= count) {
	pre = iter;
	iter = iter->next;
    }
    pre->next = nullptr;
    ListNode* leftSide = mergeSort(start, count);
    ListNode* rightSide = mergeSort(iter, size-count);
    return merge(leftSide, count, rightSide, size-count);
}

ListNode* Solution::sortList2(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return head;
    ListNode* iter = head;
    int size(0);
    while (iter) {
	++size;
	iter = iter->next;
    }
    return mergeSort(head, size);
}

ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (left && right) {
	if (left->val < right->val) {
	    cur->next = left;
	    left = left->next;
	} else {
	    cur->next = right;
	    right = right->next;
	}
	cur = cur->next;
    }
    if (left) cur->next = left;
    if (right) cur->next = right;
    return dummy->next;
}

ListNode* Solution::sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head, *pre = nullptr;
    while (fast && fast->next) {
	pre = slow;
	slow = slow->next;
	fast = fast->next->next;
    }
    pre->next = nullptr;
    return merge(sortList(head), sortList(slow));
}


#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

RandomListNode* Solution::copyRandomList(RandomListNode *head) {
    if (head == nullptr) return nullptr;
    unordered_map<int, RandomListNode*> record;
    RandomListNode* dummy = new RandomListNode(0);
    RandomListNode* CopyTail = dummy;

    RandomListNode* iter = head;

    while (iter) {
	if (record.find(iter->label) != record.end()) {
	    CopyTail->next = record.at(iter->label);
	} else {
	    RandomListNode* node = new RandomListNode(iter->label);
	    record.emplace(iter->label, node);
	    CopyTail->next = node;
	    if (iter->random) {
		RandomListNode* randAppend = node;
		RandomListNode* randIter = iter->random;
		while (randIter) {
		    if (record.find(randIter->label) == record.end()) {
			RandomListNode* randNode = new RandomListNode(randIter->label);
			record.emplace(randIter->label, randNode);
			randAppend->random = randNode;
			randAppend = randAppend->random;
			randIter = randIter->random;
		    } else {
			randAppend->random = record.at(randIter->label);
			break;
		    }
		}
	    }
	}
	CopyTail = CopyTail->next;
	iter = iter->next;
    }

    return dummy->next;
}

RandomListNode* Solution::copyRandomList2(RandomListNode *head) {
    if (!head) return nullptr;
    RandomListNode* newHead, * l1, * l2;
    for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
	l2 = new RandomListNode(l1->label);
	l2->next = l1->next;
	l1->next = l2;
    }

    for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
	if (l1->random) l1->next->random = l1->random->next;
    }

    newHead = head->next;
    for (l1 = head; l1 != nullptr; l1 = l1->next) {
	l2 = l1->next;
	l1->next = l2->next;
	if (l2->next) l2->next = l2->next->next;
    }

    return newHead;
}

#include <Solution.h>

int main(void) {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    first->next = first;
    second->next = first;
    Solution* test = new Solution();
    test->rotateRight(first, 1);

    return 0;
}


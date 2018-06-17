#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    ListNode* input = new ListNode(9);
    Solution* test = new Solution();
    ListNode* ret = test->plusOne(input);
    while (ret) {
	cout << ret->val << " ";
	ret = ret->next;
    }
    cout << endl;

    return 0;
}


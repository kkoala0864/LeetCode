#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
    public :
        Solution() {}
        ListNode* removeDuplicates(ListNode *head);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


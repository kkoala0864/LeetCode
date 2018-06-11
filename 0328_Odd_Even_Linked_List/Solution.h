#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public :
        Solution() {}
	ListNode* oddEvenList(ListNode* head);
	ListNode* oddEvenList2(ListNode* head) const;
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


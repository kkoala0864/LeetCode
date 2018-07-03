struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public :
        Solution() {}
	ListNode* removeNthFromEnd(ListNode* head, int n);
	ListNode* removeNthFromEnd2(ListNode* head, int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


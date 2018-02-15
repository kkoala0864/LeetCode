#include <cstddef>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};


class Solution {
    public :
        Solution() {}
	void deleteNode(ListNode* node);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


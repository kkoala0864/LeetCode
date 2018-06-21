#include <vector>
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public :
        Solution() {}
	vector<ListNode*> splitListToParts(ListNode* root, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


#include <vector>
#include <memory>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
    public :
        Solution() {}
	bool hasCycle(ListNode* head);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


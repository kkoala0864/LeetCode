#include <vector>
#include <memory>

using std::shared_ptr;

struct ListNode {
    int val;
    shared_ptr<ListNode> next;
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
    public :
        Solution() {}
        void removeDuplicatesKeepFirst(shared_ptr<ListNode> head);
        void removeDuplicatesAll(shared_ptr<ListNode> head);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


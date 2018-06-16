
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
    public :
        Solution() {}
	RandomListNode *copyRandomList(RandomListNode *head);
	RandomListNode *copyRandomList2(RandomListNode *head);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


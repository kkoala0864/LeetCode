#include <vector>

using std::vector;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public :
        Solution() {}
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


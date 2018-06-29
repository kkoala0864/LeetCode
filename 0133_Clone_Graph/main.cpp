#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    UndirectedGraphNode* one = new UndirectedGraphNode(-1);
    UndirectedGraphNode* two = new UndirectedGraphNode(1);
    one->neighbors.emplace_back(two);
    Solution* test = new Solution();
    UndirectedGraphNode* ret = test->cloneGraph(one);
    cout << one->label << endl;
    cout << one->neighbors.at(0)->label << endl;

    return 0;
}


#include <Solution.h>
#include <iostream>
#include <unordered_map>
using namespace std;

void dfs(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& LabelMapping) {
    UndirectedGraphNode* addNode = new UndirectedGraphNode(node->label);
    LabelMapping.emplace(node->label, addNode);
    for (const auto& idx : node->neighbors) {
	auto neighborsNode = LabelMapping.find(idx->label);
	if (neighborsNode != LabelMapping.end()) {
	    addNode->neighbors.emplace_back(neighborsNode->second);
	} else {
	    dfs(idx, LabelMapping);
	    addNode->neighbors.emplace_back(LabelMapping.at(idx->label));
	}
    }
}

UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *node) {
    if (nullptr == node) return nullptr;
    unordered_map<int, UndirectedGraphNode*> LabelMapping;
    dfs(node, LabelMapping);
    return LabelMapping.at(node->label);
}

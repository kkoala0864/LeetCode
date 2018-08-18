#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string traverse(TreeNode* node, unordered_map<string, vector<TreeNode*>>& ht) {
    if (node == nullptr) return "";
    string curStr = "(" + traverse(node->left, ht) + to_string(node->val) + traverse(node->right, ht) + ")";
    ht[curStr].emplace_back(node);
    return curStr;
}

vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, vector<TreeNode*>> ht;
    vector<TreeNode*> ret;
    traverse(root, ht);
    for (const auto& bucket : ht) {
	if (bucket.second.size() > 1) {
	    ret.emplace_back(bucket.second.at(0));
	}
    }
    return ret;
}

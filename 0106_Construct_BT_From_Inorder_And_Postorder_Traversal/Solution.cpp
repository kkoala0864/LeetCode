#include <Solution.h>
#include <iostream>
#include <unordered_map>


using namespace std;

void construct(TreeNode*& root, int start, int end, unordered_map<int, int>& rootMap, vector<int>::const_reverse_iterator& crIter) {
    if (start == end) {
	root = new TreeNode(*crIter++);
	return;
    }

    root = new TreeNode(*crIter++);
    int idx = rootMap.at(root->val);
    if (idx+1 <= end)
	construct(root->right, idx+1, end, rootMap, crIter);
    if (idx-1 >= start)
	construct(root->left, start, idx-1, rootMap, crIter);
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) {
	return nullptr;
    }

    unordered_map<int, int> rootMap;
    for (int i = 0 ; i < inorder.size() ; ++i) {
	rootMap.emplace(inorder.at(i), i);
    }
    auto crIter = postorder.crbegin();
    TreeNode* root = nullptr;
    construct(root, 0, inorder.size() - 1, rootMap, crIter);
    return root;
}


#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

void construct(TreeNode*& root, int start, int end, unordered_map<int, int>& locMap, vector<int>::iterator& preIter) {
    root = new TreeNode(*preIter++);
    if (start == end) {
	return;
    }

    int rootIdx = locMap.at(root->val);
    if (rootIdx-1 >= start)
	construct(root->left, start, rootIdx-1, locMap, preIter);
    if (rootIdx+1 <= end)
	construct(root->right, rootIdx+1, end, locMap, preIter);
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;

    unordered_map<int, int> locMap;
    int size = preorder.size();
    vector<int>::iterator preIter = preorder.begin();
    for (int i = 0 ; i < size; ++i) {
	locMap.emplace(inorder.at(i), i);
    }
    TreeNode* root = nullptr;
    construct(root, 0, size-1, locMap, preIter);
    return root;
}

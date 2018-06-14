#include <Solution.h>
#include <iostream>

using namespace std;

vector<TreeNode*> Solution::splitBST(TreeNode* root, int V) {
    vector<TreeNode*> ret(2, nullptr);
    if (root == nullptr) return ret;

    if (root->val > V) {
	ret[1] = root;
	vector<TreeNode*> subRet = splitBST(root->left, V);
	root->left = subRet[1];
	ret[0] = subRet[0];
    } else {
	ret[0] = root;
	vector<TreeNode*> subRet = splitBST(root->right, V);
	root->right = subRet[0];
	ret[1] = subRet[1];
    }
    return ret;
}


vector<TreeNode*> Solution::splitBST2(TreeNode* root, int V) {
    TreeNode Less(0);
    TreeNode *LessAppend = &Less;
    TreeNode More(0);
    TreeNode *MoreAppend = &More;

    while (root != nullptr) {
	if (root->val > V) {
	    MoreAppend->left = root;
	    MoreAppend = root;
	    root = root->left;
	    MoreAppend->left = nullptr;
	} else {
	    LessAppend->right = root;
	    LessAppend = root;
	    root = root->right;
	    LessAppend->right = nullptr;
	}
    }
    vector<TreeNode*> ret = {Less.right, More.left};
    return ret;

}

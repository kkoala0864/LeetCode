#include <Solution.h>
#include <iostream>
#include <climits>

using namespace std;

TreeNode* construcTree(int start, int end, vector<int>& nums) {
    if (end < start)
	return nullptr;

    int MaxVal(INT_MIN), MaxIdx(0);
    for (int i = start ; i <= end ; ++i) {
	if (MaxVal < nums.at(i)) {
	    MaxVal = nums.at(i);
	    MaxIdx = i;
	}
    }

    TreeNode *lv_root = new TreeNode(MaxVal);
    lv_root->left = construcTree(start, MaxIdx - 1, nums);
    lv_root->right = construcTree(MaxIdx + 1, end, nums);
    return lv_root;
}

TreeNode* Solution::constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty())
	return nullptr;

    return construcTree(0, nums.size() - 1, nums);

}

TreeNode* Solution::constructMaximumBinaryTree2(vector<int>& nums) {
    if (nums.empty())
	return nullptr;

    TreeNode *cur = new TreeNode(nums.at(0));

    for (int i = 1 ; i < nums.size() ; ++i) {
	TreeNode *next = new TreeNode(nums.at(i));
	if (cur->val < next->val) {
	    next->left = cur;
	    cur = next;
	} else {
	    TreeNode *iter = cur;
	    while (iter->right && iter->right->val > next->val) {
		iter = iter->right;
	    }
	    next->left = iter->right;
	    iter->right = next;
	}
    }
    return cur;
}

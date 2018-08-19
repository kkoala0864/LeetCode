#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int traverse(TreeNode* node, unordered_map<int, int>& CntMap, int& MaxVal, int& MaxCnt) {
    if (node == nullptr) return 0;
    int sum = traverse(node->left, CntMap, MaxVal, MaxCnt) + traverse(node->right, CntMap, MaxVal, MaxCnt) + node->val;
    ++CntMap[sum];
    if (CntMap[sum] > MaxCnt) {
	MaxCnt = CntMap[sum];
	MaxVal = sum;
    }
    return sum;
}

vector<int> Solution::findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> CntMap;
    vector<int> ret;
    if (root == nullptr) return ret;
    int MaxVal(0);
    int MaxCnt(INT_MIN);
    traverse(root, CntMap, MaxVal, MaxCnt);
    for (const auto& bucket : CntMap) {
	if (bucket.second == MaxCnt)
	    ret.emplace_back(bucket.first);
    }
    return ret;
}



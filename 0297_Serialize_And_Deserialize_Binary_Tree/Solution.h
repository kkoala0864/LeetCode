#include <string>
#include <queue>

using std::string;
using std::queue;
using std::to_string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public :
	Solution() {}
	~Solution() {}
	string serialize(TreeNode* root) {
	    string data = serial(root);
	    return data.substr(1);
	}
	TreeNode* deserialize(string data) {
	    int idx(0);
	    return deserial(data, idx);
	}
    private :
	string serial(TreeNode* root) {
	    string ret("");
	    if (nullptr == root) {
		ret += ",#";
		return ret;
	    }
	    ret += "," + to_string(root->val);
	    ret += serial(root->left);
	    ret += serial(root->right);
	    return ret;
	}
	TreeNode* deserial(const string& data, int& idx) {
	    if (idx >= data.size()) {
		return nullptr;
	    }

	    int start = idx;
	    while (idx < data.size() && data.at(idx) != ',')
		++idx;

	    string nodeStr = data.substr(start, idx - start);
	    if (nodeStr == "#") return nullptr;

	    TreeNode* ret = new TreeNode(stoi(nodeStr));
	    ++idx;
	    ret->left = deserial(data, idx);
	    ++idx;
	    ret->right = deserial(data, idx);
	    return ret;
	}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


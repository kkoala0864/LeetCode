#include <stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    public :
	BSTIterator(TreeNode *root);
	bool hasNext();
	int next();
    private :
	stack<TreeNode*> smallStack;
        virtual ~BSTIterator() {}
        BSTIterator& operator=(const BSTIterator& source);
        BSTIterator(const BSTIterator&);
};


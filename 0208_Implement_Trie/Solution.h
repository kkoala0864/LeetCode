#include <vector>
#include <string>
using std::string;
using std::vector;

struct TrieNode {
    bool term;
    vector<TrieNode*> ChildNode;
    TrieNode() : term(false), ChildNode(26, nullptr) {}
};

class Trie {
    public :
	/** Initialize your data structure here. */
	Trie() {
	    root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
	    TrieNode* iter = root;
	    int idx(0);
	    while (idx < word.size()) {
		if (iter->ChildNode.at(word.at(idx)-'a') == nullptr) {
		    iter->ChildNode.at(word.at(idx)-'a') = new TrieNode();
		}
		iter = iter->ChildNode.at(word.at(idx)-'a');
		++idx;
	    }
	    iter->term = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
	    int idx(0);
	    TrieNode* iter = root;
	    while (iter && idx < word.size()) {
		iter = iter->ChildNode.at(word.at(idx) - 'a');
		++idx;
	    }
	    if (idx < word.size()) return false;
	    if (iter->term) return true;
	    else return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
	    int idx(0);
	    TrieNode* iter = root;
	    while (iter && idx < prefix.size()) {
		iter = iter->ChildNode.at(prefix.at(idx)-'a');
		++idx;
	    }
	    if (idx == prefix.size()) return true;
	    else return false;
	}
    private :
	TrieNode* root;
        virtual ~Trie() {}
        Trie& operator=(const Trie& source);
        Trie(const Trie&);
};


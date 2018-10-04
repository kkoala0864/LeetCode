#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <set>

using std::cout;
using std::endl;
using std::set;
using std::unordered_map;

string find(const string& s, unordered_map<string, string>& p) {
    return p[s] == s ? s : find(p[s], p);
}

// union and find
vector<vector<string>> Solution::accountsMerge(vector<vector<string>>& accounts) {
    const int size = accounts.size();
    unordered_map<string, string> owner;
    unordered_map<string, string> parent;
    unordered_map<string, set<string>> unions;

    for (int i = 0 ; i < size ; ++i) {
	for (int j = 1 ; j < accounts[i].size() ; ++j) {
	    parent[accounts[i][j]] = accounts[i][j];
	    owner[accounts[i][j]] = accounts[i][0];
	}
    }

    // path compression
    for (int i = 0 ; i < size ; ++i) {
	string p = find(accounts[i][1], parent);
	for (int j = 2 ; j < accounts[i].size() ; ++j) {
	    parent[find(accounts[i][j], parent)] = p;
	}
    }

    for (int i = 0 ; i < size ; ++i) {
	for (int j = 1 ; j < accounts[i].size() ; ++j) {
	    unions[find(accounts[i][j], parent)].emplace(accounts[i][j]);
	}
    }

    vector<vector<string>> res;
    for (const auto& p : unions) {
	vector<string> emails(p.second.begin(), p.second.end());
	emails.emplace(emails.begin(), owner[p.first]);
	res.emplace_back(emails);
    }

    return res;
}


#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

bool Solution::areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) return false;
    unordered_map<string, string> connection;

    // path compression
    for (const auto& strPair : pairs) {
	string v1 = strPair.first;
	string v2 = strPair.second;

	if (connection.find(v1) == connection.end())
	    connection.emplace(v1, v1);
	else
	    while (v1 != connection.at(v1)) v1 = connection.at(v1) = connection.at(connection.at(v1));

	if (connection.find(v2) == connection.end())
	    connection.emplace(v2, v2);
	else
	    while (v2 != connection.at(v2)) v2 = connection.at(v2) = connection.at(connection.at(v2));

	if (v1 != v2)
	    connection.at(v2) = v1;
    }
    for (int i = 0 ; i < words1.size() ; ++i) {
	string one = words1.at(i);
	string two = words2.at(i);
	if (one == two) continue;
	if (connection.find(one) == connection.end() ||
		connection.find(two) == connection.end()) return false;
	while (one != connection.at(one)) one = connection.at(one);
	while (two != connection.at(two)) two = connection.at(two);
	if (one != two) return false;
    }
    return true;
}

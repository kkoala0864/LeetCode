#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using std::vector;
using std::string;
using std::unordered_map;
using std::pair;

bool cmp(const pair<string, int>& lhs, const pair<string, int>& rhs) {
    if (lhs.second == rhs.second)
	return lhs.first < rhs.first;
    else
	return lhs.second > rhs.second;
}

class AutocompleteSystem {
    public :
	AutocompleteSystem(vector<string> sentences, vector<int> times) {
	    for (int i = 0 ; i < sentences.size() ; ++i) {
		_SentenceCnt.emplace(sentences.at(i), times.at(i));
	    }
	    _input = "";
	}

	vector<string> input(char c) {
	    vector<string> ret;
	    if (c == '#') {
		++_SentenceCnt[_input];
		_input = "";
		sortVec.clear();
		return ret;
	    }

	    _input.push_back(c);
	    if (1 == _input.size()) {
		for (const auto& strCnt : _SentenceCnt) {
		    if (strCnt.first.at(0) == c) {
			sortVec.emplace_back(strCnt.first, strCnt.second);
		    }
		}
	    } else {
		vector<pair<string, int>> tmp;
		for (const auto& strCnt : sortVec) {
		    if (strCnt.first.at(_input.size()-1) == c) {
			tmp.emplace_back(strCnt);
		    }
		}
		sortVec = move(tmp);
	    }

	    sort(sortVec.begin(), sortVec.end(), cmp);
	    for (int i = 0 ; i < sortVec.size() ; ++i) {
		if (3 == i) break;
		ret.emplace_back(sortVec.at(i).first);
	    }
	    return ret;
	}
    private :
	string _input;
	unordered_map<string, int> _SentenceCnt;
	vector<pair<string, int>> sortVec;
        virtual ~AutocompleteSystem() {}
        AutocompleteSystem& operator=(const AutocompleteSystem& source);
        AutocompleteSystem(const AutocompleteSystem&);
};


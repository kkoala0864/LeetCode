#include <Solution.h>
#include <iostream>

using namespace std;

vector<string> Solution::removeComments(vector<string>& source) {
    if (!source.empty()) {
	vector<pair<vector<string>::iterator, int>> mark;

	for (auto line = source.begin() ; line != source.end() ;) {
	    bool lineClear(false);
	    bool haveSymbol(false);
	    for (int ch = 0 ; ch < line->size() ; ++ch) {
		if (line->at(ch) == '/') {
		    if (ch+1 < line->size() && line->at(ch+1) == '/') {
			line->erase(line->begin() + ch, line->end());
			break;
		    } else if (ch+1 < line->size() && line->at(ch+1) == '*') {
			haveSymbol = true;
			mark.emplace_back(line, ch);
		    }
		} else if (line->at(ch) == '*') {
		    if (ch+1 < line->size() && line->at(ch+1) == '/') {
			if (line == mark.back().first) {
			    line->erase(line->begin() + mark.back().second, line->begin() + (ch+2));
			} else {
			    lineClear = true;
			    mark.back().first->erase(mark.back().first->begin() + mark.back().second, mark.back().first->end());
			    *mark.back().first += line->substr(ch+2);
			}
			mark.pop_back();
		    }
		}
	    }

	    if (lineClear || (!mark.empty() && !haveSymbol)) {
		line = source.erase(line);
	    } else {
		++line;
	    }
	}
    }
    for (auto iter = source.begin() ; iter != source.end() ;) {
	if (iter->empty())
	    iter = source.erase(iter);
	else
	    ++iter;
    }
    return source;
}

vector<string> Solution::removeComments2(vector<string>& source) {
    vector<string> ans;
    bool inBlock = false;
    string sf;
    for (auto& t:source) {
	for (int i = 0; i < t.size();) {
	    if (!inBlock) {
		if (i + 1 == t.size()) sf += t[i++];
		else {
		    string m = t.substr(i,2);
		    if (m == "/*") inBlock = 1, i+=2;
		    else if (m == "//") break;
		    else sf += t[i++];
		}
	    }
	    else {
		if (i + 1 == t.size()) i++;
		else {
		    string m = t.substr(i,2);
		    if (m == "*/") inBlock = 0, i+=2;
		    else i++;
		}
	    }
	}
	if (sf.size() && !inBlock) ans.push_back(sf), sf = "";
    }
    return ans;
}


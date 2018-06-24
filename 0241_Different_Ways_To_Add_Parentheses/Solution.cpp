#include <Solution.h>
#include <iostream>

using namespace std;

vector<int> Solution::diffWaysToCompute(string input) {
    if (input.empty()) return vector<int>();

    int cnt(0);
    vector<int> ret;
    for (int i = 0 ; i < input.size() ; ++i) {
	if (input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*') {
	    ++cnt;
	    vector<int> left = diffWaysToCompute(input.substr(0, i));
	    vector<int> right = diffWaysToCompute(input.substr(i+1));
	    for (const auto& leftV : left) {
		for (const auto& rightV : right) {
		    if (input.at(i) == '+')
			ret.emplace_back(leftV + rightV);
		    else if (input.at(i) == '-')
			ret.emplace_back(leftV - rightV);
		    else if (input.at(i) == '*')
			ret.emplace_back(leftV * rightV);
		}
	    }
	}
    }
    if (0 == cnt || (1 == cnt && input.at(0) == '-'))
	ret.emplace_back(stoi(input));
    return ret;
}

#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;
static const vector<string> digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
static const vector<string> tenDigits = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string convert(const string& numStr, int start) {
    string ret("");
    if (numStr.size() == start) return "";
    int size = numStr.size() - start;
    if (size > 9) {
	if (numStr.at(start) != '0') {
	    ret += digits.at(numStr.at(start) - '0') + " ";
	    ret += "Billion";
	    return ret += convert(numStr, 1);
	}
    } else {
	int localSize = size % 3 == 0 ? 3 : size % 3;
	for (int i = 0 ; i < localSize ; ++i) {
	    if (0 == i) {
		if (localSize > 1 && numStr.at(start+localSize-2) == '1') {
		    ret += " " + digits.at(stoi(numStr.substr(start+localSize-2, 2)));
		    ++i;
		} else {
		    if (numStr.at(start+localSize-1-i) != '0') {
			ret += " " + digits.at(numStr.at(start+localSize-1-i) - '0');
		    }
		}
	    } else if (1 == i) {
		if (numStr.at(start+localSize-1-i) > '1') {
		    ret = " " + tenDigits.at(numStr.at(start+localSize-1-i) - '0') + ret;
		}
	    } else if (2 == i) {
		if (numStr.at(start+localSize-1-i) != '0') {
		    ret = " " + digits.at(numStr.at(start+localSize-1-i) - '0') + " Hundred" + ret;
		}
	    }
	}
	if (size > 6 && !ret.empty()) {
	    ret += " Million";
	} else if (size > 3 && !ret.empty()) {
	    ret += " Thousand";
	}
	return ret += convert(numStr, start + localSize);
    }
}

string Solution::numberToWords(int num) {
    if (0 == num) return "Zero";
    string ret = convert(to_string(num), 0);
    int start(0);
    int end(ret.size()-1);
    while (ret.at(start) == ' ') {
	++start;
    }
    while (ret.at(end) == ' ') {
	--end;
    }
    return ret.substr(start, end-start+1);
}

const vector<string> A = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const vector<string> B = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
const vector<string> C = { "", "Thousand", "Million", "Billion" };

string f(int n) {
    if (n < 20) return A[n];
    if (n < 100) return B[n / 10] + (n % 10 ? " " : "") + A[n % 10];
    return A[n / 100] + " Hundred" + (n % 100 ? " " : "") + f(n % 100);
}

string Solution::numberToWords2(int num) {
    if (num == 0) return "Zero";
    int i = 0;
    string r = "";
    while (num > 0) {
	if (num % 1000)
	    r = f(num % 1000) + (i > 0 ? " " + C[i]: "") + (r.empty() ? "" : " ") + r;
	num /= 1000;
	i++;
    }
    return r;
}

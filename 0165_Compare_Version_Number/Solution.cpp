#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::compareVersion(string version1, string version2) {
    int start1(0), end1(0);
    int start2(0), end2(0);

    while (start1 < version1.size() && start2 < version2.size()) {
	while (end1 < version1.size() && version1.at(end1) != '.') {
	    ++end1;
	}
	int v1Num = stoi(version1.substr(start1, end1 - start1));
	while (end2 < version2.size() && version2.at(end2) != '.') {
	    ++end2;
	}
	int v2Num = stoi(version2.substr(start2, end2 - start2));
	cout << v1Num << " : " << v2Num << endl;
	if (v1Num > v2Num) return 1;
	else if (v1Num < v2Num) return -1;

	start1 = end1 + 1;
	end1 = start1;
	start2 = end2 + 1;
	end2 = start2;
    }

    while (start1 < version1.size()) {
	while (end1 < version1.size() && version1.at(end1) != '.') {
	    ++end1;
	}
	int v1Num = stoi(version1.substr(start1, end1 - start1));
	start1 = end1 + 1;
	end1 = start1;
	if (v1Num > 0)
	    return 1;
    }
    while (start2 < version2.size()) {
	while (end2 < version2.size() && version2.at(end2) != '.') {
	    ++end2;
	}
	int v2Num = stoi(version2.substr(start2, end2 - start2));
	start2 = end2 + 1;
	end2 = start2;
	if (v2Num > 0)
	    return -1;
    }
    return 0;
}

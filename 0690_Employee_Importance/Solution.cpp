#include <Solution.h>
#include <iostream>
#include <list>
#include <unordered_map>

using std::cout;
using std::endl;
using std::list;
using std::unordered_map;

int Solution::getImportance(vector<Employee*> employees, int id) {
    if (employees.empty()) {
	return 0;
    }

    int importance(0);
    list<int> subordinate;
    unordered_map<int, Employee*> hash_Employees;
    for (const auto& idx : employees) {
	hash_Employees[idx->id] = idx;
    }

    subordinate.push_back(id);
    while (!subordinate.empty()) {

	Employee *subIdx = hash_Employees[subordinate.front()];
	importance += subIdx->importance;
	if (!subIdx->subordinates.empty()) {
	    for (const auto& descendant : subIdx->subordinates) {
		subordinate.push_back(descendant);
	    }
	}
	subordinate.pop_front();
    }
    return importance;
}

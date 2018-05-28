#include <vector>
using std::vector;

// Employee info
class Employee {
    public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
    public :
        Solution() {}
	int getImportance(vector<Employee*> employees, int id);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};


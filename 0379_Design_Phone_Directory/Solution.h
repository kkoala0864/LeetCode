#include <unordered_map>


class PhoneDirectory {
    public :
	/** Initialize your data structure here
	 *         @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
	PhoneDirectory(int maxNumbers) {
	    for (int i = 0 ; i < maxNumbers ; ++i) {
		_Directory.emplace(i);
	    }
	    _MaxCnt = maxNumbers;
	}

	/** Provide a number which is not assigned to anyone.
	 *         @return - Return an available number. Return -1 if none is available. */
	int get() {
	    if (_Directory.size() == 0) return -1;
	    int number = *_Directory.begin();
	    _Directory.erase(_Directory.begin());
	    return number;
	}

	/** Check if a number is available or not. */
	bool check(int number) {
	    if (_Directory.find(number) != _Directory.end())
		return true;
	    else
		return false;
	}

	/** Recycle or release a number. */
	void release(int number) {
	    if (_Directory.size() < _MaxCnt)
		_Directory.emplace(number);
	}
    private :
	int _MaxCnt;
	unordered_set<int> _Directory;
        virtual ~PhoneDirectory() {}
        PhoneDirectory& operator=(const PhoneDirectory& source);
        PhoneDirectory(const PhoneDirectory&);
};



/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

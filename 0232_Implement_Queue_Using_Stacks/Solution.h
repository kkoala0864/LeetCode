#include <stack>

using std::stack;

class MyQueue {
    public :
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
	    _st.emplace(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
	    int ret(0);
	    if (1 == _st.size()) {
		ret = _st.top();
		_st.pop();
	    } else {
		stack<int> reverse;
		while (_st.size() > 1) {
		    reverse.emplace(_st.top());
		    _st.pop();
		}
		ret = _st.top();
		_st.pop();
		while (!reverse.empty()) {
		    _st.emplace(reverse.top());
		    reverse.pop();
		}
	    }
	    return ret;
	}

	/** Get the front element. */
	int peek() {
	    if (1 == _st.size()) {
		return _st.top();
	    }

	    int ret(0);
	    stack<int> reverse;
	    while (_st.size() > 1) {
		reverse.emplace(_st.top());
		_st.pop();
	    }
	    ret = _st.top();
	    while (!reverse.empty()) {
		_st.emplace(reverse.top());
		reverse.pop();
	    }
	    return ret;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
	    return _st.empty();
	}

    private :
	stack<int> _st;
        virtual ~MyQueue() {}
        MyQueue& operator=(const MyQueue& source);
        MyQueue(const MyQueue&);
};


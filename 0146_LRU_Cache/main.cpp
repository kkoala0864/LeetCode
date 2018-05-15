#include <Solution.h>
#include <iostream>

using namespace std;

int main() {
	LRUCache *obj = new LRUCache(2);
	obj->put(2, 1);
	obj->put(2, 2);
	cout << obj->get(2) << endl;
	obj->put(1, 1);
	obj->put(4, 1);
	cout << obj->get(2) << endl;
}

#include <Solution.h>
#include <iostream>

using namespace std;

LRUCacheVector::LRUCacheVector(int capacity) : _capacity(capacity) {
	if (INT_MAX < capacity) {
		cerr << "capacity too big" << endl;
		exit(1);
	} else {
		_capacity = capacity;
	}
}

int LRUCacheVector::get(int key) {
	int retValue(-1);

	for (int i = 0 ; i < _cache.size() ; ++i) {
		if (_cache.at(i).first == key) {
			retValue = _cache.at(i).second;
			_cache.erase(_cache.begin() + i);
			break;
		}
	}
	if (retValue >= 0) {
		_cache.push_back(make_pair(key, retValue));
	}
	return retValue;
}

void LRUCacheVector::put(int key, int value) {
	int i = 0;
	for (; i < _cache.size() ; ++i) {
		if (_cache.at(i).first == key) {
			_cache.erase(_cache.begin() + i);
			break;
		}
	}
	if (_cache.size() == _capacity) {
		_cache.erase(_cache.begin());
	}
	_cache.push_back(make_pair(key, value));
}

LRUCache::LRUCache(int capacity) {
	if (INT_MAX < capacity) {
		cerr << "capacity to big" << endl;
		exit(1);
	}
	_capacity = capacity;
}

void LRUCache::reorder(HashIntPair::iterator map_idx) {
	_order.erase(map_idx->second.second);
	_order.push_front(map_idx->first);
	map_idx->second.second = _order.begin();
}

int LRUCache::get(int key) {
	HashIntPair::iterator found = _cache.find(key);
	if (found == _cache.end()) {
		return -1;
	} else {
		reorder(found);
		return found->second.first;
	}
}

void LRUCache::put(int key, int value) {
	HashIntPair::iterator found = _cache.find(key);
	if (found != _cache.end()) {
		reorder(found);
	} else {
		if (_cache.size() == _capacity) {
			_cache.erase(_order.back());
			_order.pop_back();
		}
		_order.push_front(key);
	}
	_cache[key] = make_pair(value, _order.begin());
}


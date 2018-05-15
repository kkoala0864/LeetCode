#include <vector>
#include <utility>
#include <unordered_map>
#include <iterator>
#include <list>

using std::vector;
using std::list;
using std::pair;
using std::unordered_map;

class LRUCacheVector {
	public:
		LRUCacheVector(int capacity);
		int get(int key);
		void put(int key, int value);
	private :
		int _capacity;
		vector<pair<int, int>> _cache;
		virtual ~LRUCacheVector() {}
		LRUCacheVector& operator=(const LRUCacheVector& source);
		LRUCacheVector(const LRUCacheVector&);
};

class LRUCache {
	public :
		LRUCache(int capacity);
		int get(int key);
		void put(int key, int value);
	private:
		using IList = list<int>;
		using PairIntListIter = pair<int, IList::iterator>;
		using HashIntPair = unordered_map<int, PairIntListIter>;
		int _capacity;
		IList _order;
		HashIntPair _cache;
		void reorder(HashIntPair::iterator map_idx);
		virtual ~LRUCache() {}
		LRUCache& operator=(const LRUCache& source);
		LRUCache(const LRUCache&);
};

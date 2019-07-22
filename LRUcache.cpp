/*

// Deque to be used as double ended container for entry/removal of front/back
//	size_t capacity = 3;
//	std::deque<int> cache;
//	//=======================
//	// -FRONT- << << << -BACK-
//	// ^RECENT -------- ^OLD^
//	//=======================
// insert
// if data already exists, remove and insert at FRONT
// cache.erase(data)... cache.push_front(data)

// if data doesn't exist
// if cache is full
// cache.pop_back... cache.push_front(data)
// if cache NOT full
// cache.push_front(data)

*/

#include "pch.h"

// USAGE
//LRU lru;
//lru.insert(42);
//lru.insert(55);
//lru.insert(12);
//lru.insert(42);
//lru.insert(12);
//lru.insert(12);
//lru.insert(55);
//lru.insert(42);

class LRU {
private:
	std::deque<int> cache;
	size_t capacity = 5;
	size_t size{};
public:
	void insert(int data) {
		// if it doesn't exist
		// add it to the "front" or most recent
		if (std::find(begin(cache), end(cache), data) == cache.end()) {
			if (size == capacity) {
				cache.pop_back();
				cache.push_front(data);
			}
			else {
				cache.push_front(data);
			}
		}
		else {
			// if it does exist, move it to the front
			cache.erase(std::find(begin(cache), end(cache), data), cache.end());
			cache.push_front(data);
		}

	}
};

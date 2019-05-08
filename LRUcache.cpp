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
//
//////=======================
////// FRONT   << << << BACK
////// ^RECENT -------- ^^OLD
//////=======================

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

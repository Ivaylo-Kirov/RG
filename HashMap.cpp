#include "pch.h"
//
//HashMap hm;
//hm.insert(42);
//hm.insert(55);
//hm.insert(12);
//
//hm.erase(55);
//auto result = hm.find(12);
//auto result2 = hm.find(112);
//
class HashMap {
public:
	std::vector<std::forward_list<int>> buckets;
	int numOfBuckets;

	HashMap(int numOfBuckets = 7)
		: numOfBuckets(numOfBuckets)
	{
		buckets.resize(numOfBuckets);
	}

	int hashCode(int data) {
		return data % numOfBuckets;
	}

	void insert(int data) {
		buckets[hashCode(data)].push_front(data);
	}

	void erase(int data) {
		buckets[hashCode(data)].remove(data);
	}

	bool find(int data) {
		auto itr = std::find(std::begin(buckets[hashCode(data)]), std::end(buckets[hashCode(data)]), data);
		if (itr == buckets[hashCode(data)].end()) {
			return false;
		}
		else {
			return true;
		}
	}

};

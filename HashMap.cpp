/*

// ====================================class HashTable
// int num_buckets
// list<T>* buckets_array
// ==================================== hashFunction
// data % num_buckets
// returns index of the bucket
// ==================================== insert
// int index = hashFunction(data)
// .push_back(data)
// ====================================erase
// int index = hashFunction(data)
// erase/remove idiom or other, depending on structure used
// ====================================print
// for num_buckets
// for item in buckets[i]
// ====================================

*/

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

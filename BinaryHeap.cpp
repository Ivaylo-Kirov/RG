/*

// ====================================class MyBinaryHeap
// size_t size, size_t capacity
// int* buffer
// ====================================sink
// swap left or right?
// keep comparing and swap
// ====================================swim
// larger than parent?
// swap and keep going
// ====================================resize
// capacity * 2
// temp[capacity]
// copy buffer into temp
// buffer = temp
// ====================================insert
// check for resize
// insert at end
// swim
// size++
// ====================================popMax
// replace first with last
// sink first
// delete last
// size--
// ====================================top
// cout buffer[0]
// ====================================getParentIndex
// currentIndex - 1 / 2
// ====================================getLeftChildIndex
// currentIndex + 1 * 2) - 1
// ====================================getRightChildIndex
// currentIndex + 1) * 2
// 

*/

#include "pch.h"

// USAGE
//BinaryHeap bh;
//
//bh.insert(42);
//bh.insert(55);
//
//bh.insert(12);
//
//bh.pop();

class BinaryHeap {
public:
	size_t capacity;
	int* buffer;
	size_t size{};

	void insert(int data) {
		buffer[size] = data;
		swim(size);
		++size;
	}

	void swim(int index) {
		if (buffer[index] > buffer[parent(index)]) {
			std::swap(buffer[index], buffer[parent(index)]);
			swim(parent(index));
		}
	}

	int parent(int index) {
		return (index - 1) / 2;
	}

	void pop() {
		std::swap(buffer[0], buffer[size - 1]);
		buffer[size - 1] = NULL;
		--size;
		sink(0);
	}

	int leftIndex(int index) {
		return (index * 2) + 1;
	}

	int rightIndex(int index) {
		return (index * 2) + 2;
	}

	void sink(int index) {
		int biggerChildIndex = buffer[leftIndex(index)] > buffer[rightIndex(index)] ? leftIndex(index) : rightIndex(index);
		if (buffer[index] < buffer[biggerChildIndex]) {
			std::swap(buffer[index], buffer[biggerChildIndex]);
			sink(biggerChildIndex);
		}
	}

	BinaryHeap(size_t capacity = 3)
		: capacity(capacity)
		, buffer(new int[capacity])
	{}

	BinaryHeap(const BinaryHeap& copy)
		: capacity(copy.capacity)
		, buffer(new int[capacity])
	{
		std::copy(copy.buffer, copy.buffer + copy.capacity, buffer);
	}

	BinaryHeap(BinaryHeap&& copy)
		: BinaryHeap()
	{
		swap(*this, copy);
	}

	BinaryHeap& operator=(BinaryHeap copy) {
		swap(*this, copy);
		return *this;
	}

	friend void swap(BinaryHeap& first, BinaryHeap& second) {
		using std::swap;
		swap(first.capacity, second.capacity);
		swap(first.buffer, second.buffer);
	}

	~BinaryHeap() {
		delete buffer;
	}
};

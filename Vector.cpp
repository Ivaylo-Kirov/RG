#include "pch.h"

 USAGE
MyVector mv;

mv.insert(42);
mv.insert(55);

mv.insert(12);

mv.erase(55);

class MyVector {
private:
	size_t capacity;
	int* buffer;
	size_t size{};
public:
	MyVector(int capacity = 3)
		: capacity(capacity)
		, buffer(new int[capacity])
	{}

	void insert(int data) {
		if (size == capacity) {
			resize();
		}
		buffer[size] = data;
		++size;
	}

	void resize() {
		capacity *= 2;
		int* temp = new int[capacity];
		std::copy(temp, temp + size, buffer);
		buffer = temp;
	}

	void erase(int data) {

		for (gsl::index i{}; i < size; ++i) {
			if (buffer[i] == data) {
				std::swap(buffer[i], buffer[size - 1]);
				buffer[size - 1] = NULL;
				--size;
			}
		}

	}

	MyVector(const MyVector& copy)
		: capacity(copy.capacity)
		, buffer(new int[capacity])
	{
		std::copy(copy.buffer, copy.buffer + copy.capacity, buffer);
	}

	MyVector& operator=(MyVector copy) {
		swap(*this, copy);
		return *this;
	}

	friend void swap(MyVector& first, MyVector& second) {
		using std::swap;
		swap(first.capacity, second.capacity);
		swap(first.buffer, second.buffer);
	}

	MyVector(MyVector&& copy)
		: MyVector()
	{
		swap(*this, copy);
	}

	~MyVector() {
		delete[] buffer;
	}
};

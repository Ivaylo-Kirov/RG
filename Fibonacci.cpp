#include "pch.h"

auto result = fib(10);

int fib(int n) {

	// MEMOIZATION
	/*if (n < 2) return n;

	static std::map<int, int> cache;

	if (cache.find(n) != cache.end()) {
	return cache[n];
	}
	else {
	cache[n] = fib(n - 1) + fib(n - 2);
	}

	return cache[n];*/

	// BOTTOM UP
	int prev2 = 0;
	int prev = 1;
	int current;
	for (int i = 2; i <= n; ++i) {

		current = prev + prev2;
		prev2 = prev;
		prev = current;

	}

	return current;

}

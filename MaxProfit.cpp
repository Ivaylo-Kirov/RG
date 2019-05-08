#include "pch.h"

std::vector<int> nums{ 9, 1, 2, 8, 4, 5, 6, 7 };

auto result = maxProfit(nums);

int maxProfit(std::vector<int>& prices) {

	std::vector<int> diffs;
	diffs.reserve(prices.size());

	std::adjacent_difference(std::begin(prices), std::end(prices), std::back_inserter(diffs));

	return std::accumulate(std::next(std::begin(diffs)), std::end(diffs), 0, [](int accum, int value) {
		return std::max(accum, accum + value);
	});

}

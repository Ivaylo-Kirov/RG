#include "pch.h"

// USAGE
//auto result = binary_search_recursive(nums, 8, 0, 6);
//
bool binary_search(std::vector<int>& nums, int value) {
	int begin = 0;
	int end = nums.size() - 1;
	while (begin < end) {
		int mid = (end + begin) / 2;

		if (nums[mid] > value) {
			end = mid;
		}
		else if (nums[mid] < value) {
			begin = mid + 1;
		}
		else {
			return true;
		}
	}
	return false;
}

bool binary_search_recursive(std::vector<int>& nums, int value, int start, int end) {
	if (start < end) {
		int mid = (end + start) / 2;
		if (nums[mid] == value || nums[start] == value || nums[end] == value) return true;
		if (nums[mid] > value) {
			return binary_search_recursive(nums, value, start, mid);
		}
		else {
			return binary_search_recursive(nums, value, mid + 1, end);
		}

	}
	return false;
}

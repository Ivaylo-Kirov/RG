/*

Iterative
Takes in vector&, startindex, endindex, searchvalue
Main loop is while start < end
Check for matches and return true
Calculate mid.. End + start / 2
Is the value Left or right?
If left.. End = mid
If right.. Start = mid + 1
Return false if all values were exhausted and it never matched ‘true’

Recursive
Takes in vector&, startindex, endindex, searchvalue
Calculate mid.. End + start / 2
Check for matches and return true
Exit condition.. End >= start.. If it’s met, return false (value doesn’t exist)
is the value left or right?
If left.. recurse(vector, start, mid, searchvalue)
If right.. recurse(vector, mid + 1, end, searchvalue)

*/

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

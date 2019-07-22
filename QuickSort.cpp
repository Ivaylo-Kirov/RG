/*

// takes vector, start, end
// if start < end
// partition_element = partition(vector, start, end)
// recurse(vector, start, partition - 1)
// recurse(vector, partition + 1, end)

// partition
// takes vector, start, end
// squeeze and process.. Return pivot location

*/

#include "pch.h"

int partition(std::vector<int>& nums, int start_index, int end_index) {
	int pivot = nums[start_index];
	int s = start_index + 1;
	int e = end_index;

	while (s < e) {
		while (s < e && nums[s] < pivot) {
			s++;
		}
		while (s < e && nums[e] > pivot) {
			e--;
		}
		if (s < e) {
			std::swap(nums[s], nums[e]);
		}
	}

	std::swap(nums[start_index], nums[s - 1]);
	return s - 1;
}

void quickSort(std::vector<int>& nums, int start_index, int end_index) {
	if (start_index < end_index) {
		int partition_element = partition(nums, start_index, end_index);
		quickSort(nums, start_index, partition_element);
		quickSort(nums, partition_element + 1, end_index);
	}
}

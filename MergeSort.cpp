/*

// merge
// takes vector, start, mid, end
// create aux (vector.begin(), vector.end())
// i = start // will go start to mid
// j = mid + 1 // will go mid to end
// k = start // for aux
// get lower element from each side and insert into aux
// handle stragglers
// iterate start to end and insert into original vector

// mergeSort
// takes vector, start, end
// if start < end
// mid = end+start / 2
// mergeSort(vector, start, mid)
// mergeSort(vector, mid + 1, end)
// merge(vector, start, mid, end)

*/

#include "pch.h"

void merge(std::vector<int>& nums, int start_index, int mid, int end_index) {
	int i = start_index;
	int j = mid + 1;
	std::vector<int> aux(nums.begin(), nums.end());
	int auxi = start_index;

	while (i <= mid && j <= end_index) {
		if (nums[i] <= nums[j]) {
			aux[auxi++] = nums[i++];
		}
		else {
			aux[auxi++] = nums[j++];
		}
	}

	// stragglers
	while (i <= mid) {
		aux[auxi++] = nums[i++];
	}

	while (j <= end_index) {
		aux[auxi++] = nums[j++];
	}

	// think of the last iteration
	for (int i = start_index; i <= end_index; ++i) {
		nums[i] = aux[i];
	}

}

void mergeSort(std::vector<int>& nums, int start_index, int end_index) {
	if (start_index < end_index) {
		int mid = (end_index + start_index) / 2;
		mergeSort(nums, start_index, mid);
		mergeSort(nums, mid + 1, end_index);
		merge(nums, start_index, mid, end_index);
	}
}

#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 *
 * https://leetcode.com/problems/next-permutation/
 *
 * RESULT: Accepted
 *
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size() < 2)
            return;

		// 从尾部找到一个比N仅大一点的数字，进行交换
		// 然后从交换结束的位置，开始排序
        for(int i=nums.size()-2; i>=0; --i) {
			int bigger = findBigger(nums, i);
			if(bigger == -1)
				continue;
			swap(nums, i, bigger);

			reSortSub(nums, i+1);
			return;
        }

        // by default, reorder the nums
        for(int i=0; i<nums.size()/2; ++i)
            swap(nums, i, nums.size()-i-1);
    }

	int findBigger(const vector<int> &nums, int start) {
		int current = 10000000000;
		int idx = -1;

		for(int i=start+1; i<nums.size(); ++i) {
			if(nums[i] > nums[start] && nums[i]<current) {
				idx = i;
				current = nums[i];
			}
		}

		return idx;
	}

	void reSortSub(vector<int> &nums, int start){
		for(int i=start; i<nums.size(); ++i)
			for(int j=i+1; j<nums.size(); ++j)
				if(nums[i] > nums[j])
					swap(nums, i, j);
	}

    void swap(vector<int>& nums, int i, int j) {
		if(i == j)
			return;

        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
};

#endif

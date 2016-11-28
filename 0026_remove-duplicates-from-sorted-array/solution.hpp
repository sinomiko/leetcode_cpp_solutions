#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * RESULT: 	Accepted
 *
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty())
            return 0;

        std::size_t store_pos = 0;
        int curr_val = nums[0];

        for(std::size_t i=1; i<nums.size(); ++i) {
            if(nums[i] == curr_val)
                continue;

            curr_val = nums[i];
            nums[++store_pos] = curr_val;
        }

        return store_pos + 1; // pos -> count
    }
};

#endif
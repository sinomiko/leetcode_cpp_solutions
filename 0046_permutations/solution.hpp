#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 * https://leetcode.com/problems/permutations/
 *
 * RESULT: Accepted
 *
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret_vec;



        for(int i=0; i<nums.size(); ++i) {
            vector<int> pref( { nums[i] });
            spawn(pref, removeElem(nums, i), ret_vec);
        }

        return ret_vec;
    }

    void spawn(vector<int> pref, vector<int> rest, vector<vector<int>> & ret) {
        if(rest.size() == 0) {
            ret.push_back(pref);
        }

        if(rest.size() == 1) {
            vector<int> tmp(pref);
            tmp.push_back(rest[0]);
            ret.push_back(tmp);
            return;
        }

        for(int j=0; j<rest.size(); ++j) {
            vector<int> tmp(pref);
            tmp.push_back(rest[j]);
            spawn(tmp, removeElem(rest, j), ret);
        }
    }

    vector<int> removeElem(const vector<int>& elem, int idx) {
        vector<int> ret(elem);
        ret.erase(ret.begin() + idx);

        return ret;
    }
};

#endif
#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include <map>
#include <vector>
#include <string>
#include <algorithm>

/**
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note: All inputs will be in lower-case.
 *
 * https://leetcode.com/problems/anagrams/
 *
 * RESULT: Accepted
 *
 */

using std::string;
using std::vector;
using std::multimap;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        multimap<string, string> ret_map;
        for (size_t i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            ret_map.insert({ tmp, strs[i] });
        }

        vector<vector<string>> ret;
        string stage;
        vector<string> stage_store;
        for (auto it = ret_map.begin(); it != ret_map.end(); ++it) {
            if (stage != it->first) {
                if (!stage_store.empty())
                    ret.push_back(stage_store);
                stage_store.clear();
                stage = it->first;
            }
            stage_store.push_back(it->second);
        }

        if (!stage_store.empty())
            ret.push_back(stage_store);

        return ret;
    }
};


#endif

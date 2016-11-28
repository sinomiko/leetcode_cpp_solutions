#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 * //https://leetcode.com/problems/combinations/
 *
 * RESULT: Time Limit Exceeded
 *
 */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;

        vector<int> n_expan;
        for(int i=1; i<=n; ++i)
            n_expan.push_back(i);

        if(n == k) {
            ret = { n_expan };
            return ret;
        }

        for(int i=0; i<n; ++i) {
            vector<int> pref( {i+1} );
            spawn(pref, removeElemEx(n_expan, i), ret, k);
        }

        return ret;
    }

    void spawn(vector<int> pref, vector<int> rest, vector<vector<int>>& ret, int k){
        if(pref.size() == k) {
            ret.push_back(pref);
            return;
        }

        if(pref.size() == (k-1)) {
            for(int i=0; i<rest.size(); ++i) {
                vector<int> tmp(pref);
                tmp.push_back(rest[i]);
                ret.push_back(tmp);
            }
            return;
        }

        for(int i=0; i<rest.size(); ++i) {
            vector<int> tmp( pref );
            tmp.push_back(rest[i]);
            spawn(tmp, removeElemEx(rest, i), ret, k);
        }
    }

    vector<int> removeElemEx(const vector<int> vec, int idx) {
        vector<int> node(vec);
        node.erase(node.begin(), node.begin() + idx + 1);
        return node;
    }
};

#endif
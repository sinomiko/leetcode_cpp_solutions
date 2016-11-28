#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
 *
 * Example1:
 *
 * a = 2
 * b = [3]
 *
 * Result: 8
 * Example2:
 *
 * a = 2
 * b = [1,0]
 *
 * Result: 1024
 *
 * https://leetcode.com/problems/super-pow/
 *
 * RESULT: 	Time Limit Exceeded
 */

class Solution {
public:
    int subsubCalc(int res, int cnt) {
        int ret = 1;

        for(int i=0; i<cnt; ++i) {
            ret *= res;
            if(ret > 1337)
                ret = ret % 1337;
        }

        return ret;
    }

    int subCalc(int res, int pref, int index_10) {
        int ret = 1;

        ret = subsubCalc(res, pref);

        for(int j=0; j<index_10; ++j) {
            ret = subsubCalc(ret, 10);
        }

        return ret;
    }

    int superPow(int a, vector<int>& b) {
        int ret = 1;
        int real_a = a % 1337;

        for(int i=0; i<b.size(); ++i){
            ret *= subCalc(real_a, b[i], b.size()-i-1);
            if(ret > 1337)
                ret %= 1337;
        }


        return ret % 1337;
    }
};

#endif

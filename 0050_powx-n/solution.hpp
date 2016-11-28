#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP
/**
 *
 * Implement pow(x, n).
 *
 * Subscribe to see which companies asked this question
 *
 * // https://leetcode.com/problems/powx-n/
 *
 * RESULT: Accepted
 *
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        signed long long lln = n;

        if(lln == 0)
            return ret;

        if(lln > 0) {
            ret = calc(x, lln);
        }

        if(lln < 0) {
            ret = calc(x, -lln);
            ret = 1 / ret;
        }

        return ret;
    }

    double calc(double x, signed long long n){
        int a = n /  0xFFFFFF;
        int b = n %  0xFFFFFF;

        double ret = 1;

        if(a) {
            double ret_16 = 1;
            for(int i=0; i<0xFFFFFF; ++i)
                ret_16 *= x;

            for(int i=0; i<a; ++i)
                ret *= ret_16;
        }

        for(int i=0; i<b; ++i)
            ret *= x;

        return ret;
    }
};

#endif
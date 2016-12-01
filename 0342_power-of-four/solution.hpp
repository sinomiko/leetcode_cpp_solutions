#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 *
 * Follow up: Could you solve it without loops/recursion?
 *
 * Credits:
 * Special thanks to @yukuairoy for adding this problem and creating all test cases.
 *
 * https://leetcode.com/problems/power-of-four/
 *
 * RESULT: Accepted
 *
 */

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1)
            return true;

        if ((num < 1) || (num & 0x3))
            return false;

        while (num >= 3) {
            if (num & 0x3)
                return false;

            num = num >> 2;
        }

        return num == 1 ? true : false;
    }
};


#endif

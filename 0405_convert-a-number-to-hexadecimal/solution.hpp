#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed integer.
 * You must not use any method provided by the library which converts/formats the number to hex directly.
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 * Example 2:
 *
 * Input:
 * -1
 *
 * Output:
 * "ffffffff"
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 *
 * RESULT: Accepted
 *
 */

class Solution {
public:
    string toHex(int num) {

        unsigned todo = num;
        if (num == 0)
            return string("0");

        if (num < 0)
            todo = (~(-num)) + 1;

        string ret;
        while (todo > 0) {
            char res = todo & 0xF;
            todo >>= 4;

            if (res < 10)
                res = res + '0';
            else
                res = (res - 10) + 'a';

            ret = res + ret;
        }

        return ret;
    }
};


#endif

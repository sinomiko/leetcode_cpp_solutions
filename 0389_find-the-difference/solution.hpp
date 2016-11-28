#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more letter at a random position.
 *
 * Find the letter that was added in t.
 *
 * Example:
 *
 * Input:
 * s = "abcd"
 * t = "abcde"
 *
 * Output:
 * e
 *
 * Explanation:
 * 'e' is the letter that was added.
 *
 * https://leetcode.com/problems/find-the-difference/
 *
 * RESULT: Accepted
 */


class Solution {
public:
    char findTheDifference(string s, string t) {
        std::size_t ret = -1;

        for(int i=0; i<t.size(); ++i){
            ret = -1;
            for(int j=0; j<s.size(); ++j){
                if(s[j] == t[i]){
                    s[j] = '\0';
                    ret = j;
                    break;
                }
            }

            if(ret == -1)
                return t[i];
        }

        return '\0';
    }
};

#endif
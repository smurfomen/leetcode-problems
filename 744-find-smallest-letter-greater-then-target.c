#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        You are given an array of characters letters that is sorted in non-decreasing order, and a character target.
        There are at least two different characters in letters.

        Return the smallest character in letters that is lexicographically greater than target.
        If such a character does not exist, return the first character in letters.



        Example 1:
                        Input: letters = ["c","f","j"], target = "a"
                        Output: "c"
                        Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

        Example 2:
                        Input: letters = ["c","f","j"], target = "c"
                        Output: "f"
                        Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

        Example 3:
                        Input: letters = ["x","x","y","y"], target = "z"
                        Output: "x"
                        Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].


        Constraints:
                        2 <= letters.length <= 10^4
                        letters[i] is a lowercase English letter.
                        letters is sorted in non-decreasing order.
                        letters contains at least two different characters.
                        target is a lowercase English letter.
*/



class Solution {
public:
    /*

      Time Complexity: O(log n + n)

      Space Complexity: O(1)

    */
    char nextGreatestLetter_plusN(vector<char> letters, char target) {
        int l = 0;
        int r = letters.size() - 1;

        int mid = -1;

        while(l <= r) {
            mid = (l + r) / 2;
            char c = letters[mid];

            if(c == target)
                break;

            else if(c < target)
                l = mid + 1;

            else if(c > target)
                r = mid - 1;
        }

        /* find next greatest letter from letters */
        for(int i = mid; i < letters.size(); ++i) {
            if(letters[i] > target)
                return letters[i];
        }


        return letters[0];
    }

    /*

      Time Complexity: O(log n)

      Space Complexity: O(1)

    */
    char nextGreatestLetter(vector<char> letters, char target) {
        int l = 0;
        int r = letters.size() - 1;

        int mid = -1;

        while(l <= r) {
            mid = (l + r) / 2;
            char c = letters[mid];

            if(c > target)
                r = mid - 1;

            else
                l = mid + 1;

        }

        /*
                searching will stop when l will > then r, and we need return next element then target
                but l can be last index in collection, then we can take mod division [l % collection size]. if l == 3 and size == 3 then it will be cyclic index 0

                f.e. [c, f, j] t=g  l=0,r=2

                1. l=0, r=2, mid=1  'f' < 'g'   -> l=(mid+1)=2, r=2
                2. l=2, r=2, mid=2  'j' > 'g'   -> r=(mid-1)=1, l=2;  so here l < r then break;

                return [l%len], e.g [2%3] -> return [2], e.g 'j' (next greater then target)


                f.e. [c, f, j] t=j  l=0,r=2

                1. l=0, r=2, mid=1  'f' < 'j'   -> l=(mid+1)=2,	r=2
                2. l=2, r=2, mid=2  'j' == 'j'  -> l=(mid+1)=3, r=2

                return [l%len], e.g [3%3] -> return [0], e.g 'c' cyclic
        */
        return letters[l % letters.size()];
    }
};


int main() {
    Solution sol;

    assert(sol.nextGreatestLetter({'c', 'f', 'g'}, 'a') == 'c');
    assert(sol.nextGreatestLetter({'c', 'f', 'g'}, 'c') == 'f');
    assert(sol.nextGreatestLetter({'c', 'f', 'g'}, 'g') == 'c');
    assert(sol.nextGreatestLetter({'c', 'f', 'j'}, 'd') == 'f');
    assert(sol.nextGreatestLetter({'c', 'f', 'j'}, 'g') == 'j');

    return 0;
}

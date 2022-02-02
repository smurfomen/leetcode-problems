#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:
        Input: s = "cbaebabacd", p = "abc"
        Output: [0,6]
        Explanation:
        The substring with start index = 0 is "cba", which is an anagram of "abc".
        The substring with start index = 6 is "bac", which is an anagram of "abc".

    Example 2:
        Input: s = "abab", p = "ab"
        Output: [0,1,2]
        Explanation:
        The substring with start index = 0 is "ab", which is an anagram of "ab".
        The substring with start index = 1 is "ba", which is an anagram of "ab".
        The substring with start index = 2 is "ab", which is an anagram of "ab".

    Constraints:
        1 <= s.length, p.length <= 3 * 104
        s and p consist of lowercase English letters.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int s_len = s.length();
        int p_len = p.length();

        if(s_len >= p_len)
        {
            unordered_map<char, int> smap, pmap;
            for(int i = 0; i < p_len; ++i) {
                smap[s[i]]++;
                pmap[p[i]]++;
            }

            for(int i = p_len; i < s_len; ++i) {
                if(smap == pmap)
                    result.push_back(i-p_len);

                smap[s[i]]++;
                smap[s[i-p_len]]--;

                if(smap[s[i-p_len]] == 0)
                    smap.erase(s[i-p_len]);
            }

            if(smap == pmap)
                result.push_back(s_len - p_len);
        }

        return result;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;

    assert((sol.findAnagrams("cbaebabacd", "abc") == vector<int>{0, 6}));
    assert((sol.findAnagrams("abab", "ab") == vector<int>{0, 1, 2}));

    cout << "tests is passed!" << endl;

    return 0;
}

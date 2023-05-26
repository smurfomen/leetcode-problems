#include <string>
#include <cassert>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
            Given an array of strings strs, group the anagrams together. You can return the answer in any order.

            An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


            Example 1:
                    Input: strs = ["eat","tea","tan","ate","nat","bat"]
                    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

            Example 2:
                    Input: strs = [""]
                    Output: [[""]]

            Example 3:
                    Input: strs = ["a"]
                    Output: [["a"]]


            Constraints:
                    1 <= strs.length <= 104
                    0 <= strs[i].length <= 100
                    strs[i] consists of lowercase English letters.
*/


/* time O(N*2) -> O(N)   and space O(N * 2) -> O(N) */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        unordered_map<string, vector<string>> m;

        int nCount = strs.size();

        /* push any element to map */
        for(int i = 0; i < nCount; ++i) {
            auto key = strs[i];

            /* sort anagram to take key for map */
            sort(key.begin(), key.end());

            /* push original string to map using sorted anagram - e.g. key */
            m[key].push_back(std::move(strs[i]));
        }

        vector<vector<string>> result;
        for(auto && v : m) {
            result.push_back(std::move(v.second));
        }

        return result;
    }
};


int main() {
    Solution sol;

    auto r0 = sol.groupAnagrams({"eat","tea","tan","ate","nat","bat"});
    auto r1 = sol.groupAnagrams({});
    auto r2 = sol.groupAnagrams({"a"});


    return 0;
}

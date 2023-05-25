#include <string>
#include <cassert>
#include <algorithm>
#include <stack>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <map>
#include <iostream>
using namespace std;

/*
            Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
            substring

            Example 1:
                    Input: s = "(()"
                    Output: 2
                    Explanation: The longest valid parentheses substring is "()".

            Example 2:
                    Input: s = ")()())"
                    Output: 4
                    Explanation: The longest valid parentheses substring is "()()".

            Example 3:
                    Input: s = ""
                    Output: 0

            Constraints:
                    0 <= s.length <= 3 * 104
                    s[i] is '(', or ')'.
*/


/* first try - not working on all sets */
class Solution_NotWork {
public:
    vector<int> findSubstring(string s, vector<string> words) {
        int word_size = words[0].size();
        int s_size = s.size();
        int words_count = words.size();

        vector<set<int>> sets;

        vector<int> result;

        for(int i = 0; i < s_size;) {
            string e = s.substr(i, word_size);

            if(find(words.cbegin(), words.cend(), e) != words.end()) {
                auto it = find_if(sets.begin(), sets.end(), [&](set<int> & ref) { return s.substr(*ref.begin(), word_size) == e; });
                if(it != sets.end())
                    (*it).insert(i);
                else
                    sets.push_back({i});

                i += word_size;
            }
            else
                i++;
        }


        while(true) {
            int min = *sets[0].begin();
            int max = *sets[sets.size() - 1].begin();

            for(auto & wordinputs : sets) {
                if(wordinputs.empty())
                    return result;

                if(*wordinputs.begin() > max) {
                    max = *wordinputs.begin();
                }

                if(*wordinputs.begin() < min) {
                    min = *wordinputs.begin();
                }
            }


            {
                string e = s.substr(max, word_size);
                int c = 0;
                for(auto && w : words) {
                    if(w == e)
                        c++;
                }

                if(c > 1)
                {
                    auto it = find_if(sets.begin(), sets.end(), [&](set<int> & e) { return e.count(max); });
                    auto iit = it->begin();
                    for(int i = 0; i < c - 1; ++i) {
                        iit++;
                    }

                    if(iit != it->end())
                        max = *iit;
                }
            }

            if(max - min == word_size * words_count - word_size) {
                vector<string> o = words;
                for(int i = min; i < max + word_size; i += word_size) {
                    auto e = s.substr(i, word_size);
                    auto it = find(o.begin(), o.end(), e);
                    if(it != o.end())
                        o.erase(it);
                }

                if(o.empty())
                    result.push_back(min);
            }

            auto it = find_if(sets.begin(), sets.end(), [min](set<int>& e) { return e.count(min); });
            if(it != sets.end()) {
                it->erase(min);
            }
        }

        return result;
    }
};










/* BruteForce - Time Limit Exceeded on big sets */
class Solution_BF {
public:
    vector<int> findSubstring(string s, vector<string> words) {
        int word_size = words[0].size();
        int s_size = s.size();
        int words_count = words.size();
        vector<int> result;

        for(int i = 0; i < s_size - words_count * word_size + 1; i++) {
            auto tt = s.substr(i, word_size);
            auto v = find(words.begin(), words.end(), tt);
            if(v != words.end()) {
                auto t = s.substr(i, words_count * word_size);

                vector<string> o = words;
                for(int j = i; j < i + words_count * word_size; j += word_size) {
                    auto it = find(o.begin(), o.end(), s.substr(j, word_size));
                    if(it != o.end())
                    {
                        o.erase(it);
                    }
                }

                if(o.empty())
                    result.push_back(i);
            }
        }

        return result;
    }
};





/* unordered_map solution time O(N^2) space O(N) */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> words) {
        unordered_map<string, int> counts;

        /* parse words to map couse every word can be in words many times */
        for (auto& word : words)
            counts[word]++;

        int n = s.length(), wCount = words.size(), wSize = words[0].length();

        vector<int> result;

        /* walk at s from 0 before n - words count * word length and check all sequences */
        for (int i = 0; i < n - wCount * wSize + 1; i++) {

            /* already see words in sequences */
            unordered_map<string, int> alreadySeen;


            int j = 0;
            for (; j < wCount; j++) {
                string word = s.substr(i + j * wSize, wSize);
                if (counts.find(word) != counts.end()) {
                    alreadySeen[word]++;

                    /* if in current sequence we see word more then need */
                    if (alreadySeen[word] > counts[word])
                        break;
                }

                /* or if word not find - go to next sequence */
                else break;
            }

            /* if j == words count - we find sequence, add first input point to this sequence */
            if (j == wCount)
                result.push_back(i);
        }


        return result;
    }
};



int main() {
    Solution sol;

    auto eq_vectors = [](vector<int> a, vector<int> b) { sort(a.begin(), a.end()); sort(b.begin(), b.end()); return a == b; };

    assert(eq_vectors(sol.findSubstring("barfoothefoobarman", {"foo","bar"}), {0,9}));
    assert(eq_vectors(sol.findSubstring("wordgoodgoodgoodbestword", {"word","good","best","good"}), {8}));
    assert(eq_vectors(sol.findSubstring("barfoofoobarthefoobarman", {"bar","foo","the"}), {6,9,12}));
    assert(eq_vectors(sol.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", {"fooo","barr","wing","ding","wing"}), {13}));
    assert(eq_vectors(sol.findSubstring("aaaaaaaaaaaaaa", {"aa","aa"}), {0,1,2,3,4,5,6,7,8,9,10}));

    return 0;
}















#include <string>
#include <cassert>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
            Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
            You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

            Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words,
            the empty slots on the left will be assigned more spaces than the slots on the right.
            For the last line of text, it should be left-justified, and no extra space is inserted between words.

            Note:

            A word is defined as a character sequence consisting of non-space characters only.
            Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
            The input array words contains at least one word.


            Example 1:
                    Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
                    Output:
                    [
                       "This    is    an",
                       "example  of text",
                       "justification.  "
                    ]

            Example 2:
                    Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
                    Output:
                    [
                      "What   must   be",
                      "acknowledgment  ",
                      "shall be        "
                    ]
                    Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
                    Note that the second line is also left-justified because it contains only one word.

            Example 3:
                    Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
                    Output:
                    [
                      "Science  is  what we",
                      "understand      well",
                      "enough to explain to",
                      "a  computer.  Art is",
                      "everything  else  we",
                      "do                  "
                    ]


            Constraints:
                    1 <= words.length <= 300
                    1 <= words[i].length <= 20
                    words[i] consists of only English letters and symbols.
                    1 <= maxWidth <= 100
                    words[i].length <= maxWidth
*/

/* time O(2N) and space O(2N) */
class Solution {
public:
    vector<string> fullJustify(vector<string> words, int maxWidth) {
        vector<string> result;

        /* go through all words sequentially */
        for(int i = 0; i < words.size();) {

            /* begin - first index word in words for current row */
            int begin = i;

            /* only letters from current row count */
            int len = 0;

            /* find next word which can not be placed into current row */
            for(; i < words.size(); ++i) {
                if(len + words[i].length() + i - begin <= maxWidth)
                    len += words[i].length();
                else
                    break;
            }


            /* end - last index word in words for current row */
            int end = i-1;

            /* total spaceholders length in current row */
            int spaces = maxWidth - len;


            int wCount = end - begin + 1;

            /* accumulator string - will be placed into result */
            string s;


            /* if end is last word in words - this is last row and need align left last row */
            if(end == words.size() - 1 || end == begin) {

                /* insert one space after all words except last word in row */
                for(int w = 0; w < wCount - 1; ++w) {
                    s += words[begin + w] + ' ';
                    spaces--;
                }

                /* append last word */
                s.append(words[begin + wCount - 1]);

                /* fill spaceholders to end row */
                s.append(string(spaces, ' '));
            }
            else
            {
                int l = begin;
                int r = end;

                /* add spaces to words from the current line one by one in a circle until there are no more spaces */
                while(l < r && spaces) {
                    words[l++] += ' ';

                    /* skip last word couse */
                    if(l == r)
                        l = begin;

                    spaces--;
                }

                /* make result string */
                for(int w = 0; w < wCount; ++w) {
                    s += words[begin + w];
                }
            }


            /* push result string to result */
            result.push_back(s);
        }

        return result;
    }
};


int main() {
    Solution sol;


    auto r0 = sol.fullJustify({"This", "is", "an", "example", "of", "text", "justification."}, 16);
    for(auto s : r0)
        cout << s << "| " << s.size() << endl;

    auto r1 = sol.fullJustify({"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}, 20);
    for(auto s : r1)
        cout << s << "| " << s.size() << endl;


    auto r2 = sol.fullJustify({"What","must","be","acknowledgment","shall","be"}, 16);
    for(auto s : r2)
        cout << s << "| " << s.size() << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <cassert>

using namespace std;

/*
Write a bash script to calculate the frequency of each word in a text file words.txt.
For simplicity sake, you may assume:
        * words.txt contains only lowercase characters and space ' ' characters.
        * Each word must consist of lowercase characters only.
        * Words are separated by one or more whitespace characters.


    Example:
        Assume that words.txt has the following content:
            the day is sunny the the
            the sunny is is

        Your script should output the following, sorted by descending frequency:
            the 4
            is 3
            sunny 2
            day 1


    Constraints:
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        k is in the range [1, the number of unique elements in the array].
        It is guaranteed that the answer is unique.
*/
class Solution {
public:
    void printWordFrequent(const char * file) {
        std::unordered_map<std::string, int> freq;

        std::ifstream ifs;
        ifs.open(file);

        std::string s;
        while(ifs >> s) {
            freq[s]++;
        }


        while(!freq.empty()) {
            auto it = freq.cbegin();
            auto max = it;
            for(;it != freq.end(); ++it) {
                if(it->second > max->second)
                    max = it;
            }

            std::cout << max->first << " " << max->second << std::endl;
            freq.erase(max);
        }
    }
};


int main(int argc, char * argv[]) {
    Solution sol;
    sol.printWordFrequent("words.txt");


    return 0;
}

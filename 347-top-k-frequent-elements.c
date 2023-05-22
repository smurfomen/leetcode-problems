#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:
        Input: nums = [1,1,1,2,2,3], k = 2
        Output: [1,2]

    Example 2:
        Input: nums = [1], k = 1
        Output: [1]

    Constraints:
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        k is in the range [1, the number of unique elements in the array].
        It is guaranteed that the answer is unique.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int> nums, int k) {
        vector<int> result;
        std::unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }


        int size = std::min<int>(k, freq.size());


        for(int i = 0; i < size; ++i) {
            auto it = freq.cbegin();
            auto max = it++;

            for(;it != freq.cend();++it) {
                if(it->second > max->second)
                    max = it;
            }

            result.push_back(max->first);
            freq.erase(result[i]);
        }

        return result;
    }
};


void print(std::vector<int> p) {
    for(int i = 0; i < p.size(); ++i) {
        std::cout << p[i] << " ";
    }

    std::cout << endl;
}


int main(int argc, char * argv[]) {
    Solution sol;

    assert((sol.topKFrequent({1,1,1,2,2,5,4}, 2) == vector<int>{1,2}));
    assert((sol.topKFrequent({1}, 1) == vector<int>{1}));

    auto a = sol.topKFrequent({1,2}, 3);
    sort(a.begin(), a.end());
    assert((a == vector<int>{1,2}));

    return 0;
}

#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
    Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
    Return k after placing the final result in the first k slots of nums.
    Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

    Custom Judge:
    The judge will test your solution with the following code:
    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length
    int k = removeDuplicates(nums); // Calls your implementation
    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }

    If all assertions pass, then your solution will be accepted.

    Example 1:
        Input: nums = [1,1,1,2,2,3]
        Output: 5, nums = [1,1,2,2,3,_]
        Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
        It does not matter what you leave beyond the returned k (hence they are underscores).

    Example 2:
        Input: nums = [0,0,1,1,1,1,2,3,3]
        Output: 7, nums = [0,0,1,1,2,3,3,_,_]
        Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
        It does not matter what you leave beyond the returned k (hence they are underscores).


    Constraints:
        1 <= nums.length <= 3 * 10^4
        -10^4 <= nums[i] <= 10^4
        nums is sorted in non-decreasing order.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cn = nums[0];
        int cnt = 1;
        int n = nums.size();
        int newCount = nums.size();
        for(int i = 1; i < newCount; ++i)
        {
            if(nums[i] == cn)
            {
                cnt++;
                if(cnt > 2)
                {
                    int k = i;
                    for(; k < newCount; ++k)
                    {
                        if(nums[k] != cn)
                            break;
                    }

                    int to_remove = k - i;
                    for(; k < newCount; ++k){
                        nums[k - to_remove] = nums[k];
                    }

                    newCount -= to_remove;
                    cnt = 1;
                    cn = nums[i];
                }
            }
            else {
                cnt = 1;
                cn = nums[i];
            }
        }

        return newCount;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;

    auto to_str = [](vector<int> & nums) {
        int n = nums.size();
        string s;
        s.append("{ ");
        for(int i = 0; i < n; ++i)
        {
            s.append(std::to_string(nums[i]));
            if(i < n - 1)
            {
                s.append(", ");
            }
        }
        s.append(" }");
        return s;
    };


    auto isEq = [](const vector<int> & nums1, const vector<int> & nums2, int n){
        for(int i = 0; i < n; ++i) {
            if(nums1[i] != nums2[i])
                return false;
        }

        return true;
    };

    {
        vector<int> nums {1,1,1,2,2,3};
        int r = sol.removeDuplicates(nums);
        cout << r << to_str(nums) << endl;
        assert(r == 5 && isEq(nums, {1,1,2,2,3}, r));
    }

    {
        vector<int> nums {1,1,1};
        int r = sol.removeDuplicates(nums);
        cout << r << to_str(nums) << endl;
        assert(r == 2 && isEq(nums, {1,1}, r));
    }

    {
        vector<int> nums {1,1,1,1};
        int r = sol.removeDuplicates(nums);
        cout << r << to_str(nums) << endl;
        assert(r == 2 && isEq(nums, {1,1}, r));
    }

    {
        vector<int> nums {1};
        int r = sol.removeDuplicates(nums);
        cout << r << to_str(nums) << endl;
        assert(r == 1 && isEq(nums, {1}, r));
    }


    {
        vector<int> nums {1,1,1,2,3,4,5,5,5};
        int r = sol.removeDuplicates(nums);
        cout << r << to_str(nums) << endl;
        assert(r == 7 && isEq(nums, {1,1,2,3,4,5,5}, r));
    }


    {
        vector<int> nums {1,1,1,2,2,2,3,3};
        int r = sol.removeDuplicates(nums);
        cout << r << to_str(nums) << endl;
        assert(r == 6 && isEq(nums, {1,1,2,2,3,3}, r));
    }


    cout << "tests is passed!" << endl;

    return 0;
}

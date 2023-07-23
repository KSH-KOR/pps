/*
922. Sort Array By Parity II
Easy
2.4K
86
Companies
Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

 

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedArray(n);

        int evenIdx = 0;  // Index for even positions
        int oddIdx = 1;   // Index for odd positions

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                sortedArray[evenIdx] = nums[i];  // Place even element at even position
                evenIdx += 2;
            } else {
                sortedArray[oddIdx] = nums[i];   // Place odd element at odd position
                oddIdx += 2;
            }
        }

        return sortedArray;
    }
};

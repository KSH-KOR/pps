/*
26. Remove Duplicates from Sorted Array
Easy
11.7K
15.6K
Companies
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

#include <vector>
using namespace std;

class Solution {
public:
/*
    int removeDuplicates(vector<int>& nums) {
        int prev = -999999;
        int k=0;
        vector<int>::iterator curr = nums.begin();
        for(auto it = nums.begin(); it < nums.end(); it++){
            if(prev == *it) continue;
            prev = *it;
            *curr = *it;
            curr++;
            k++;
        }

        curr++;
        curr = nums.end();
        return k;
    }*/
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n; // No duplicates to remove
        }

        int idx = 1; // Index to track the current position of unique elements

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[idx++] = nums[i]; // Store unique elements at the next available position
            }
        }

        return idx;
    }
};
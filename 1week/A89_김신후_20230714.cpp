/*
108. Convert Sorted Array to Binary Search Tree
Easy
9.9K
492
Companies
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.
*/

#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* constructBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = constructBST(nums, start, mid - 1);
        root->right = constructBST(nums, mid + 1, end);
        
        return root;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;
        int n = nums.size();
        
        for (int currentIndex = 0; currentIndex < n; currentIndex++) {
            if (nums[currentIndex] != 0) {
                nums[nonZeroIndex] = nums[currentIndex];
                nonZeroIndex++;
            }
        }
        
        while (nonZeroIndex < n) {
            nums[nonZeroIndex] = 0;
            nonZeroIndex++;
        }
    }
};

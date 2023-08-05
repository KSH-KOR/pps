//변수 a의 이름을 바꾼 후, 조건문 if (i != n - 1)를 삭제하고, 바로 start = nums[i + 1];로 값을 갱신하도록 하였습니다.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0];

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                if (start != nums[i])
                    result.push_back(to_string(start) + "->" + to_string(nums[i]));
                else
                    result.push_back(to_string(start));
                start = nums[i + 1];
            }
        }

        return result;
    }
};

/*
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int a = nums[0];

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                if (nums[i] != a)
                    result.push_back(to_string(a) + "->" + to_string(nums[i]));
                else
                    result.push_back(to_string(a));
                if (i != n - 1)
                    a = nums[i + 1];
            }
        }
        return result;
    }
};
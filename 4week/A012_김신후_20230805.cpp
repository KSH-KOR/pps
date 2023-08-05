// for (int j = 2; i * j < n; ++j) 대신 for (int j = i * i; j < n; j += i)로 수정하여 반복 범위를 줄였다. 
// 에라토스테네스의 체의 핵심적인 원리는 제곱근 이상의 배수들만 제거하면 되기 때문이다.

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int cnt = 0;
        vector<bool> nums(n, true);
        nums[0] = nums[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (nums[i]) {
                for (int j = i * i; j < n; j += i) {
                    nums[j] = false;
                }
            }
        }

        for (bool isPrime : nums) {
            if (isPrime) cnt++;
        }

        return cnt;
    }
};


/*class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int cnt = 0;
        vector<bool> nums(n, true);
        nums[0] = nums[1] = false;
        for (int i = 2; i < n; ++i)
            if (nums[i]) {
                ++cnt;
                for (int j = 2; i * j < n; ++j)
                    nums[i * j] = false;
            }
        return cnt;
    }
};
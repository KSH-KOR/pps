// 불필요한 조건문과 변수를 제거하여 코드를 더 간결하고 효율적으로 만들었다.
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};


/*
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            digits.push_back(1);
            return digits;
        }
        if (digits.back() != 9) {
            digits.back()++;
        }
        else {
            int popCount = 0;
            while (digits.back() == 9) {
                digits.pop_back();
                popCount++;
                if (digits.empty()) break;
            }
            if (digits.empty()) digits.push_back(1);
            else digits.back()++;
            for (int i = 0; i < popCount; i++) {
                digits.push_back(0);
            }
        }
        return digits;

    }
};
*/
// answer 벡터를 탐색하는 방식 대신, 비트 연산인 XOR(^)을 사용하여 유일한 숫자를 찾는 방법으로 변경하다. 
// XOR은 자기 자신과 두 번 XOR되면 원래 값으로 돌아오는 특성을 이용하였다.

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    vector<int> v = { 2, 2, 1 };
    cout << Solution().singleNumber(v);
}

/*

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> answer;
        bool found;
        for (auto x : nums) {
            found = false;
            for (auto it = answer.begin(); it < answer.end(); it++) {
                if (*it == x) {
                    answer.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found) answer.push_back(x);
        }
        return answer[0];
    }
};

int main() {
    vector<int> v = { 2, 2, 1 };
    cout << Solution().singleNumber(v);
}
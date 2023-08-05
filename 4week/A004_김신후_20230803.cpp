// 조건문을 반대로 바꾸어 코드를 더 간결하게 만들었다.
// 불필요한 중괄호를 제거하여 코드를 간결하게 만들었다.

#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int x : arr) {
        if (x % divisor == 0) {
            answer.push_back(x);
        }
    }
    if (answer.empty()) {
        return { -1 };
    }
    sort(answer.begin(), answer.end());
    return answer;
}


// #include <string>
// #include <vector>
// #include <algorithm> 


// using namespace std;

// vector<int> solution(vector<int> arr, int divisor) {
//     vector<int> answer;
//     for (auto x : arr) {
//         if (x % divisor != 0) continue;
//         answer.push_back(x);
//     }
//     if (answer.empty()) return { -1 };
//     sort(answer.begin(), answer.end());
//     return answer;
// }
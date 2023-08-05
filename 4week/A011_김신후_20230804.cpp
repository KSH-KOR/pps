
// for (int stage : stages) 형태의 범위 기반 for 루프를 사용하여 더 간단하게 실패 횟수를 계산하도록 하였다.
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, float>& a, const pair<int, float>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> failRate;
    int stageSize = stages.size();
    int ans[501] = { 0 };

    for (int stage : stages) {
        if (stage <= N) {
            ans[stage]++;
        }
    }

    int len = stageSize;
    for (int i = 1; i <= N; i++) {
        if (len == 0) {
            failRate.push_back(pair<int, float>(i, 0));
        } else {
            failRate.push_back(pair<int, float>(i, 1.0 * ans[i] / len));
            len -= ans[i];
        }
    }

    sort(failRate.begin(), failRate.end(), cmp);

    for (const auto& pair : failRate) {
        answer.push_back(pair.first);
    }
    return answer;
}

int main() {
    solution(6, { 1, 2, 2, 3, 3, 1, 1, 4 });
}


/*
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, float>& a, const pair<int, float>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> failRate;
    int stageSize = stages.size();
    int ans[501] = { 0 };
    for (int i = 1; i <= N; i++) {
        for (auto iter = stages.begin(); iter < stages.end(); iter++) {
            if (*iter == i) {
                ans[i]++;
            }
        }
    }
    int len = stageSize;
    for (int i = 1; i < N + 1; i++) {
        if (len == 0) {
            failRate.push_back(pair<int, float>(i, 0));
            continue;
        }
        failRate.push_back(pair<int, float>(i, 1.0 * ans[i] / len));
        len -= ans[i];
    }
    sort(failRate.begin(), failRate.end(), cmp);
    for (auto pair : failRate) {
        answer.push_back(pair.first);
    }
    return answer;
}

int main() {
    solution(6, { 1, 2, 2, 3, 3, 1, 1, 4 });
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> jump;

int countReachableStones(int start) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int count = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        count++;

        int left = cur - jump[cur - 1];
        int right = cur + jump[cur - 1];

        if (left >= 1 && !visited[left]) {
            q.push(left);
            visited[left] = true;
        }

        if (right <= n && !visited[right]) {
            q.push(right);
            visited[right] = true;
        }
    }

    return count;
}

int main() {
    cin >> n;
    jump.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> jump[i];
    }

    int start;
    cin >> start;

    cout << countReachableStones(start) << endl;

    return 0;
}

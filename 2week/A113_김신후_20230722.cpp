#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj_list, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj_list[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj_list(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int connected_components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            bfs(i, adj_list, visited);
            connected_components++;
        }
    }

    cout << connected_components << endl;
    return 0;
}

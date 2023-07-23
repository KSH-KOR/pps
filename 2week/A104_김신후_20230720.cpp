#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> costs(N);
    int total = 0;

    for (int i = 0; i < N; i++) {
        cin >> costs[i];
        total += costs[i];
    }

    int minCost = total;
    int currentCost = 0;

    for (int i = 0; i < N; i++) {
        currentCost += costs[i];
        int nextCost = total - currentCost + costs[i];
        minCost = min(minCost, min(currentCost, nextCost));
    }

    cout << minCost << endl;
    return 0;
}

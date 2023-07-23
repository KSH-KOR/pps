#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> packages;
    vector<int> singles;

    for (int i = 0; i < M; i++) {
        int packagePrice, singlePrice;
        cin >> packagePrice >> singlePrice;

        packages.push_back({packagePrice, 6});
        singles.push_back(singlePrice);
    }

    sort(packages.begin(), packages.end());
    sort(singles.begin(), singles.end());

    int minPrice = min(packages[0].first, singles[0] * 6); 
    int numPackages = N / 6; 
    int remainingStrings = N % 6; 

    int totalPrice = numPackages * minPrice;
    if (remainingStrings > 0) {
        totalPrice = min(totalPrice + packages[0].first, totalPrice + singles[0] * remainingStrings);
    }

    cout << totalPrice << endl;
    return 0;
}

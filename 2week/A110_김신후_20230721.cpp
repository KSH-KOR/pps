#include <iostream>
#include <vector>
using namespace std;

int main() {
    int money;
    cin >> money;

    vector<int> coins = {500, 100, 50, 10, 5, 1};
    vector<int> dp(money + 1, money);
    dp[0] = 0; // 0원을 거슬러 줄 때의 잔돈 개수는 0

    for (int i = 1; i <= money; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << dp[money] << endl;
    return 0;
}

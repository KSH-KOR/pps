/*
앨리스와 밥의 총 사탕 개수를 계산한다.
앨리스와 밥 사이의 총 사탕 개수 차이를 계산한다.
앨리스의 사탕 상자를 반복하면서, 각 상자와 교환할 밥의 사탕 개수를 계산한다. 
    이 때, 교환 후 두 사람의 사탕 개수가 같아야 하므로 밥의 사탕 개수는 "앨리스의 사탕 개수 + (전체 차이 / 2)"가 되어야 한다.
밥의 사탕 상자에서 계산된 사탕 개수를 가진 상자가 존재하는지 확인한다.
존재한다면 앨리스의 사탕 상자와 밥의 사탕 상자를 교환해야 하는 사탕 개수로 반환한다.
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int totalAlice = 0, totalBob = 0;
        for (int candies : aliceSizes) {
            totalAlice += candies;
        }
        for (int candies : bobSizes) {
            totalBob += candies;
        }

        int targetDifference = (totalBob - totalAlice) / 2;
        unordered_set<int> bobCandies;
        for (int candies : bobSizes) {
            bobCandies.insert(candies);
        }

        for (int aliceCandies : aliceSizes) {
            int desiredBobCandies = aliceCandies + targetDifference;
            if (bobCandies.count(desiredBobCandies)) {
                return {aliceCandies, desiredBobCandies};
            }
        }

        return {};
    }
};

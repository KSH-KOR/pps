#include <limits>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0, sIndex = 0;

        for (int greedFactor : g) {
            while (sIndex < s.size() && s[sIndex] < greedFactor) {
                sIndex++;
            }
            if (sIndex >= s.size()) {
                break;
            }
            count++;
            sIndex++;
        }

        return count;
    }
};

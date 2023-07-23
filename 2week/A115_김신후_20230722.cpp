class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> charCounts;

        for (char c : text) {
            charCounts[c]++;
        }

        int minInstance = INT_MAX;
        string balloon = "balloon";
        for (char c : balloon) {
            if (c == 'l' || c == 'o') {
                minInstance = min(minInstance, charCounts[c] / 2);
            } else {
                minInstance = min(minInstance, charCounts[c]);
            }
        }

        return minInstance;
    }
};

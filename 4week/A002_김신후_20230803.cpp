// 불필요한 변수를 제거하고, 반복문의 범위를 최소화하여 코드를 더 간결하고 빠르게 만들었다.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int currRow = 0; currRow < numRows; currRow++) {
            result[currRow].resize(currRow + 1);
            result[currRow][0] = 1;
            result[currRow][currRow] = 1;
            for (int elementIndex = 1; elementIndex < currRow; elementIndex++) {
                result[currRow][elementIndex] = result[currRow - 1][elementIndex - 1] + result[currRow - 1][elementIndex];
            }
        }
        return result;
    }
};


/*

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int length = 0;
        vector<int> prevRow;
        for (int currRow = 0; currRow < numRows; currRow++) {
            vector<int> row;
            for (int elementIndex = 0; elementIndex < currRow + 1; elementIndex++) {
                if (currRow == 0) {
                    row.push_back(1);
                    break;
                }
                if (elementIndex == 0 || elementIndex == currRow) {
                    row.push_back(1);
                    continue;
                }
                row.push_back(prevRow[elementIndex - 1] + prevRow[elementIndex]);
            }
            prevRow = row;
            result.push_back(row);
        }
        return result;
    }
};

*/
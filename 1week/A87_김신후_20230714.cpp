/*
1710. Maximum Units on a Truck
Easy
3.5K
198
Companies
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a.at(1) > b.at(1);
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int tn = 0;
        int count = 0;
        int n;
        int v;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for(auto x : boxTypes){
            n = x.at(0);
            v = x.at(1);
            int left = truckSize - count;
            if(left == 0) break;
            int min = left < n ? left : n;

            count += min;
            tn += min * v;
        }
        return tn;
    }
};
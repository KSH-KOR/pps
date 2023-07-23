class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        
        int totalDistance = 0;
        for (int d : distance) {
            totalDistance += d;
        }
        
        int clockwiseDistance = 0;
        int curStop = start;
        while (curStop != destination) {
            clockwiseDistance += distance[curStop];
            curStop = (curStop + 1) % n;
        }
        
        return min(clockwiseDistance, totalDistance - clockwiseDistance);
    }
};

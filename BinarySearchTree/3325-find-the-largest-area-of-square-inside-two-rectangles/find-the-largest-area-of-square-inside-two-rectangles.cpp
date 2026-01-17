class Solution {
public:
   typedef unsigned long long ll;
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        long long maxsquare = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1, x2, y1, y2;
                // TopLeft
                x2 = min(topRight[i][0], topRight[j][0]);
                y2 = min(topRight[i][1], topRight[j][1]);

                // BottomLeft
                x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                y1 = max(bottomLeft[i][1], bottomLeft[j][1]);

                int width = x2 - x1;
                int height = y2 - y1;

                long long val = min(width, height)<0?0:min(width,height);
                maxsquare = max(maxsquare, val * val);
            }
        }
        return maxsquare;
    }
};
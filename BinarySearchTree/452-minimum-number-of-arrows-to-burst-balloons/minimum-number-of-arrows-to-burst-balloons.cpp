class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
              int st = points[0][0];
        int end = points[0][1];
        int count = 0;
        for (int i = 1; i < points.size(); i++) {
            int first = points[i][0];
            int last = points[i][1];
            if (first > end) {
                count++;
                st = first;
                end = last;
            } else {
                st = max(st, first);
                end = min(end, last);
            }
        }
        count++;
        return count;
    }
};
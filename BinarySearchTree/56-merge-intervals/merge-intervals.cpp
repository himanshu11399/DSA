class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        int st = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;
        while (i < intervals.size()) {
            if (end >= intervals[i][0]) {
                st = min(st, intervals[i][0]);
                end = max(end, intervals[i][1]);
                i++;
            } else {
                ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
                i++;
            }
        }
        ans.push_back({st, end});
        return ans;
    }
};
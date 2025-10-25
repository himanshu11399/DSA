class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval,
                               vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        while (i < interval.size()) {
            if (interval[i][1] < newInterval[0]) {
                ans.push_back({interval[i][0], interval[i][1]});
                i++;
            } else if (interval[i][0] > newInterval[1]) {
                ans.push_back({newInterval[0], newInterval[1]});
                while(i<interval.size()){
                ans.push_back({interval[i][0], interval[i][1]});
                i++;
                }
                return ans;
            } else {
                newInterval[0] = min(newInterval[0], interval[i][0]);
                newInterval[1] = max(newInterval[1], interval[i][1]);
                i++;
            }
        }
        ans.push_back({newInterval[0], newInterval[1]});
        return ans;
    }
};
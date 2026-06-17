class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.empty()) {
            return {{newInterval[0], newInterval[1]}};
        }
        int i = 0;
        int st = newInterval[0];
        int en = newInterval[1];
        vector<vector<int>> ans;

        while (i < intervals.size()) {
            if (intervals[i][1] < st) {
                ans.push_back({intervals[i][0], intervals[i][1]});
                i++;
            } else if (intervals[i][0] > en) {
                ans.push_back({st, en});
                while (i < intervals.size()) {
                    ans.push_back({intervals[i][0], intervals[i][1]});
                    i++;
                }
                return ans;
            } else {
                st = min(st, intervals[i][0]);
                en = max(en, intervals[i][1]);
                i++;
            }
        }
        ans.push_back({st, en});

            return ans;
    }
};
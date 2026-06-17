class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end(),
           [](const vector<int>&a,const vector<int>&b){
            return a[0] < b[0];
           }
        );

         int st = intervals[0][0];
        int en = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
        int first = intervals[i][0];
        int last = intervals[i][1];
        if (en >= first) {
            if(en>=last){
                continue;
            }
            en = last;
        } else {
            ans.push_back({st, en});
            st = first;
            en = last;
        }
    }
    ans.push_back({st, en});
    return ans;
}
}
;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
         if(nums.empty()) return ans;
        long long start = nums[0];
        long long prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]!= prev+1) {
                // if (prev != INT_MIN) {
                    if (prev == start) {
                        ans.push_back(to_string(start));
                    } else {
                        ans.push_back(to_string(start) + "->" +
                                      to_string(prev));
                    }
                // }
                start = nums[i];
            }
            prev = nums[i];
        }
        if (prev == start) {
                        ans.push_back(to_string(start));
                    } else {
                        ans.push_back(to_string(start) + "->" +
                                      to_string(prev));
                    }
        return ans;
    }
};
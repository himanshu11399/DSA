class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int longest=0;
        for(int i=0;i<n;i++){
             if(longest<i) return false;
            longest=max(longest,nums[i]+i);
            if(longest>=n-1) return true;
        }return true;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int jumps=0;
        while(r<n-1){
            int longest=0;
            for(int i=l;i<=r;i++){
                longest=max(longest,nums[i]+i);
            }
            l=r+1;
            r=longest;
            jumps=jumps+1;
        }
        return jumps;
    }
};
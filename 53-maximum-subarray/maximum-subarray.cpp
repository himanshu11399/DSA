class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxelement=INT_MIN;
        for(int val:nums){
            curr+=val;
            maxelement=max(maxelement,curr);
            if(curr<0){
                curr=0;
            }
        }
   return maxelement;
    }
};
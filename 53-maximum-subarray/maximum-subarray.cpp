class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int curr=0;
       int maxsum=INT_MIN;
       for(int i=0;i<nums.size();i++){
        curr+=nums[i];
        maxsum=max(maxsum,curr);
        if(curr<0){
            curr=0;
        }
       } return maxsum;
    }
};
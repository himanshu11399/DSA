class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int currsum=0;
       int n=nums.size();

       int tsum=(n*(n+1))/2;

       for(int i=0;i<nums.size();i++){
           currsum+=nums[i];
       }

    return tsum-currsum;
    }
};
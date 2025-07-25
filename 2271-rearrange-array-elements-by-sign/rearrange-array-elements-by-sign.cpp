class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    
        vector<int>ans(nums.size(),0);
        int firstidx=0;
        int secondidx=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
             ans[firstidx]=nums[i];
             firstidx+=2;
            }else{
             ans[secondidx]=nums[i];
             secondidx+=2;
            }
        }

        return ans;
    }
};
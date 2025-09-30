class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
           int com=target-nums[i];
           if(mpp.find(com)!=mpp.end()){
            return {i,mpp[com]};
           }
           mpp[nums[i]]=i; 
        }
        return {0,0};
    }
};
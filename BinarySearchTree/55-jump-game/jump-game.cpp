class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n=nums.size();
      int lastend=0;
      for(int i=0;i<n;i++){
        if(lastend<i) return false;
        lastend=max(lastend,nums[i]+i);
        if(lastend>=n-1) return true;
      }
      return false;  
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        int longest=1;
        int prev=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1==prev){
                count++;
            }else if(nums[i]!=prev){
                count=1;
            }
            prev=nums[i];
            longest=max(longest,count);
        }
        return longest;
    }
};
class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            int quantity=n-mid;
            if(nums[mid]>=quantity){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return  n-left;
    }
};
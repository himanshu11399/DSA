class Solution {
public:

int maxele(vector<int>&nums){
    int ans=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>ans){
            ans=nums[i];
        }
    }
    return ans;
}

int checkdivide(vector<int>&nums,int ele){
    if(ele==0) return 0;
    long long msum=0;
    for(int i=0;i<nums.size();i++){
        long long sum=(nums[i]+ele-1)/ele;
        msum+=sum;
    }
    return msum;
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=maxele(nums);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(checkdivide(nums,mid)<=threshold){
              ans=mid;
              high=mid-1;
            }else{
             low=mid+1;
            }
        }
        return ans;
    }
};
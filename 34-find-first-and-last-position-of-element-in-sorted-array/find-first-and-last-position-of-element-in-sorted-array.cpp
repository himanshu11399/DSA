class Solution {
public:

int FirstPos(vector<int>&nums,int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }else if(nums[mid]>target){
          high=mid-1;
        }else{
           low=mid+1;
        }
    }
    return ans;
}

int LastPos(vector<int>&nums,int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
    while(low<=high){
    int mid=(low+high)/2;
    if(nums[mid]==target){
         ans=mid;
         low=mid+1;
    }else if(nums[mid]>target){
          high=mid-1;
        }else{
           low=mid+1;
        }
    }
    return ans;
}


    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int>ans;
      ans.push_back(FirstPos(nums,target));
      ans.push_back(LastPos(nums,target));
      return ans;  
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minele=INT_MAX;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
           
            if(nums[low]<=nums[mid]){
                minele=min(minele,nums[low]);
                low=mid+1;
            }else{
               minele=min(minele,nums[mid]);
               high=mid-1;
            }
            
        }return minele;
    }
};
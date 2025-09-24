class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            //First case 0
            if(nums[mid]==0){
                swap(nums[mid],nums[left]);
                mid++;
                left++;
            }else if(nums[mid]==1){  //Second case 1
                mid++;
            }else{  //Third case 2
                swap(nums[mid],nums[high]);
              
                high--;
            }
        }
    }
};
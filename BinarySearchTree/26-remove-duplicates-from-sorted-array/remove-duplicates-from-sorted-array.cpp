class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int prev=nums[0];
        for(int i=0;i<nums.size();i++){
           if(i==0 || nums[i]!=prev){
            nums[k]=nums[i];
            prev=nums[i];
            k++;
           }
        }
        return k;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int nextindex=0;

        //Move all zero to the front
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[nextindex++]=nums[i];
            }
        }

        for(int i=nextindex;nextindex<nums.size();nextindex++){
            nums[i++]=0;
        }
    }
};
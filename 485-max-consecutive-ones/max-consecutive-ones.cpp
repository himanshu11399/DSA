class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxno=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }else{
                count=0;
            }
            maxno=max(maxno,count);
        }

        // maxno=max(maxno,count);

        return maxno;

    }
};
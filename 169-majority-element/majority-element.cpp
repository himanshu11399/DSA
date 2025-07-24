class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        int limit=nums.size()/2;


        for(auto it:mpp){
            if(it.second>limit){
                return it.first;
            }
        }
        return -1;


    }
};
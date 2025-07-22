class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        vector<int>ans;
        
        for(auto i:nums){
            mpp[i]++;
        }

        for(auto it:mpp){
            if(it.second==1){
            ans.push_back(it.first);
            }
        }
        return ans;
    }
};
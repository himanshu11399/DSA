class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>st;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(!st.count(nums[i])){
                nums[k]=nums[i];
                st.insert(nums[i]);
                k++;
            }
        }
        return k;
    }
};
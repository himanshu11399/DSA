class Solution {
public:
set<vector<int>>ans;
void solve(int i,vector<int>&nums,vector<int>&curr,int k){
    if(i==nums.size() || k<0){
        return;
    }
    if(k==0){
        ans.insert(curr);
        return;
    }
    
    curr.push_back(nums[i]);
    solve(i+1,nums,curr,k-nums[i]);//Include the i single time;
    solve(i,nums,curr,k-nums[i]);  //Include i multiple timesz
    curr.pop_back();
    solve(i+1,nums,curr,k);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>arr;
       solve(0,candidates,arr,target);
       
       vector<vector<int>>res;
       for(auto it:ans){
        res.push_back(it);
       }
       return res; 
    }
};
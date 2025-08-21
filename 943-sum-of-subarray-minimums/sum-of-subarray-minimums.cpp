class Solution {
public:
vector<int>NSL(vector<int>nums,int n){
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
     while(!st.empty() && nums[i]<=nums[st.top()]){
        st.pop();
     }
     if(!st.empty()){
        ans[i]=st.top();
     }
     st.push(i);
    }return ans;
}
vector<int>NSR(vector<int>nums,int n){
    stack<int>st;
    vector<int>ans(n,n);
    for(int i=n-1;i>=0;i--){
     while(!st.empty() && nums[i]<nums[st.top()]){
        st.pop();
     }
     if(!st.empty()){
        ans[i]=st.top();
     }
     st.push(i);
    }return ans;
}
    int sumSubarrayMins(vector<int>& nums) {
      long long ans=0;
      int n=nums.size();
      int m=1e9+7;
      vector<int>nsl=NSL(nums,n);
      vector<int>nsr=NSR(nums,n);
      
      for(int i=0;i<n;i++){
        long long left=i-nsl[i];
        long long right=nsr[i]-i;
        long long ways=left*right;
        long long sum=ways*nums[i];
        ans=(ans+sum)%m;
      }
      return ans;
    }
};
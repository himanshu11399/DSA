class Solution {
public:
    vector<int>NLL(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>NLR(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>NSL(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>NSR(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();

        vector<int>left_min=NLL(nums);
        vector<int>right_min=NLR(nums);
        vector<int>left_max=NSL(nums);
        vector<int>right_max=NSR(nums);

        long long lowest=0,highest=0;

        for(int i=0;i<n;i++){
            long long leftcount=i-left_min[i];
            long long rightcount=right_min[i]-i;
            lowest+=1LL*nums[i]*leftcount*rightcount;
        }
        for(int i=0;i<n;i++){
            long long leftcount=i-left_max[i];
            long long rightcount=right_max[i]-i;
            highest+=1LL*nums[i]*leftcount*rightcount;
        }

        return highest-lowest;
    }
};
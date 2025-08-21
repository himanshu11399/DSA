class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
       stack<int>st;
       for(int i=0;i<nums.size();i++){
        bool iscollide=false;
        while(!st.empty() && nums[i]<0 && st.top()>0){
            int sum=nums[i]+st.top();
            if(sum>0){
                iscollide=true;
                break;
            }else if(sum<0){
                st.pop();
            }else{
                st.pop();
                iscollide=true;
                break;
            }
        }
        if(!iscollide){
            st.push(nums[i]);
        }
       }
       vector<int>ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
        
       }
       reverse(ans.begin(),ans.end());
       return ans; 
    }
};
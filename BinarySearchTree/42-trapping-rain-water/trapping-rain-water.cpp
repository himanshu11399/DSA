class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);

        // Fill leftmax
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < left) {
                leftmax[i] = left;
            }
            left = max(left, nums[i]);
        }

        int right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < right) {
                rightmax[i] = right;
            }
            right = max(right, nums[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int water=min(leftmax[i],rightmax[i]);
            if(water>0){
                water-=nums[i];
            }
            ans+=water;
        }
        return ans;
    }
};
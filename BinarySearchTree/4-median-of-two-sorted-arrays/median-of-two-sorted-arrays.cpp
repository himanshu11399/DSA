class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                ans.push_back(nums2[j]);
                j++;
            } else {
                ans.push_back(nums1[i]);
                i++;
            }
        }
        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = merge(nums1, nums2);
        int n = ans.size();
        double res = 0.000;
        if (n % 2 == 0) {
            res = (ans[n / 2] + ans[(n / 2) - 1]) / 2.0;
        } else {
            res = ans[n / 2];
        }
        return res;
    }
};
class Solution {
public:
    // Merge Step
    vector<int> merge(vector<int> v1, vector<int> v2) {
        int i = 0, j = 0;
        vector<int> ans;

        while (i < v1.size() && j < v2.size()) {
            if (v1[i] <= v2[j]) {
                ans.push_back(v1[i]);
                i++;
            } else {
                ans.push_back(v2[j]);
                j++;
            }
        }

        while (i < v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }
        while (j < v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }

    vector<int> sortArray(vector<int> nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums;
        }

        int mid = n / 2;

        vector<int> list1 =
            sortArray(vector<int>(nums.begin(), nums.begin() + mid));
        vector<int> list2 =
            sortArray(vector<int>(nums.begin() + mid, nums.end()));

        return merge(list1, list2);
    }
};
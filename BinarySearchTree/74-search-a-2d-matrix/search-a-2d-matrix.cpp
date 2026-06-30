class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int low = 0;
        int high = (r * c) - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int val=matrix[mid / c][mid % c];
            if (val == target) {
                return true;
            } else if (target > val) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
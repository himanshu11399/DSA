class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        // For left
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = max(candy[i], candy[i - 1] + 1);
            }
        }
        // For Right
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int maxcandy = 0;
        for (int i = 0; i < n; i++) {
            maxcandy += candy[i];
        }
        return maxcandy;
    }
};
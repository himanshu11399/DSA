class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int mHBars = 1;
        int mVBars = 1;

        int currConsecutiveHbars = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                currConsecutiveHbars++;
            } else {
                currConsecutiveHbars = 1;
            }
            mHBars = max(mHBars, currConsecutiveHbars);
        }

        int currConsecutiveVbars = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                currConsecutiveVbars++;
            } else {
                currConsecutiveVbars = 1;
            }
            mVBars = max(mVBars, currConsecutiveVbars);
        }

        int ans = min(mHBars+1, mVBars+1);
        return ans * ans;
    }
};
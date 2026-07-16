class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int minval = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long s = 1LL*mid * mid;
            if (s == x) {
                return mid;
            } else if (s < x) {
                minval = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return minval;
    }
};
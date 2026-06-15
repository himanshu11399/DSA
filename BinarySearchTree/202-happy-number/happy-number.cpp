class Solution {
public:
    unordered_set<int> st;
    bool isHappy(int n) {
        if (n == 1)
            return true;
        if (n < 0 || st.count(n))
            return false;
        st.insert(n);
        int sum = 0;
        while (n != 0) {
            int val = n % 10;
            sum += val * val;
            n = n / 10;
        }

        return isHappy(sum);
    }
};
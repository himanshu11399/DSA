class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 0;
        digits[n] = digits[n] + 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int val = digits[i] + carry;
            carry = 0;
            if (val >= 10) {
                digits[i] = val % 10;
                carry = val / 10;
            }else{
            digits[i] = val;
            }
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
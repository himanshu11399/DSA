class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                a++;
            } else if (nums[i] == 1) {
                b++;
            } else {
                c++;
            }
        }
        int i = 0;
        while (a != 0) {
            nums[i] = 0;
            a--;
            i++;
        }
        while (b != 0) {
            nums[i] = 1;
            b--;
            i++;
        }
        while (c != 0) {
            nums[i] = 2;
            c--;
            i++;
        }
    }
};
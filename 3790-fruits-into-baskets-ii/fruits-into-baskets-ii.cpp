class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int ans = 0;
        vector<int> freq(baskets.size(), 0);

        for (int i = 0; i < fruits.size(); i++) {
            bool placed = false;
            for (int j = 0; j < baskets.size(); j++) {

                if (fruits[i] <= baskets[j] && freq[j] == 0) {
                    freq[j] = 1;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                ans++;
            }
        }
        return ans;
    }
};
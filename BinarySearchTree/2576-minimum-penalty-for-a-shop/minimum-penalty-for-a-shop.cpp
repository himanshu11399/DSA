class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;

        // Initial penalty if closed all day
        for (char c : customers)
            if (c == 'Y') penalty++;

        int minPenalty = penalty, bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') penalty--;
            else penalty++;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};

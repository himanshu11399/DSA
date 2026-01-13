class Solution {
public:
    bool check(vector<vector<int>>& squares, double midy, double total) {
        double bottomarea = 0;

        for (auto& square : squares) {
            double miny = square[1];
            double l = square[2];
            double maxy=miny+l;

            if(midy>=maxy){
                bottomarea+=l*l;
            }else if(midy>miny){
                bottomarea+=l*(midy-miny);
            }

        }
        return bottomarea>=total/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0.00000;

        for (auto& square : squares) {
            double x = square[0];
            double y = square[1];
            double l = square[2];
            total += l * l;

            low = min(low, y);
            high = max(high, y + l);
        }

        double result = 0.00000;

        while (high - low > 1e-5) {
            double midy = low + (high - low) / 2;

            result = midy;

            if (check(squares, midy, total) == true) {
                high = midy;
            } else {
                low = midy;
            }
        }

        return result;
    }
};
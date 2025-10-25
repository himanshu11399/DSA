class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),
             boxTypes.end(),[](vector<int> & a, vector<int> & b){
                return a[1] >b[1];
    });

        int totalUnits = 0;

        for (auto it : boxTypes) {
            int box = it[0];
            int unit = it[1];

            int size = min(box, truckSize);
            totalUnits += size * unit;
            truckSize -= size;
        }
        return totalUnits;
    }
};
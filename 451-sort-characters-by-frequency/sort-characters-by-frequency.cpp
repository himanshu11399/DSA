class Solution {
public:
    typedef pair<char, int> p;
    string frequencySort(string s) {
        vector<p> vec(123);
        for (char& ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq + 1};
        }

        auto lambda = [&](p& p1, p& p2) { return p1.second > p2.second;};

        sort(vec.begin(), vec.end(),lambda);

        string ans;

        for (int i = 0; i <= 122; i++) {
            char ch = vec[i].first;
            int freq = vec[i].second;

            string temp = string(freq,ch);
            ans += temp;
        }

        return ans;
    }
};
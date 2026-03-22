class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(end) == st.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({start, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == end)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.find(temp) != st.end()) {
                        q.push({temp, steps + 1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
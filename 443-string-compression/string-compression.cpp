class Solution {
public:
    int compress(vector<char>& chars) {
        char ch = chars[0];
        int len = 1;
        int idx = 0;

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == ch) {
                len++;
            } else {
                chars[idx] = ch;
                idx++;

                if (len > 1) {
                    string count = to_string(len);
                    for (char t : count) {
                        chars[idx] = t;
                        idx++;
                    }
                }
                ch = chars[i];
                len = 1;
            }
        }

        
            chars[idx] = ch;
            idx++;

            if (len > 1) {
                string count = to_string(len);
                for (char t : count) {
                    chars[idx] = t;
                    idx++;
                }
            }
        
        return idx;
    }
};
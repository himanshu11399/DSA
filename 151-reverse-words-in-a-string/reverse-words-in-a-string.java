class Solution {
    public void rev(char[] s, int start, int end) {
        if (start >= end)
            return;
        while (start < end) {
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            start++;
            end--;
        }
    }

    public String reverseWords(String s) {
        int n = s.length();

        char[] arr = s.toCharArray();

        rev(arr, 0, n - 1);

        int start = 0;
        String ans = "";

        for (int i = 0; i < n; i++) {
            if (arr[i] == ' ') {
                String tmp = new String(arr, start, i - start);
                if (tmp.length() > 0) {
                    char[] tmpArr = tmp.toCharArray();

                    rev(tmpArr, 0, tmpArr.length - 1);

                    ans = ans + " " + new String(tmpArr);
                }
                start = i + 1;
            }
        }

        String tmp = new String(arr, start, n - start);
        if (tmp.length() > 0) {
            char[] tmpArr = tmp.toCharArray();
            rev(tmpArr, 0, tmpArr.length - 1);

            ans = ans + " " + new String(tmpArr);
        }

        return ans.substring(1);
    }
}
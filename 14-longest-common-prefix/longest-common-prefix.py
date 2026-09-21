class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans = strs[0]
        for i in range(1, len(strs)):
            ch = ""
            p = 0
            q = 0
            word = strs[i]
            while p < len(ans) and q < len(word):
                if ans[p] == word[q]:
                    ch += ans[p]
                    p+=1
                    q+=1
                else:
                    break
            ans = ch
        return ans

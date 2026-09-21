class Solution:
    def firstUniqChar(self, s: str) -> int:
        mpp = {}
        for x in s:
           mpp[x]=mpp.get(x,0)+1
        for i in range(len(s)):
            if mpp[s[i]]==1:
                return i
        return -1        

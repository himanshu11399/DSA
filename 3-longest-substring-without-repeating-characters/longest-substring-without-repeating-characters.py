class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start=0
        st=set()
        maxans=0
        for x in s:
            maxans=max(maxans,len(st))
            while x in st:
                st.remove(s[start])
                start+=1
            st.add(x)
        maxans=max(maxans,len(st))
        return maxans       
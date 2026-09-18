class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        st=set()
        for x in nums:
            if x in st:
                return x
            st.add(x)

        return -1        
        
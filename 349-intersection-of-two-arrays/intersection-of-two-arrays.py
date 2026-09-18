class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        st=set()
        for x in nums1:
            st.add(x)
        ans=[]
        for x in nums2:
            if x in st:
                st.remove(x)
                ans.append(x)

        return ans        
        
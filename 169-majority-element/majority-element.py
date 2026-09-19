class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        mpp={}
        for x in nums:
            mpp[x]=mpp.get(x,0)+1
            if mpp[x]>len(nums)/2:
                return x
        return -1        
        
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        n=len(nums)
        maxans=float('-inf')
        maxele=0
        for x in nums:
            maxele+=x
            maxans=max(maxans,maxele)
            if maxele<0:
                maxele=0       
        return maxans              
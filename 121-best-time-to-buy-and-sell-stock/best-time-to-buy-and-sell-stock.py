class Solution(object):
    def maxProfit(self, nums):
        """
        :type prices: List[int]
        :rtype: int
        """
        ans=0
        i=0
        for j in range(1,len(nums)):
            if nums[i]>nums[j]:
                i=j
            else:
                ans=max(ans,nums[j]-nums[i])
        return ans            
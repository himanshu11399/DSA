class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        total=0
        for x in nums:
            total+=x
        n=len(nums)
        return  int(n*(n+1)/2-total)   
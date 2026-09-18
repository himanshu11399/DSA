class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp={}
        for x in range(0,len(nums)):
            rem=target-nums[x]
            if rem in mp:
                return [x,mp[rem]]
            mp[nums[x]]=x
        return [-1,-1]        

        
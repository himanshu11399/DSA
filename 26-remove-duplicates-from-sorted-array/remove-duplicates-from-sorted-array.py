class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        idx=0
        for i,x in enumerate(nums):
            if nums[idx]!=x:
                idx+=1
                nums[idx]=x
        return idx+1
                

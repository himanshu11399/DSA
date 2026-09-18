class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx=0
        for i,x in enumerate(nums):
            if x!=0:
                nums[idx],nums[i]=nums[i],nums[idx]
                idx+=1
        return idx        
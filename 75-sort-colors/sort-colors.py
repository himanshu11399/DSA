class Solution:
    def sortColors(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx=0
        for i in range(len(nums)):
            if nums[i]==0:
                nums[idx],nums[i]=nums[i],nums[idx]
                idx+=1

        for i in range(len(nums)):
            if nums[i]==1:
               nums[idx],nums[i]=nums[i],nums[idx]
               idx+=1
               
        
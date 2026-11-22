class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        i=0
        for j in range(1,len(nums)):
            if nums[i]!=nums[j]:
                i+=1
                temp=nums[i]
                nums[i]=nums[j]
                nums[j]=temp
        return i+1   
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i=0
        for j in range(0,len(nums)):
            if nums[j]!=val:
                temp=nums[i]
                nums[i]=nums[j]
                nums[j]=temp
                i+=1
        return i     
        
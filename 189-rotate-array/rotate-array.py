class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        temp=[0]*len(nums)
        for i in range(0,len(nums)):
            temp[(i+k)%len(nums)]=nums[i]    
        for i in range(0,len(nums)):
            nums[i]=temp[i]    
        
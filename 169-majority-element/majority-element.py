class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mpp={}
        for i in nums:
            mpp[i]=mpp.get(i,0)+1
            if mpp[i]>len(nums)/2:
                return i
        return -1        
        
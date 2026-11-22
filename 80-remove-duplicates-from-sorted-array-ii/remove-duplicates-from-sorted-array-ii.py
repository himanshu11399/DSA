class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        cnt=0
        for j in range(0,len(nums)):
            if nums[i]==nums[j]:
                cnt+=1
                if cnt==2:
                    i+=1
                    nums[i]=nums[j]
            else:
                cnt=1
                i+=1
                nums[i]=nums[j]
        return i+1                            
        
class Solution:
    def reverseWords(self, s: str) -> str:
        nums=list(s)
        left=0
        right=len(nums)-1
        while left<=right:
                nums[left],nums[right]=nums[right],nums[left]
                left+=1
                right-=1 
        nums.append(' ')

        ans=""
        x=0
        while x<len(nums):
           while x<len(nums) and nums[x]==' ':
                x+=1

           temp=""
           while x<len(nums) and nums[x]!=' ' :   
                temp+=nums[x]
                x+=1

           temp=temp[::-1]
           if temp:
              ans+=temp+' '     

        return ans.strip()           
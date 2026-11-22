class Solution(object):
    def solve(self,nums,idx,buy,dp):
        if idx>=len(nums):
            return 0
        if dp[idx][buy]!=-1:
            return dp[idx][buy]    
        prices=0
        if(buy==1):
            take=-nums[idx]+self.solve(nums,idx+1,0,dp)
            notake=self.solve(nums,idx+1,1,dp)
            prices=max(take,notake)
        else:
            take=nums[idx]+self.solve(nums,idx+1,1,dp)
            notake=self.solve(nums,idx+1,0,dp)
            prices=max(take,notake)
        dp[idx][buy]=prices 
        return prices   
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp=[[-1]*2 for _ in range(0,len(prices))]
        ans=self.solve(prices,0,1,dp)
        return ans

        
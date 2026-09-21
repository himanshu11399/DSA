class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mpp={}
        for x in s:
            mpp[x]=mpp.get(x,0)+1
        for x in t:
            if x in mpp and mpp[x]>0:
                mpp[x]-=1
            else:
                return False
        for v in mpp:
            if mpp[v]>0:
                return False      
        return True            

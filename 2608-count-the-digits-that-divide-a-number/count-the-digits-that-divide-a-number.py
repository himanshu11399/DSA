class Solution(object):
    def countDigits(self, num):
        """
        :type num: int
        :rtype: int
        """

        li=[]
        v=num
        while v!=0:
            li.append(v%10)
            v=v//10

        cnt=0
        for val in li:
            if num%val==0:
                cnt+=1
        return cnt        



        
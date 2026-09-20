class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        vowels=set("aeiou")
        cnt=0
        for i in range(len(word)):
            tmp=set()
            for j in range(i,len(word)):
                if word[j] not in vowels:
                    break
                tmp.add(word[j])
                if len(tmp)==5:
                    cnt+=1
        return cnt                
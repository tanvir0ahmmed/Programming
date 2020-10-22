class Solution(object):
    def isAnagram(self, s, t):
        s = sorted (s)
        t = sorted(t)
        if s != t:
            return False
        else: return True

ob = Solution()
#s = "anagram"
#t = "nagaram"
s = "aaabbb"
t = "ab"
print(ob.isAnagram(s,t))
        
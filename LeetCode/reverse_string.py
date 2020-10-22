class Solution(object):
    def reverseString(self, s):
        n = len(s)
        for i in range(n//2):
            t = s[n-(i+1)]
            s[n-(i+1)] = s[i]
            s[i] = t
        return s

ob = Solution()
#s = ['h','e','l','l','o']
s = ["H","a","n","n","a","h"]
print(ob.reverseString(s))
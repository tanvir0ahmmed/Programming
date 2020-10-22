class Solution(object):
    def firstUniqChar(self, s):
        dic = {}
        n = len(s)
        for i in range(n):
            dic[s[i]] = 0
        for i in range(n):
            dic[s[i]] += 1
        for i in range(n):
           if dic[s[i]] == 1:
               return i
        return -1
    def firstUniqChar1(self, s):
        n = len(s)
        c = 0
        for i in range(n):
            for j in range(n):
                if s[i] != s[j]:
                    c += 1
            if c == n-1:
                return i
            c = 0
        return -1

ob = Solution()
s = "hhooell"
print(ob.firstUniqChar1(s))
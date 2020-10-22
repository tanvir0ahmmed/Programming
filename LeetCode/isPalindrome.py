class Solution(object):
    def isPalindrome(self, s):
        st = ""
        for i in range(len(s)):
            if (s[i] >='a' and s[i]<='z') or (s[i] >='A' and s[i]<='Z') or ((s[i] >='0' and s[i]<='9')):
                st += s[i]
        n = len(st)
        print(st)
        a = ""
        for i in range(n-1,-1,-1):
            a += st[i]
        print(a)
        if a.lower() == st.lower():
            return True
        return False

ob = Solution()
s = "0P"
print(ob.isPalindrome(s))
        
class Solution(object):
    def reverse(self, x):
        digit = 0
        f = 0
        a = -2**31
        b = (2**31)-1
        if x < 0:
            x = x * -1
            f = 1
        while(x > 0):
            r = x % 10
            x = x // 10
            digit = (digit * 10) + r
        if f == 1:
            digit = digit * -1
        print(digit)
        if digit > b or digit < a:
            return 0
        else:
            return digit
ob = Solution()
x = -2147483648
print(ob.reverse(x))
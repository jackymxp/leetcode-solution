class Solution:
    def numDecodings(self, s: str) -> int:
        dp = {}
        return self.dfs(s, 0, len(s)-1, dp)

    def dfs(self, s, left, right, dp):
        
        if left in dp.keys():
            return dp[left]

        if len(s) == 0:
            return 1

        if s == "0":
            return 0

        num1, num2 = int(s[0:1]), int(s[0:2])

        s1, s2= s[1:], s[2:]

        t1, t2 = 0, 0

        if num1 >= 1 and num1 <= 9:
            t1 = self.dfs(s1, left+1, right, dp)
      
        if num2 <= 26 and num2 >= 10:
            t2 = self.dfs(s2, left+2, right, dp)

        dp[left] = t1+t2

        return t1+t2
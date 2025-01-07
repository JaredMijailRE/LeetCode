class Solution:
    def evaluate(self, right: str, left: str) -> int:
        cero = right.count('0')
        one = left.count('1')
        return cero + one

    def maxScore(self, s: str) -> int:
        max = 0

        for n in range(1, len(s)):
            result = self.evaluate(s[:n], s[n:])
            if result > max:
                max = result

        return max
    
    
fuck = Solution()
print(fuck.maxScore("00"))
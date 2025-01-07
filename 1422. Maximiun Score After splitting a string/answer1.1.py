class Solution:

    def maxScore(self, s: str) -> int:
        max = 0
        
        for n in range(1, len(s)):
            result = s[:n].count('0') + s[n:].count('1')
            if result > max:
                max = result

        return max
    
# kind of the same but i guess it uses less memory using less variables and doesnt have to 
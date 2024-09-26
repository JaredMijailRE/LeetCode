class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        par_map = {')': '(', ']': '[', '}': '{'}
        for char in s:
            if char in par_map:  
                top_element = stack.pop() if stack else '#'
                if par_map[char] != top_element:
                    return False
            else:
                stack.append(char)
        return not stack

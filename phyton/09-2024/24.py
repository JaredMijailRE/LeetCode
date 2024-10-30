# https://leetcode.com/problems/longest-common-prefix/
# Version 1
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        min = len(strs[0])
        for palabra in strs:
            if (len(palabra) < min):
                min = len(palabra)

        for char in range(min):
            base = strs[0][char]
            for palabra in strs:
                if(palabra[char] != base):
                    return result
            result += strs[0][char]
        return result
    
# version 2
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        minM = 400
        for palabra in strs:
            minM = min(minM, len(palabra))
        for char in range(minM):
            for palabra in strs[1:]:
                if(palabra[char] != strs[0][char]):
                    return result
            result += strs[0][char]
        return result
    
# unclear if min function is more efficient
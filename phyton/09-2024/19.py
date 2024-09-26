class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev_s = s[::-1]
        new_s = s + "#" + rev_s
        n = len(new_s)
        kmp_table = [0] * n
        for i in range(1, n):
            j = kmp_table[i - 1]
            while j > 0 and new_s[i] != new_s[j]:
                j = kmp_table[j - 1]
            if new_s[i] == new_s[j]:
                j += 1
            kmp_table[i] = j
        longest_palindromic_prefix_length = kmp_table[-1]
        return rev_s[:len(s) - longest_palindromic_prefix_length] + s
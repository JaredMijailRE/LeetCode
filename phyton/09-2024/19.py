def shortestPalindrome(s: str) -> str:
        size = len(s)
        s = list(s)
        for n in range(1, (size // 2) + 1):
            if s[n - 1] != s[size - n]:
                s.insert(n - 1, s[size - n])
            print(''.join(s))
        return ''.join(s)
    
shortestPalindrome("abcd")
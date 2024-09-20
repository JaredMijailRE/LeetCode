class Solution {
public:
    string shortestPalindrome(string s) {
        int size = s.size();
        for(int n=1; n-1 <= size/2; n++){
            if((s[n-1] != s[size-n])){
                s.insert(n-1, 1, s[s.size()-n]);
            }
        }
        return s;
    };
};

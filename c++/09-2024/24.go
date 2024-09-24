// https://leetcode.com/problems/longest-common-prefix/
// version 1
func longestCommonPrefix(strs []string) string {
    min := len(strs[0])
    for _, palabra := range strs{
        if(len(palabra) < min){
            min = len(palabra) 
        }
    }
    result := ""
    for n := 0; n <= min-1 ; n++{
        base := strs[0][n]
        for _, palabra := range strs{
            if (base != palabra[n]){
                return result 
            }
        }
        result += string(strs[0][n])
    }
    return result
}
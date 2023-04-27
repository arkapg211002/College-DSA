//Longest palindromic substring
class Solution {        
    public String longestPalindrome(String str) {
        int n = str.length();
        boolean table[][] = new boolean[n][n];
        int maxLength = 1;
        for (int i = 0; i < n; ++i)
            table[i][i] = true;
        int start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (str.charAt(i) == str.charAt(i + 1)) {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (table[i + 1][j - 1]
                    && str.charAt(i) == str.charAt(j)) {
                    table[i][j] = true;
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        //System.out.print("Longest palindrome substring is; ");
        // printSubStr(str, start,start + maxLength - 1);
        int low=start;
        int high=start + maxLength - 1;
        return str.substring(low, high + 1);
        // return maxLength;
    }
}

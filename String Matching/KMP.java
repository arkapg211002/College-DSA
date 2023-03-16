public class KnuthMorrisPrattAlgorithm {
    public static void search(String pattern, String text) {
        int m = pattern.length(); // length of pattern
        int n = text.length(); // length of text
        
        int[] prefix = computePrefix(pattern); // compute prefix array for pattern
        
        int j = 0; // index of current character in pattern
        
        for (int i = 0; i < n; i++) {
            while (j > 0 && text.charAt(i) != pattern.charAt(j)) {
                j = prefix[j-1]; // move to the next possible match
            }
            if (text.charAt(i) == pattern.charAt(j)) {
                j++; // match found, move to the next character in pattern
            }
            if (j == m) {
                System.out.println("Pattern found at index " + (i - m + 1));
                j = prefix[j-1]; // reset j to find next match
            }
        }
    }
    
    private static int[] computePrefix(String pattern) {
        int m = pattern.length();
        int[] prefix = new int[m];
        
        int j = 0; // index of current character in prefix array
        
        for (int i = 1; i < m; i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = prefix[j-1]; // move to the next possible match
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                j++; // match found, move to the next character in prefix array
            }
            prefix[i] = j;
        }
        
        return prefix;
    }
}

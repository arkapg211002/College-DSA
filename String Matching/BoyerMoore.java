public class BoyerMooreAlgorithm {
    public static void search(String pattern, String text) {
        int m = pattern.length(); // length of pattern
        int n = text.length(); // length of text
        
        int[] lastOccurrence = buildLastOccurrence(pattern); // build last occurrence table for pattern
        
        int i = m - 1; // index of last character in pattern
        int j = m - 1; // index of current character in pattern
        
        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                if (j == 0) {
                    System.out.println("Pattern found at index " + i);
                    i += m; // move to next possible match
                    j = m - 1; // reset j to match last character of pattern
                } else {
                    i--;
                    j--;
                }
            } else {
                int last = lastOccurrence[text.charAt(i)];
                i += m - Math.min(j, 1 + last);
                j = m - 1;
            }
        }
    }
    
    private static int[] buildLastOccurrence(String pattern) {
        int[] lastOccurrence = new int[256]; // assume ASCII character set
        
        for (int i = 0; i < 256; i++) {
            lastOccurrence[i] = -1; // set all values to -1
        }
        
        for (int i = 0; i < pattern.length(); i++) {
            lastOccurrence[pattern.charAt(i)] = i; // set last occurrence of each character in pattern
        }
        
        return lastOccurrence;
    }
}

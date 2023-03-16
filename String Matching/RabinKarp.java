public class RabinKarpAlgorithm {
    private static final int PRIME = 101; // prime number used for hashing
    private static final int BASE = 256; // number of possible characters in input string
    
    public static void search(String pattern, String text) {
        int m = pattern.length(); // length of pattern
        int n = text.length(); // length of text
        int patternHash = hash(pattern, m); // hash value of pattern
        int textHash = hash(text, m); // hash value of first m characters of text
        
        for (int i = 0; i <= n - m; i++) {
            if (patternHash == textHash && pattern.equals(text.substring(i, i + m))) {
                System.out.println("Pattern found at index " + i);
            }
            if (i < n - m) {
                textHash = rehash(text, i, i + m, textHash, m);
            }
        }
    }
    
    private static int hash(String str, int length) {
        int hash = 0;
        for (int i = 0; i < length; i++) {
            hash = (hash * BASE + str.charAt(i)) % PRIME;
        }
        return hash;
    }
    
    private static int rehash(String str, int oldIndex, int newIndex, int oldHash, int length) {
        int newHash = oldHash - str.charAt(oldIndex) * (int) Math.pow(BASE, length - 1);
        newHash = newHash * BASE + str.charAt(newIndex);
        newHash = newHash % PRIME;
        return newHash;
    }
}

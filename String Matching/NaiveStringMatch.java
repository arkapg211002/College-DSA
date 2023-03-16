public class NaiveStringMatching {
    public static void search(String pattern, String text) {
        int m = pattern.length();
        int n = text.length();

        // Slide the pattern over the text one by one
        for (int i = 0; i <= n - m; i++) {
            int j;

            // Check if the pattern matches the text at the current position
            for (j = 0; j < m; j++) {
                if (text.charAt(i + j) != pattern.charAt(j)) {
                    break;
                }
            }

            // If the pattern matches, print the index of the starting position
            if (j == m) {
                System.out.println("Pattern found at index " + i);
            }
        }
    }

    public static void main(String[] args) {
        String text = "AABAACAADAABAAABAA";
        String pattern = "AABA";

        search(pattern, text);
    }
}

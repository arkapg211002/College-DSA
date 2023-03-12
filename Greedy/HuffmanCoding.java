import java.util.PriorityQueue;
import java.util.Scanner;

public class HuffmanCoding {
    static class HuffmanNode implements Comparable<HuffmanNode> {
        char c;
        int freq;
        HuffmanNode left;
        HuffmanNode right;

        public HuffmanNode(char c, int freq) {
            this.c = c;
            this.freq = freq;
            left = null;
            right = null;
        }

        public int compareTo(HuffmanNode o) {
            return this.freq - o.freq;
        }
    }

    public static void printCode(HuffmanNode root, String code) {
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ": " + code);
            return;
        }
        printCode(root.left, code + "0");
        printCode(root.right, code + "1");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String input = sc.nextLine();
        int[] freq = new int[256];
        for (char c : input.toCharArray()) {
            freq[c]++;
        }

        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>();
        for (int i = 0; i < freq.length; i++) {
            if (freq[i] > 0) {
                pq.add(new HuffmanNode((char) i, freq[i]));
            }
        }

        while (pq.size() > 1) {
            HuffmanNode left = pq.poll();
            HuffmanNode right = pq.poll();
            HuffmanNode parent = new HuffmanNode('\0', left.freq + right.freq);
            parent.left = left;
            parent.right = right;
            pq.add(parent);
        }

        HuffmanNode root = pq.peek();
        printCode(root, "");
    }
}


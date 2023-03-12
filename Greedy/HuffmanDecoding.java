
import java.util.*;

public class HuffmanDecoder {
    
    private Node root;

    private static class Node {
        private final char character;
        private Node left;
        private Node right;

        private Node(char character) {
            this.character = character;
        }
    }

    public void buildHuffmanTree(String encodedText, Map<Character, String> codeTable) {
        root = new Node('\0');

        for (Map.Entry<Character, String> entry : codeTable.entrySet()) {
            char character = entry.getKey();
            String code = entry.getValue();

            Node currentNode = root;
            for (int i = 0; i < code.length(); i++) {
                char bit = code.charAt(i);
                if (bit == '0') {
                    if (currentNode.left == null) {
                        currentNode.left = new Node('\0');
                    }
                    currentNode = currentNode.left;
                } else {
                    if (currentNode.right == null) {
                        currentNode.right = new Node('\0');
                    }
                    currentNode = currentNode.right;
                }
            }
            currentNode.character = character;
        }
    }

    public String decode(String encodedText) {
        StringBuilder decodedText = new StringBuilder();
        Node currentNode = root;

        for (int i = 0; i < encodedText.length(); i++) {
            char bit = encodedText.charAt(i);
            if (bit == '0') {
                currentNode = currentNode.left;
            } else {
                currentNode = currentNode.right;
            }

            if (isLeaf(currentNode)) {
                decodedText.append(currentNode.character);
                currentNode = root;
            }
        }

        return decodedText.toString();
    }

    private boolean isLeaf(Node node) {
        return node != null && node.left == null && node.right == null;
    }
    
    public static void main(String[] args) {
        Map<Character, String> codeTable = new HashMap<>();
        codeTable.put('a', "10");
        codeTable.put('b', "011");
        codeTable.put('c', "00");
        codeTable.put('d', "11");

        String encodedText = "10011011001100";

        HuffmanDecoder decoder = new HuffmanDecoder();
        decoder.buildHuffmanTree(encodedText, codeTable);

        String decodedText = decoder.decode(encodedText);

        System.out.println("Encoded text: " + encodedText);
        System.out.println("Decoded text: " + decodedText);
    }
}

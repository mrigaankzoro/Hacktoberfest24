import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.Map;

class Node implements Comparable<Node> {
    char character;
    int frequency;
    Node left;
    Node right;

    Node(char character, int frequency) {
        this.character = character;
        this.frequency = frequency;
        left = null;
        right = null;
    }
    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.frequency, other.frequency);
    }
}

public class HuffmanCoding {

    private static Node buildHuffmanTree(Map<Character, Integer> frequencyMap) {
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            priorityQueue.add(new Node(entry.getKey(), entry.getValue()));
        }

        while (priorityQueue.size() > 1) {
            Node left = priorityQueue.poll();
            Node right = priorityQueue.poll();
            Node combined = new Node('\0', left.frequency + right.frequency);
            combined.left = left;
            combined.right = right;
            priorityQueue.add(combined);
        }

        return priorityQueue.poll();
    }

    private static void generateHuffmanCodes(Node root, String code, Map<Character, String> huffmanCodes) {
        if (root == null) return;

 
        if (root.left == null && root.right == null) {
            huffmanCodes.put(root.character, code);
            return;
        }

        generateHuffmanCodes(root.left, code + "0", huffmanCodes);
        generateHuffmanCodes(root.right, code + "1", huffmanCodes);
    }

    public static String encode(String text) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char character : text.toCharArray()) {
            frequencyMap.put(character, frequencyMap.getOrDefault(character, 0) + 1);
        }
        Node root = buildHuffmanTree(frequencyMap);

    
        Map<Character, String> huffmanCodes = new HashMap<>();
        generateHuffmanCodes(root, "", huffmanCodes);
      
        StringBuilder encodedText = new StringBuilder();
        for (char character : text.toCharArray()) {
            encodedText.append(huffmanCodes.get(character));
        }

        return encodedText.toString();
    }

    public static String decode(Node root, String encodedText) {
        StringBuilder decodedText = new StringBuilder();
        Node current = root;

        for (char bit : encodedText.toCharArray()) {
            current = (bit == '0') ? current.left : current.right;

            if (current.left == null && current.right == null) {
                decodedText.append(current.character);
                current = root;
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        String text = "huffman coding example";
        String encodedText = encode(text);
        System.out.println("Encoded Text: " + encodedText);
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char character : text.toCharArray()) {
            frequencyMap.put(character, frequencyMap.getOrDefault(character, 0) + 1);
        }
        Node root = buildHuffmanTree(frequencyMap);

        String decodedText = decode(root, encodedText);
        System.out.println("Decoded Text: " + decodedText);
    }
}

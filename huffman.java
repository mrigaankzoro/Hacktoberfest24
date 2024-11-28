import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

// A Huffman Tree node
class HuffmanNode {
    int frequency;
    char character;
    HuffmanNode left;
    HuffmanNode right;

    // Constructor for leaf nodes (which store characters)
    HuffmanNode(char character, int frequency) {
        this.character = character;
        this.frequency = frequency;
        this.left = null;
        this.right = null;
    }

    // Constructor for internal nodes (which store frequencies and pointers to children)
    HuffmanNode(int frequency) {
        this.frequency = frequency;
        this.left = null;
        this.right = null;
    }
}

public class HuffmanCoding {

    /**
     * Method to build the Huffman tree.
     * @param charFrequencies - A map with characters as keys and their frequencies as values.
     * @return Root of the Huffman tree.
     */
    private static HuffmanNode buildHuffmanTree(Map<Character, Integer> charFrequencies) {
        PriorityQueue<HuffmanNode> priorityQueue = new PriorityQueue<>((a, b) -> a.frequency - b.frequency);

        // Create leaf nodes for each character and add to the priority queue
        for (Map.Entry<Character, Integer> entry : charFrequencies.entrySet()) {
            priorityQueue.add(new HuffmanNode(entry.getKey(), entry.getValue()));
        }

        // Build the Huffman Tree by combining two smallest nodes until the tree is complete
        while (priorityQueue.size() > 1) {
            HuffmanNode left = priorityQueue.poll();
            HuffmanNode right = priorityQueue.poll();
            HuffmanNode parent = new HuffmanNode(left.frequency + right.frequency);
            parent.left = left;
            parent.right = right;
            priorityQueue.add(parent);
        }

        // The root node is the final node in the queue
        return priorityQueue.poll();
    }

    /**
     * Method to generate the Huffman Codes from the tree.
     * @param root - Root of the Huffman tree.
     * @param code - The current code as a string.
     * @param huffmanCode - A map to store character-to-code mapping.
     */
    private static void generateHuffmanCodes(HuffmanNode root, String code, Map<Character, String> huffmanCode) {
        if (root == null) {
            return;
        }

        // If it's a leaf node, assign the code
        if (root.left == null && root.right == null) {
            huffmanCode.put(root.character, code);
        }

        generateHuffmanCodes(root.left, code + '0', huffmanCode);
        generateHuffmanCodes(root.right, code + '1', huffmanCode);
    }

    /**
     * Method to compress the input string using Huffman Coding.
     * @param input - The input string to be compressed.
     * @return The compressed binary string and Huffman code mapping.
     */
    public static Map<Character, String> compress(String input) {
        // Calculate character frequencies
        Map<Character, Integer> charFrequencies = new HashMap<>();
        for (char c : input.toCharArray()) {
            charFrequencies.put(c, charFrequencies.getOrDefault(c, 0) + 1);
        }

        // Build the Huffman Tree
        HuffmanNode root = buildHuffmanTree(charFrequencies);

        // Generate Huffman Codes
        Map<Character, String> huffmanCode = new HashMap<>();
        generateHuffmanCodes(root, "", huffmanCode);

        // Print the generated Huffman Codes
        System.out.println("Character to Huffman Code mapping:");
        for (Map.Entry<Character, String> entry : huffmanCode.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Compress the input string
        StringBuilder compressedData = new StringBuilder();
        for (char c : input.toCharArray()) {
            compressedData.append(huffmanCode.get(c));
        }

        System.out.println("\nCompressed Data: " + compressedData.toString());
        return huffmanCode;
    }

    /**
     * Method to decompress the binary data using Huffman coding.
     * @param compressedData - The compressed binary string.
     * @param huffmanCode - The map of characters and their Huffman codes.
     * @return The decompressed string.
     */
    public static String decompress(String compressedData, Map<Character, String> huffmanCode) {
        // Inverse the Huffman code map to get code-to-character mapping
        Map<String, Character> inverseHuffmanCode = new HashMap<>();
        for (Map.Entry<Character, String> entry : huffmanCode.entrySet()) {
            inverseHuffmanCode.put(entry.getValue(), entry.getKey());
        }

        // Decompress the binary string
        StringBuilder decodedData = new StringBuilder();
        StringBuilder tempCode = new StringBuilder();
        for (char bit : compressedData.toCharArray()) {
            tempCode.append(bit);
            if (inverseHuffmanCode.containsKey(tempCode.toString())) {
                decodedData.append(inverseHuffmanCode.get(tempCode.toString()));
                tempCode.setLength(0); // Reset the temporary code
            }
        }

        return decodedData.toString();
    }

    public static void main(String[] args) {
        // Input string to be compressed
        String input = "huffman coding example";

        // Compress the input string
        Map<Character, String> huffmanCode = compress(input);

        // Compress the string to binary format
        StringBuilder compressedData = new StringBuilder();
        for (char c : input.toCharArray()) {
            compressedData.append(huffmanCode.get(c));
        }

        // Decompress the binary string
        String decompressedData = decompress(compressedData.toString(), huffmanCode);
        System.out.println("\nDecompressed Data: " + decompressedData);
    }
}

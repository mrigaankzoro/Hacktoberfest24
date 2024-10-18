public class Huffman{

    // Node class to represent a character and its frequency in the Huffman Tree
    static class Node {
        char ch;           // Character
        int freq;          // Frequency of the character
        Node left, right;  // Left and right child nodes

        // Constructor for Node
        public Node(char ch, int freq) {
            this.ch = ch;
            this.freq = freq;
            this.left = this.right = null;
        }
    }

    // Comparator for ordering nodes in the PriorityQueue
    static class CompareNode implements Comparator<Node> {
        public int compare(Node n1, Node n2) {
            return n1.freq - n2.freq;
        }
    }

    // Build the Huffman Tree and generate Huffman codes
    public static void buildHuffmanTree(String text) {
        // Step 1: Calculate the frequency of each character
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char ch : text.toCharArray()) {
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
        }

        // Step 2: Create a priority queue to store nodes (min-heap)
        PriorityQueue<Node> pq = new PriorityQueue<>(new CompareNode());

        // Step 3: Add all characters and their frequencies to the priority queue
        for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            pq.add(new Node(entry.getKey(), entry.getValue()));
        }

        // Step 4: Build the Huffman Tree by combining the two least frequent nodes
        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();

            Node newNode = new Node('-', left.freq + right.freq);
            newNode.left = left;
            newNode.right = right;

            pq.add(newNode);
        }

        // The root of the Huffman Tree
        Node root = pq.poll();

        // Step 5: Generate Huffman codes from the Huffman tree
        Map<Character, String> huffmanCodes = new HashMap<>();
        generateHuffmanCodes(root, "", huffmanCodes);

        // Step 6: Print Huffman codes
        System.out.println("Character Huffman Codes:");
        for (Map.Entry<Character, String> entry : huffmanCodes.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Step 7: Encode the input text using the Huffman codes
        StringBuilder encodedText = new StringBuilder();
        for (char ch : text.toCharArray()) {
            encodedText.append(huffmanCodes.get(ch));
        }
        System.out.println("\nEncoded Text: " + encodedText.toString());
    }

    // Recursive function to generate Huffman codes from the tree
    private static void generateHuffmanCodes(Node root, String code, Map<Character, String> huffmanCodes) {
        if (root == null) {
            return;
        }

        // If it's a leaf node, add the code to the map
        if (root.left == null && root.right == null) {
            huffmanCodes.put(root.ch, code);
        }

        // Traverse the left and right subtrees
        generateHuffmanCodes(root.left, code + "0", huffmanCodes);
        generateHuffmanCodes(root.right, code + "1", huffmanCodes);
    }

    public static void main(String[] args) {
        String text = "this is an example for huffman encoding";
        buildHuffmanTree(text);
    }
}

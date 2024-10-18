public class PalindromeCheck {
    public static boolean isPalindrome(String str) {
        // Remove any non-alphanumeric characters and convert to lowercase
        String cleanedStr = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

        // Initialize two pointers, one at the beginning and one at the end of the string
        int left = 0;
        int right = cleanedStr.length() - 1;

        // Check characters from both ends
        while (left < right) {
            // If characters at the current pointers are not the same, it's not a palindrome
            if (cleanedStr.charAt(left) != cleanedStr.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        // If the loop completes without returning false, it's a palindrome
        return true;
    }

    public static void main(String[] args) {
        String input = "A man, a plan, a canal, Panama";
        if (isPalindrome(input)) {
            System.out.println("The string is a palindrome.");
        } else {
            System.out.println("The string is not a palindrome.");
        }
    }
}

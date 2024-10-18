import java.util.Scanner;

public class LargestNumber {

    public static int findLargestNumber(int[] arr) {
        if (arr.length == 0) {
            return Integer.MIN_VALUE; // Return a minimum value if the array is empty
        }

        int largest = arr[0]; // Assume the first number is the largest

        for (int num : arr) {
            if (num > largest) {
                largest = num; // Update largest if current number is bigger
            }
        }

        return largest;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] numbers = new int[n];

        // Input elements
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            numbers[i] = scanner.nextInt();
        }

        // Finding the largest number
        int largestNumber = findLargestNumber(numbers);
        
        if (largestNumber != Integer.MIN_VALUE) {
            System.out.println("The largest number is: " + largestNumber);
        } else {
            System.out.println("The array is empty.");
        }

        scanner.close();
    }
}

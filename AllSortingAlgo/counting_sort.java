import java.util.Arrays;

public class CountingSort {
    public static void countingSort(int[] array) {
        int max = Arrays.stream(array).max().orElse(Integer.MAX_VALUE);
        int[] count = new int[max + 1];
        int[] output = new int[array.length];

        // Count occurrences
        for (int num : array) {
            count[num]++;
        }

        // Modify count array to hold the actual position of each number
        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = array.length - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        // Copy the sorted elements back to the original array
        System.arraycopy(output, 0, array, 0, array.length);
    }

    public static void main(String[] args) {
        int[] array = {4, 2, 2, 8, 3, 3, 1};
        countingSort(array);
        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}

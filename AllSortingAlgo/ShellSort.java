public class ShellSort {
    public static void shellSort(int arr[]) {
        int n = arr.length;

        // Start with a large gap and reduce it
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Perform an insertion sort for this gap size
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = {12, 34, 54, 2, 3};

        System.out.println("Original Array:");
        for (int element : arr) {
            System.out.print(element + " ");
        }

        shellSort(arr);

        System.out.println("\nSorted Array:");
        for (int element : arr) {
            System.out.print(element + " ");
        }
    }
}

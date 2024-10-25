import java.util.Scanner;

/*
In Bubble Sort, we repeatedly swap adjacent elements if they are in the wrong order.
This process moves the largest unsorted element to its correct position at the end of the array.
We repeat this process n-1 times to sort the entire array.
*/

public class BubbleSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n = sc.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Bubble Sort algorithm
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printArray(arr);
    }

    // Print sorted array
    public static void printArray(int arr[]) {
        System.out.println("Sorted array:");
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}

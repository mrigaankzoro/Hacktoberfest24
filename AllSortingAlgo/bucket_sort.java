import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class BucketSort {
    public static void bucketSort(float[] array) {
        // Create buckets
        int n = array.length;
        ArrayList<Float>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Distribute elements into buckets
        for (float num : array) {
            int bucketIndex = (int) (num * n); // Assuming numbers are in range [0, 1)
            buckets[bucketIndex].add(num);
        }

        // Sort individual buckets and concatenate
        int index = 0;
        for (ArrayList<Float> bucket : buckets) {
            Collections.sort(bucket);
            for (Float num : bucket) {
                array[index++] = num;
            }
        }
    }

    public static void main(String[] args) {
        float[] array = {0.42f, 0.32f, 0.23f, 0.74f, 0.93f, 0.12f};
        bucketSort(array);
        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}

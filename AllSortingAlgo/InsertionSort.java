import java.util.Scanner;
/*
 in insertionSort we assume given array as two part one is sorted anthor is unsorted part
 then compare the element of unsorted part one by one if the element is present inunsorted 
 part is smaller than sorted part then in sorted part element are push back and make space for 
 smaller element in that way the all element of unsorted part array will be sorted one by one.
 */

public class InsertionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array:");
        int n= sc.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter the element:");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        //insertionsort
        for(int i=1; i<n; i++){
            int current = arr[i];
            int j=i-1;
            while(j>=0 && current <arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=current;
        }
        printArray(arr);
    }
    public static void printArray(int arr[]){
        //print sorted array
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}

/*
 OUTPUT:
Enter the size of array:5
Enter the element:
3 4 1 0 6 
0 1 3 4 6

 */
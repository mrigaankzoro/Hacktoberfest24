/*
    sc- O(1)  no extra space taken
    tc-  O(n^2) worst case
    tc- O(nlogn) average case 
 */
import java.util.*;
public class QuickSort {
     public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter the size of Array:");
        int n=sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the Element:");
        for(int i=0; i<n; i++){
            arr[i]=sc.nextInt();
        }
        // int[] arr={6,3,9,5,2,8};
          

        quickSorts(arr, 0,n-1);
        System.out.println("Sorted array:");
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void quickSorts(int arr[] , int low , int high){
        if(low < high){
            int pidx = partition(arr, low, high);

            quickSorts(arr, low, pidx-1);
            quickSorts(arr, pidx+1, high);

        }
    }
    public static int partition(int arr[], int low, int high){
        int pivot=arr[high];
        int i=low -1;

        for(int j=low; j<high ;j++){
            if(arr[j]<pivot){
                i++;
                //swap
                int tmp=arr[i];
                arr[i] = arr[j];
                arr[j]=tmp;
                
            }
        }
        i++;
        int tmp=arr[i];
        arr[i]=pivot;
        arr[high]=tmp;
        return i;   //pivot index
    }
    
}

/*
 
Enter the size of Array:5
Enter the Element:
3 4 5 0 -4
Sorted array:
-4 0 3 4 5

 */

import java.util.Scanner;
/*
 in bubble sort here we put the largest element of the array at the end in this way we iterate 
 n-1 times outer loop finally the smaller once comes first element position.
 swaping perform when the ith element greater than i+1th element.
 */
public class BubbleSort {
    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        System.out.println("Enter the number of element:");
        int n=sc.nextInt();
        
        int arr[] = new int[n];
        System.out.println("Enter the of element:");
        for(int i=0; i<n; i++){
            arr[i]=sc.nextInt();
        }
        
        //bubble sort
        int tmp=0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr[j]> arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                }
            }
        }
        printArray(arr);

    }
    //print sorted array 
    public static void printArray(int arr[]){
        System.out.println("sorted array:");
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}

/* 
OUTPUT:

Enter the number of element:
5
Enter the of element:
3 8 2 -5 1
sorted array:
-5 1 2 3 8

*/
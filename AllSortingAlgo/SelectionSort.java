import java.util.Scanner;
/*
 //in selection sort here we first assume that the first element is the smallest one and then 
 we starting compare from index 1 i.e 2nd element .
 in bubble sort we swap while comapring if larger one is found before but in selection
 sort here we swap only once when one iteration complete .we just update the index or element
 of smaller element when found with the previous smaller one.
 and at the end of iteration we swap the current smaller element with the last smaller element.
 */
public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        
        int arr[]=new int[n];
        System.out.println("Enter the size of array: ");
        for(int i=0; i<n; i++){
            arr[i]=sc.nextInt();
        }

        //selection sort
        for(int i=0; i<n-1; i++){
            int smallest = i;
            for(int j=i+1; j<n; j++){
                if(arr[smallest] > arr[j]){
                    smallest = j;
                }
            }
            int tmp=arr[smallest];
            arr[smallest]=arr[i];
            arr[i]=tmp;
        }
        printArray(arr);
    }
    public static void printArray(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}


/*
 Enter the size of array:
5
Enter the size of array: 
3 0 -3 -5 33
-5 -3 0 3 33 

 */
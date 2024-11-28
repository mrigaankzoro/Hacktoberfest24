def quicksort(arr):
    """
    Sorts an array using the quicksort algorithm.

    Args:
        arr (list): The input array.

    Returns:
        list: The sorted array.
    """
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

# Example usage
arr = [5, 2, 9, 1, 7, 3, 6, 8, 4]
print("Original array:", arr)
print("Sorted array:", quicksort(arr))

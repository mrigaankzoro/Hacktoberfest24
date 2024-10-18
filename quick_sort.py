def quick_sort(arr):
    """
    Sorts an array using the Quick Sort algorithm.

    Parameters:
    arr (list): The list of elements to be sorted.

    Returns:
    list: A new sorted list.
    """

    # Base case: if the array has one or zero elements, it's already sorted
    if len(arr) <= 1:
        return arr

    # Choosing the pivot (here, we take the last element)
    pivot = arr[-1]
    left = []  # Elements less than the pivot
    right = []  # Elements greater than the pivot
    equal = []  # Elements equal to the pivot

    # Partitioning the array
    for element in arr:
        if element < pivot:
            left.append(element)
        elif element > pivot:
            right.append(element)
        else:
            equal.append(element)

    # Recursively applying quick sort to left and right sub-arrays
    return quick_sort(left) + equal + quick_sort(right)

# Example usage:
if __name__ == "__main__":
    sample_array = [10, 7, 8, 9, 1, 5]
    sorted_array = quick_sort(sample_array)
    print("Original array:", sample_array)
    print("Sorted array:", sorted_array)

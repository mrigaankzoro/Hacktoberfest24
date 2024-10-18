def quick_sort(arr):
  """Sorts an array using the Quicksort algorithm.

  Args:
    arr: The array to be sorted.

  Returns:
    The sorted array.
  """

  if len(arr) <= 1:
    return arr

  pivot = arr[len(arr) // 2]
  left = [x for x in arr if x < pivot]
  middle = [x for x in arr if x == pivot]
  right = [x for x in arr if x > pivot]

  return quick_sort(left) + middle + quick_sort(right)


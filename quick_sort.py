def quick_sort(arr):
    """Sorts an array using the Quick Sort algorithm."""
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]  # Choosing the pivot
        left = [x for x in arr if x < pivot]  # Elements less than the pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to the pivot
        right = [x for x in arr if x > pivot]  # Elements greater than the pivot
        return quick_sort(left) + middle + quick_sort(right)  # Recursively sort

def main():
    user_input = input("Enter numbers separated by spaces: ")
    # Convert input string to a list of integers
    try:
        numbers = list(map(int, user_input.split()))
        print(f"Original list: {numbers}")
        sorted_numbers = quick_sort(numbers)
        print(f"Sorted list: {sorted_numbers}")
    except ValueError:
        print("Please enter valid integers.")

if __name__ == "__main__":
    main()

def find_largest_number(arr):
    # Check if the array is empty
    if not arr:
        return None  # Return None if the list is empty

    largest = arr[0]

    for num in arr:
        if num > largest:
            largest = num

    return largest

if __name__ == "__main__":
    user_input = input("Enter numbers separated by spaces: ")
    arr = [int(num) for num in user_input.split()]  

    largest_number = find_largest_number(arr)
    if largest_number is not None:
        print("The largest number is:", largest_number)
    else:
        print("The list is empty.")

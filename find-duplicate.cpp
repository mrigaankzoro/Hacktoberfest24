def duplicates(arr):
    # Step 1: Create an empty dictionary to store element frequencies
    freq_map = {}
    result = []

    # Step 2: Iterate through the array and count element frequencies
    for num in arr:
        freq_map[num] = freq_map.get(num, 0) + 1

    # Step 3: Iterate through the dictionary to find duplicates
    for key, value in freq_map.items():
        if value > 1:
            result.append(key)

    # Step 4: If no duplicates found, add -1 to the result
    if not result:
        result.append(-1)
    # Step 5: Sort the result
    result.sort()
    # Step 6: Return the result list containing duplicate elements or -1
    return result

if __name__ == "__main__":
    a = [1, 6, 5, 2, 3, 3, 2]
    duplicates_found = duplicates(a)
    
    print("Duplicate elements:", end=" ")
    for element in duplicates_found:
        print(element, end=" ")
    print()

def fractional_knapsack(capacity, values, weights):
    # Create a list of items with their index, value, weight, and value-to-weight ratio
    items = [
        (values[i], weights[i], values[i] / weights[i]) 
        for i in range(len(values))
    ]

    # Sort items based on the value-to-weight ratio in descending order
    items.sort(key=lambda x: x[2], reverse=True)

    total_value = 0.0  # Store the total value of items taken

    for value, weight, ratio in items:
        if capacity <= 0:
            break  # No more capacity left to fill

        if weight <= capacity:
            # If we can take the whole item, do so
            total_value += value
            capacity -= weight
        else:
            # Take the fractional part of the remaining item
            total_value += ratio * capacity
            break  # Knapsack is now full

    return total_value

# Example usage
if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [10, 20, 30]
    capacity = 50

    max_value = fractional_knapsack(capacity, values, weights)
    print(f"Maximum value: {max_value:.2f}")

def fractional_knapsack(capacity, values, weights):
    # Create a list of items with value-to-weight ratio, value, and weight
    items = []
    for i in range(len(values)):
        ratio = values[i] / weights[i]
        items.append((ratio, values[i], weights[i]))

    # Sort the items by their value-to-weight ratio in descending order
    items.sort(reverse=True, key=lambda x: x[0])

    total_value = 0  # Store the total value of items taken

    for item in items:
        ratio, value, weight = item

        if capacity >= weight:
            # If we can take the full item, add its full value
            capacity -= weight
            total_value += value
        else:
            # Take the fractional part of the item
            total_value += value * (capacity / weight)
            break

    return total_value

# Example usage
values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 50

print(f"Maximum value: {fractional_knapsack(capacity, values, weights)}")

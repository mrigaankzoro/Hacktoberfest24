def fractional_knapsack(capacity, values, weights):
    """
    Solves the Fractional Knapsack problem by maximizing the total value of items
    that can be carried in a knapsack with a limited weight capacity.

    Args:
        capacity (int): The maximum weight capacity of the knapsack.
        values (list): A list of values for each item.
        weights (list): A list of weights for each item.

    Returns:
        float: The maximum total value of items that can be carried.
    """

    # Create a list of items with value-to-weight ratio, value, and weight
    items = [(value / weight, value, weight) for value, weight in zip(values, weights)]

    # Sort the items by their value-to-weight ratio in descending order
    items.sort(reverse=True)

    total_value = 0  # Store the total value of items taken

    for ratio, value, weight in items:
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

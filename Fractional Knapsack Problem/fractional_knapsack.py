class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value / weight  # Calculate value-to-weight ratio

def fractional_knapsack(capacity, items):
    # Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0  # Variable to store total value of knapsack
    for item in items:
        if capacity <= 0:
            break  # If the knapsack is full, break out of the loop
        
        if item.weight <= capacity:
            # If the item can be fully accommodated, take it all
            total_value += item.value
            capacity -= item.weight
        else:
            # If the item cannot be fully accommodated, take the fraction
            total_value += item.ratio * capacity  # Add value of the fraction
            capacity = 0  # The knapsack is now full
            
    return total_value

# Example usage
if __name__ == "__main__":
    items = [
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)
    ]
    capacity = 50
    max_value = fractional_knapsack(capacity, items)
    print(f"Maximum value in the knapsack: {max_value}")

# Fractional Knapsack Problem

## Overview

The **Fractional Knapsack Problem** is an optimization problem where the goal is to maximize the total value of items that can be carried in a knapsack with a limited weight capacity. In this problem, you can take fractions of an item, unlike the 0/1 Knapsack problem where you can only take entire items or none at all.

The solution uses a **greedy algorithm** to prioritize items based on their value-to-weight ratio and fills the knapsack to maximize the total value.

## Problem Statement

You are given:
- A set of `n` items, where each item has a value `v_i` and a weight `w_i`.
- A knapsack with a maximum weight capacity `W`.

The objective is to select fractions of items such that the total value is maximized while the total weight remains less than or equal to `W`.

## Algorithm

1. **Sort** the items in descending order of their value-to-weight ratio (`v_i / w_i`).
2. **Pick** items with the highest value-to-weight ratio first.
3. If the entire item can fit in the knapsack, take it. If not, take a fraction of it until the knapsack is full.

The algorithm ensures the maximum value is obtained by always picking the best option available at each step.

![Screenshot 2024-10-10 175713](https://github.com/user-attachments/assets/40b93089-0ce5-439e-95fc-a928e6edcd75)

## Steps:

1. **Input**:
   - A list of items, each with a value and weight.
   - A knapsack with a maximum weight capacity.

2. **Process**:
   - Sort items by their value-to-weight ratio.
   - Add as much of the highest ratio item as possible to the knapsack.
   - If the knapsack cannot accommodate the full weight of the current item, take the fraction of the item that fits.

3. **Output**:
   - The maximum value that can be carried in the knapsack.

## Example

### Input:
- Items:
    - Item 1: value = 60, weight = 10
    - Item 2: value = 100, weight = 20
    - Item 3: value = 120, weight = 30
- Maximum knapsack capacity: `W = 50`

### Process:
1. Calculate value-to-weight ratios:
    - Item 1: 60/10 = 6
    - Item 2: 100/20 = 5
    - Item 3: 120/30 = 4
2. Sort items by their ratios in descending order.
3. Add as much of the highest ratio items to the knapsack:
    - Take all of Item 1 (value = 60, weight = 10).
    - Take all of Item 2 (value = 100, weight = 20).
    - Take 2/3 of Item 3 (value = 80, weight = 20).

### Output:
- Maximum value in the knapsack: `60 + 100 + 80 = 240`.

## Conclusion

The greedy approach of picking the highest value-to-weight ratio at each step guarantees that the solution is optimal for the Fractional Knapsack problem. This problem showcases how a greedy algorithm can provide an optimal solution when the problem allows fractional choices.


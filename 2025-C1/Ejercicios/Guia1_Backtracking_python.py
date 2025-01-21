import numpy as np
import pandas as pd


def count_subsets_with_sum(C, k):
    def backtrack(start, current_sum):
        nonlocal count
        if current_sum == k:
            count += 1
        for i in range(start, len(C)):
            backtrack(i + 1, current_sum + C[i])

    count = 0
    backtrack(0, 0)
    return count

# Example usage
C = [6, 12, 6]
k = 12
result = count_subsets_with_sum(C, k)
print(f"Number of subsets with sum {k}: {result}")  # Expected output: 2
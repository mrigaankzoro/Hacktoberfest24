def findWays(k):
    memo = {}

    def dfs(stair, jump, prev_down):
        if stair == k:
            return 1
        if (stair, jump, prev_down) in memo:
            return memo[(stair, jump, prev_down)]
        if stair > k:
            return 0
        
        ways_up = dfs(stair + (1 << jump), jump + 1, False)
        
        ways_down = 0
        if stair > 1 and not prev_down:
            ways_down = dfs(stair - 1, jump, True)
        
        memo[(stair, jump, prev_down)] = ways_up + ways_down
        
        return memo[(stair, jump, prev_down)]
    
    return dfs(1, 0, False)

# Example usage:
k = 5
print(f"Number of ways to reach the {k}-th stair: {findWays(k)}")

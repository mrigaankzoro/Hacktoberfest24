class Solution:
    def countPrimes(self, n: int) -> int:
        # no primes lesser than 2
        if n<2:
            return 0
        # initialise a list with n True's
        primes = [True]*n
        ans = 0
        for i in range(2,n):
            # if prime then inc count
            if primes[i]:
                ans+=1
                # mark all multiples of i as false
                # how the for loop works:
                # start from i*i cuz till that number, all the prev nums would have marked the necessary numbers
                # go till n with steps of i (basically multiples of i)
                for j in range(i*i,n,i):
                    primes[j] = False

        return ans
    
# Time complexity: O(nloglogn)
# Space complexity: O(n)
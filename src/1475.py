from typing import List

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        ret = prices[:]

        stack = []

        for i in range(len(prices)):
            while stack and prices[stack[-1]] >= prices[i]:
                ret[stack.pop()] -= prices[i]

            stack.append(i)

        return ret
from typing import List

class Solution:        
    def generate(self, subs: List[List[int]], nums: List[int], curr: List[int]):
        if len(curr) == len(nums):
            return

        for n in nums:
            if n not in curr and (len(curr) == 0 or curr[-1] < n):
                curr.append(n)

                subs.append(curr[:])
                self.generate(subs, nums, curr)

                curr.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = [[]]
        self.generate(subsets, nums, [])

        return subsets
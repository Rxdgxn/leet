from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)

        def dfs(i: int) -> bool:
            if i == n - 1: return True

            end = min(n - 1, i + nums[i])
            for j in range(i + 1, end + 1):
                if dfs(j): return True

            return False

        return dfs(0)
from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ret = []

        last = {}

        for i in range(len(s)):
            last[s[i]] = i

        size = end = 0

        for i in range(len(s)):
            size += 1
            end = max(end, last[s[i]])

            if i == end:
                ret.append(size)
                size = 0

        return ret
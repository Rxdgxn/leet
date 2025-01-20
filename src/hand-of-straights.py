from typing import List

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()

        values = []
        occ = [0] * (hand[-1] + 1)

        for h in hand:
            occ[h] += 1

            if h not in values:
                values.append(h)

        i = 0
        n = len(values)

        while i < n:
            if occ[values[i]] == 0:
                i += 1
                continue

            for j in range(values[i], values[i] + groupSize):
                if j > hand[-1] or occ[j] == 0: return False
                occ[j] -= 1

        return True
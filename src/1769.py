class Solution(object):
    def minOperations(self, boxes):
        ret = []
        ones = []

        n = len(boxes)

        for i in range(0, n):
            if boxes[i] == '1':
                ones.append(i)

        for i in range(0, n):
            x = 0
            
            for j in ones:
                x += abs(i - j)

            ret.append(x)

        return ret
        
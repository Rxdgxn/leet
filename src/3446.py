class Solution(object):
    def sortMatrix(self, grid):
        n = len(grid)

        # bottom-left
        for row in range(n - 1, -1, -1):
            i = 0
            xs = []

            while row + i < n:
                xs.append(grid[row + i][i])
                i += 1

            xs.sort(reverse=True)

            for i in range(len(xs)):
                grid[row + i][i] = xs[i]

        # top-right
        for col in range(n - 1, 0, -1):
            i = 0
            xs = []

            while col + i < n:
                xs.append(grid[i][col + i])
                i += 1

            xs.sort()

            for i in range(len(xs)):
                grid[i][col + i] = xs[i]

        return grid
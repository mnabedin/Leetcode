# Given an m x n matrix, return all elements of the matrix in spiral order.

# Example 1:

# Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
# Output: [1,2,3,6,9,8,7,4,5]

# Leetcode 54: https://leetcode.com/problems/spiral-matrix/
# Difficulty: Medium

# Solution: Take the offset to determine which level of the spiral we're at, keep track of direction

def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    if not matrix:
        return matrix

    # We move right first and offset will be 0 initially
    direction = "right"
    i = j = offset = 0
    result = []
    m, n = len(matrix) - 1, len(matrix[0]) - 1

    # Iterate through all the elements in the matrix
    for _ in range(len(matrix) * len(matrix[0])):
        result += [matrix[i][j]]

        # Adjust i, j indices based on direction we are travelling
        # Moving right, we need to check if our j (coloumn) pointer reaches n (coloumn size) - offset then change direction
        if direction == "right":
            if j == n - offset:
                direction = "down"
            else:
                j += 1
        if direction == "down":
            if i == m - offset:
                direction = "left"
            else:
                i += 1
        if direction == "left":
            if j == offset:
                direction = "up"
            else:
                j -= 1

        # When we're going up, we change directions when i == offset + 1 because that row is the row below the previous spiral
        # We start traversing the inner spiral of the matrix now, also increment j and change direction to right
        if direction == "up":
            if i == offset + 1:
                direction = "right"
                offset += 1
                j += 1
            else:
                i -= 1

    return result

# Time Complexity: O(N)
# Space Complexity : O(N)

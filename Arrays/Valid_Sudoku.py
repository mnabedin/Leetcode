# Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
# Note:

# A Sudoku board (partially filled) could be valid but is not necessarily solvable.
# Only the filled cells need to be validated according to the mentioned rules.

# Leetcode 36: https://leetcode.com/problems/valid-sudoku/
# Difficulty: Medium

# Solution: Iterate through board, adding seen nums' row, col and block to set. If we ever see the same num in the same
# row, col or block return False


def isValidSudoku(self, board: List[List[str]]) -> bool:
    if not board:
        return False

    alreadySeen = set()

    # Iterate through the board
    for i, row in enumerate(board):
        for j, num in enumerate(row):
            # Skip current iteration if there's no number
            if num == ".":
                continue

            # Get the row, col and block for current number
            numInRow = num + "row" + str(i)
            numInCol = num + "col" + str(j)
            numInBlock = num + "block" + str(i // 3) + str(j // 3)

            # Return False if we've already seen this number in the current row, col or block
            if alreadySeen.intersection({numInRow, numInCol, numInBlock}):
                return False

            # Add to set if we haven't
            alreadySeen.add(numInRow)
            alreadySeen.add(numInCol)
            alreadySeen.add(numInBlock)

    # If we got to this point the board is valid so return True
    return True

# Time Complexity: O(N)
# Space Complexity: O(N)

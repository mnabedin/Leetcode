# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"

# Write the code that will take a string and make this conversion given a number of rows:

# string convert(string s, int numRows);

# Example 1:

# Input: s = "PAYPALISHIRING", numRows = 3
# Output: "PAHNAPLSIIGYIR"

# Leetcode 6: https://leetcode.com/problems/zigzag-conversion/
# Difficulty: Medium

# Solution: Create a list of strings with elements equal to numRows, keep a stepper to keep track of whether we have to go
# up or down the rows and update stepper based on the row we're at each time


def convert(self, s: str, numRows: int) -> str:
    if numRows == 1:
        return s

    rows = [""] * numRows
    i, step = 0, 1

    for letter in s:
        # For every letter, add it to the list
        rows[i] += letter

        # Increment i by the step (either go up or down). Initially, we increment by 1 (go down), when we get to the bottom
        # we decrement (go up), and we reverse again when we get to the top
        i += step

        # Reverse the step when we either reach the top or bottom row
        if i == 0 or i == numRows - 1:
            step *= -1

    # This is what rows will look like at the end
    # ['PAHN', 'APLSIIG', 'YIR']

    return "".join(rows)


# Time Complexiy: O(N)
# Space Complexity: O(N)

# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.

# Leetcode 20: https://leetcode.com/problems/valid-parentheses/

def isValid(self, s: str) -> bool:
    stack = []
    mapping = {")": "(", "}": "{", "]": "["}

    for bracket in s:
        # If we encounter a closing bracket
        if bracket in mapping:
            # Get the top element from the stack or a dummy value
            topElement = stack.pop() if stack else "#"

            # If the brackets don't match return False
            if topElement != mapping[bracket]:
                return False
        # We encountered an opening bracket, append to stack
        stack.append(bracket)

    # The stack needs to be empty if we have valid pairs of parenthesis
    return not stack

# Time Complexity: O(N)
# Space Complexity: O(N)

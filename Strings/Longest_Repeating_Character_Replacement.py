# You are given a string s and an integer k. You can choose any character of the string and change it to any other
# uppercase English character. You can perform this operation at most k times.

# Return the length of the longest substring containing the same letter you can get after performing the above operations.

# Example 2:

# Input: s = "AABABBA", k = 1
# Output: 4
# Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
# The substring "BBBB" has the longest repeating letters, which is 4.

# Leetcode 424: https://leetcode.com/problems/longest-repeating-character-replacement/
# Difficulty: Medium

# Solution: Sliding window. For each window we want the most frequent character and replace all other characters with this
# as this maximizes the number of replacements.

def characterReplacement(self, s: str, k: int) -> int:
    if len(s) == 1:
        return s

    # Initialize window and table
    table = {}
    start = end = 0
    res = maxFrequency = float('-inf')

    while end < len(s):
        # Add count of current char
        table[s[end]] = table.get(s[end], 0) + 1
        # Global frequency since if maxFrequency of window A >= maxFrequency of window B, window A has to be longer than
        # window B. We want to consider the character with the highest frequency.
        maxFrequency = max(maxFrequency, table[s[end]])

        # Property we want to hold
        if (end - start + 1) - maxFrequency > k:
            # Slide window to the left as property violated so need to remove a count for the starting of the window
            table[s[start]] -= 1
            start += 1

        # Always update res
        res = max(res, end - start + 1)
        end += 1

    return res

# Time Complexity: O(N)
# Space Complexity: O(1) (table can only be of 26 characters)

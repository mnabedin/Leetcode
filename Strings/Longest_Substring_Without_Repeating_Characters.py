# Given a string s, find the length of the longest substring without repeating characters.

# Example 1:
# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.

# Example 2:
# Input: s = "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.

# Leetcode 3: https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Difficulty: Medium

# Solution: Sliding window. Use dictionary to keep track of chars in window, move start if duplicate char found
# in window.

def lengthOfLongestSubstring(self, s: str) -> int:
    if not s or len(s) == 0:
        return 0

    # Initialize start, end of window, res and table to keep track of char indices
    start, end, res = 0, 0, float('-inf')
    table = {}

    while end < len(s):
        # If we have seen this char before and the char is in the current window, move start to the next of the last
        # position of char because we want to ignore duplicates
        if s[end] in table and table[s[end]] >= start:
            start = table[s[end]] + 1

        # Always update result, and last seen index of current char. End - start + 1 because it's inclusive.
        res = max(res, end - start + 1)
        table[s[end]] = end
        end += 1

    return res

# Time Complexity: O(N)
# Space Complexity: O(1)

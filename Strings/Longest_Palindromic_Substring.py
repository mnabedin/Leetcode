# Given a string s, return the longest palindromic substring in s.

# Example 1:
# Input: s = "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.

# Example 2:
# Input: s = "cbbd"
# Output: "bb"

# Leetcode 5: https://leetcode.com/problems/longest-palindromic-substring/
# Difficulty: Medium

# Solution: Realize that a palindrome mirrors about its center. So for each position, expand around center to find a
# palindrome. Handle both even and odd cases.

def longestPalindrome(self, s: str) -> str:
    if len(s) == 1:
        return s

    # This function returns a palindrome given a string, left and right ptrs by exapnding around the center
    def findPalindrome(s, left, right):
        # While the ptrs are in range in the characters are equal
        while left >= 0 and right < len(s) and s[left] == s[right]:
            # Expand
            left -= 1
            right += 1

        # We broke out of the loop so ignore left. Left + 1 inclusive to right exclusive.
        return s[left + 1:right]

    res = ""
    resLen = float('-inf')

    # Expand around center for each position
    for i in range(len(s)):
        # Odd case: "racecar"
        temp = findPalindrome(s, i, i)

        if len(temp) > resLen:
            res = temp
            resLen = len(temp)

        # Even case: "abba"
        temp = findPalindrome(s, i, i + 1)

        if len(temp) > resLen:
            res = temp
            resLen = len(temp)

    return res

# Time Complexity: O(N^2)
# Space Complexity: O(1)

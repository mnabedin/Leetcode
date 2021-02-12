# Given two strings s and t , write a function to determine if t is an anagram of s.

# Example 1:

# Input: s = "anagram", t = "nagaram"
# Output: true
# Example 2:

# Input: s = "rat", t = "car"
# Output: false

# Leetcode 242: https://leetcode.com/problems/valid-anagram/
# Difficulty: Easy

def isAnagram(self, s: str, t: str) -> bool:
    # Handle edge case where strings are of unequal lenghts
    if len(s) != len(t):
        return False

    # Initialize hash table to keep track of occurences of characters
    counter = {}

    # Iterate through the first string and incremement counter accordingly
    for letter in s:
        if letter not in counter:
            counter[letter] = 0
        counter[letter] += 1

    # Iterate through the second string and decrement counter if we have seen the character or return False
    for letter in t:
        if letter not in counter:
            return False
        counter[letter] -= 1

    # If we have a valid anagram, the values should be 0
    for value in counter.values():
        if value != 0:
            return False

    return True

# Time Complexity: O(n)
# Space Complexity: O(n)

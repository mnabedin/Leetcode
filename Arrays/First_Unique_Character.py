# Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

# Examples:

# s = "leetcode"
# return 0.

# s = "loveleetcode"
# return 2.

# Leetcode 387: https://leetcode.com/problems/first-unique-character-in-a-string/

def firstUniqChar(self, s: str) -> int:

    # Build a hashMap where the keys are the characters and the values are how often the character appears
    hashMap = collections.Counter(s)

    # Iterate through the string
    for index, char in enumerate(s):
        # If the count of the char we're at is 1, return it's index
        if hashMap[char] == 1:
            return index

    # No unique character exists
    return -1

# Time Complexity: O(N)
# Space Complexity: O(1) since there is a finite number of characters in the alphabet

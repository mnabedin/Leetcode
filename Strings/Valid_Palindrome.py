# Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

# Example 1:
# Input: s = "A man, a plan, a canal: Panama"
# Output: true
# Explanation: "amanaplanacanalpanama" is a palindrome.

# Leetcode 125: https://leetcode.com/problems/valid-palindrome/
# Difficulty: Easy

# Solution: Two pointers. Move left and right pointers inwards and check if they're the same.

def isPalindrome(self, s: str) -> bool:
    if len(s) == 1:
        return True

    left, right = 0, len(s) - 1

    while left < right:
        # Move left and right pointers until we reach a character
        if not s[left].isalnum():
            left += 1
        elif not s[right].isalnum():
            right -= 1
        # Reached a character
        else:
            # Chars equal so move pointers inwards
            if s[left].lower() == s[right].lower():
                left += 1
                right -= 1
            # Not equal so cannot be a palindrome
            else:
                return False

    # If we reached here, all chars are the same forwards as they are backwards
    return True

# Time Complexity: O(N)
# Space Complexity: O(1)

# In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. T
# he order of the alphabet is some permutation of lowercase letters.

# Given a sequence of words written in the alien language, and the order of the alphabet,
# return true if and only if the given words are sorted lexicographicaly in this alien language.

# Example 1:

# Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
# Output: true
# Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

# Example 3:

# Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
# Output: false
# Explanation: The first three characters "app" match, and the second string is shorter (in size.)
# According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character
# which is less than any other character.

# Leetcode 953: https://leetcode.com/problems/verifying-an-alien-dictionary/
# Difficulty: Easy

# Solution: Realize we only care about the letters that are different. Create a mapping of letter to index to
# use for comparision. Iterate through two words at a time and compare them.


def isAlienSorted(self, words: List[str], order: str) -> bool:
    # Creating mapping of letter to it's position
    orderMap = {c: i for i, c in enumerate(order)}

    # Iterate through two words at the same time
    for i in range(len(words) - 1):
        # For each character
        for j in range(len(words[i])):
            # Return False if we don't encounter a different letter but we're at the end of current word.
            # Case: ["apple", "app"] we can't iterate through the second word as it's smaller
            if j >= len(words[i + 1]):
                return False

            # If we find a different letter
            if words[i][j] != words[i + 1][j]:
                # Compare position of letter at current word to next word. If current word is lexicographically larger
                # return False as words aren't sorted
                if orderMap[words[i][j]] > orderMap[words[i + 1][j]]:
                    return False
                # Different letters but they're in the right order, the sequence is sorted
                break

    # If we got to this point, all words are sorted in lexicographical order so return True
    return True

# Time Complexity: O(N)
# Space Complexity: O(1)

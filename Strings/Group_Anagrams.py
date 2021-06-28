# Given an array of strings strs, group the anagrams together. You can return the answer in any order.

# An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the
# original letters exactly once.

# Example 1:
# Input: strs = ["eat","tea","tan","ate","nat","bat"]
# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

# Leetcode 49: https://leetcode.com/problems/group-anagrams/
# Difficulty: Medium

# Solution: Realize that you get the same word when you sort anagrams. Use that to build a hash table of sortedWord to
# its anagrams.

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    table = {}

    for word in strs:
        # Sort each word
        sortedWord = "".join(sorted(word))
        # Add to hash table if it doesn't exist, or add to exisiting list of anagrams
        if sortedWord not in table:
            table[sortedWord] = [word]
        else:
            table[sortedWord] += [word]

    # Return hash table values
    return table.values()

# Time Complexity: O(N^2*log(N))
# Space Complexity: O(N)

from typing import List


def mergeSort(nums: List[int]) -> List[int]:
    # Base case: if length of list is 1, it's already sorted so we can return it.
    if len(nums) == 1:
        return nums

    # Recursively sort left and right sub-lists
    left = mergeSort(nums[:len(nums) // 2])
    right = mergeSort(nums[len(nums) // 2:])

    sortedNums, i, j = [], 0, 0

    # While i and j are less than the lengths of the lists they point to
    while i < len(left) and j < len(right):
        # Add the smaller item from the left or right list to the sortedNums list, and increment the counter
        if left[i] < right[j]:
            sortedNums += [left[i]]
            i += 1
        else:
            sortedNums += [right[j]]
            j += 1

    # We've exhausted one of the lists so add the rest of the items from the other list
    sortedNums += left[i:] + right[j:]

    return sortedNums

# Time Complexity : O(NlogN)
# Space Complexity: O(N)


def main():
    nums = [6, 7, 3, 2, 9, 3, 1, 0]
    print(mergeSort(nums))


main()

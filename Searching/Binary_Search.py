from typing import List


def binarySearch(nums: List[int], target: int) -> List[int]:
    # Initialize our left and right pointers
    l, r = 0, len(nums) - 1

    # Note: setting this while statement to be <= and not just != means it can also
    # catch cases when the input is an empty array, as l = 0 and r = -1 in that case
    while l <= r:

        # In each iteration set the midpoint to half the difference of the left
        # and right pointers offset by the left pointer (Prevents overflow)
        mid = l + (r - l) // 2

        # If the target is larger than the midpoint, look in the right sub-list
        if nums[mid] < target:
            l = mid + 1

        # If the target is smaller than the midpoint, look in the left sub-list
        elif nums[mid] > target:
            r = mid - 1

        # nums[mid] == target so return index of where we found the target
        else:
            return mid

    # If we reached this point, the target is not in the list
    return -1

# Time Complexity: O(logN)
# Space ComplexityL O(1)


def main():
    nums = [0, 0, 2, 3, 4, 6, 7, 9]
    print(binarySearch(nums, 2))


main()

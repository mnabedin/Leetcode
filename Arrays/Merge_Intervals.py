# Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
# and return an array of the non-overlapping intervals that cover all the intervals in the input.

# Example 1:

# Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

# Leetcode 56: https://leetcode.com/problems/merge-intervals/
# Difficulty: Medium

# Solution: Sort the intervals based on start time. If there is an intersection, merge the intervals


def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    if not intervals:
        return []

    i = 0
    intervals.sort(key=lambda x: x[0])

    while i < len(intervals) - 1:
        # If the ending of the ith interval is greater than or equal to the starting of the i + 1th interval, we can merge
        if intervals[i][1] >= intervals[i + 1][0]:
            # The new interval is the starting time of ith interval and max(ending time of ith, ending time of i + 1th)
            # Just because i end >= i + 1 begin, doesn't mean i + 1 end > i end
            intervals[i] = [intervals[i][0], max(intervals[i][1], intervals[i + 1][1])]
            del intervals[i + 1]
        # No overlap, increment i
        else:
            i += 1

    return intervals


# Time Complexity: O(NlogN)
# Space Complexity: O(1)

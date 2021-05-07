# Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals
# you need to remove to make the rest of the intervals non-overlapping.

# Example 1:
# Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
# Output: 1
# Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

# Example 2:
# Input: intervals = [[1,2],[1,2],[1,2]]
# Output: 2
# Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

# Leetcode 435: https://leetcode.com/problems/non-overlapping-intervals/
# Difficulty: Medium

# Solution: Realize that the problem is also asking for maximum number of non-overlapping intervals. To get this,
# sort intervals by end time and remove overlapping intervals with earliest end time

def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    if intervals == []:
        return 0

    # Sort by end time as that will allow us to remove intervals in a way that leaves max number of non-overlapping
    # intervals
    result, end = 0, float('-inf')
    intervals.sort(key=lambda x: x[1])

    for interval in intervals:
        start = interval[0]
        # Remove if there is an overlap
        if start < end:
            result += 1
        # Update end
        else:
            end = interval[1]

    return result

# Time Complexity: O(NlogN)
# Space Complexity: O(1)

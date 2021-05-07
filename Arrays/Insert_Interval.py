# Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

# You may assume that the intervals were initially sorted according to their start times.

# Example 1:
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]

# Example 2:
# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

# Leetcode 57: https://leetcode.com/problems/insert-interval/
# Difficulty: Medium

# Solution: Add all the intervals before newInterval, if ending of newInterval < interval currently processed, insert newInterval
# and return, else we found an overlap so update start and end of newInterval

def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    if len(intervals) == 1:
        return [newInterval]

    result, n = [], newInterval

    for index, interval in enumerate(intervals):
        # Ending time of interval is before starting time of newInterval so add interval to results
        if interval[1] < n[0]:
            result.append(interval)
        # Ending time of newInterval is less than starting time of interval we are at so we can return early as this will
        # be the case for all subsequent intervals
        elif n[1] < interval[0]:
            result.append(n)
            return result + intervals[index:]
        # There is an overlap. Update newInterval to merge overlapping intervals
        else:
            n[0] = min(n[0], interval[0])
            n[1] = max(n[1], interval[1])

    # We only encountered overlapping intervals if we got to this point so add updated newInterval and return
    result.append(n)
    return result

# Time Complexity: O(N)
# Space Complexity: O(1)

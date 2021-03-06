# You are given an array prices where prices[i] is the price of a given stock on the ith day.

# You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

# Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

# Example 1:

# Input: prices = [7,1,5,3,6,4]
# Output: 5
# Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
# Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

# Leetcode 121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Difficulty: Easy

def maxProfit(self, prices: List[int]) -> int:
    result, minAmount = 0, float('inf')

    for price in prices:
        # If we encounter a new minimum price, change minAmount
        if price < minAmount:
            minAmount = price
        # The result will be the max of the current result and the profit gained by selling the stock at that day after buying at minAmount
        result = max(result, price - minAmount)

    return result

# Time Complexity: O(N)
# Space Complexity: O(1)

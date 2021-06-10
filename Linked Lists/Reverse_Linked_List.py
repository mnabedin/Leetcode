# Given the head of a singly linked list, reverse the list, and return the reversed list.

# Example 1:
# Input: head = [1,2,3,4,5]
# Output: [5,4,3,2,1]

# Solution: Iterate through linked list, set prev to None curr to head keep track of next ptr of curr, reverse
# curr and move ptrs forward

def reverseList(self, head: ListNode) -> ListNode:
    # Intialize variables, prev is going to be the new head
    prev, curr = None, head

    # Iterate through linked list
    while curr:
        # Temp variable to store next ptr since we lose reference to it
        nextTemp = curr.next
        # Reverse
        curr.next = prev
        # Move ptrs forward
        prev = curr
        curr = nextTemp

    return prev

# Time Complexity: O(N)
# Space Complexity: O(1)

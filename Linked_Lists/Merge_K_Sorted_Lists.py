# You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

# Merge all the linked-lists into one sorted linked-list and return it.

# Example 1:
# Input: lists = [[1,4,5],[1,3,4],[2,6]]
# Output: [1,1,2,3,4,4,5,6]
# Explanation: The linked-lists are:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# merging them into one sorted list:
# 1->1->2->3->4->4->5->6

# Leetcode 23: https://leetcode.com/problems/merge-k-sorted-lists/
# Difficulty: Hard

# Solution: Add all the head nodes to a heap, pop from the heap and create a linked list.x

def mergeKLists(self, lists: List[ListNode]) -> ListNode:
    if not lists:
        return None

    heap = []
    # Head and tail pointers for linked list to be returned
    head = tail = ListNode(0)

    # Push all the nodes to the heap if node exists (we're guaranteed that head nodes are the smallest)
    for i, node in enumerate(lists):
        if node:
            # Use index as a tie-breaker to push the samllest node if node.val is the same
            heapq.heappush(heap, (node.val, i, node))

    # While there are elements in the heap
    while heap:
        # Pop the head node
        node = heapq.heappop(heap)[2]
        # Build the linked list using tail.next and move tail forward
        tail.next = node
        tail = tail.next
        # If the node has a next node, push that node to the heap as we don't know how large the val is
        if node.next:
            i += 1
            heapq.heappush(heap, (node.next.val, i, node.next))

    return head.next

# Time Complexity: O(Nlogk) where N is the number of nodes and k is the number of lists
# Space Complexity: O(k)

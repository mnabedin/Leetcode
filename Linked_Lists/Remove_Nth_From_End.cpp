/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head -> next) return nullptr;
        ListNode dummy(-1);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        dummy.next = head;
        for(int i = 0; i < n; i++) fast = fast -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return dummy.next;
    }
};
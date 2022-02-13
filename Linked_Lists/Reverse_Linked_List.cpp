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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next_temp = nullptr;
        ListNode* curr = head;
        while(curr) {
            next_temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
};
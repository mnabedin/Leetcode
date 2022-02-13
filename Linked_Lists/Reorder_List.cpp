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
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast && fast -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        ListNode* h1 = head;
        ListNode* h2 = reverse(slow);
        ListNode* h1_next = nullptr;
        ListNode* h2_next = nullptr;
        while(h2) {
            h1_next = h1 -> next;
            h2_next = h2 -> next;
            h1 -> next = h2;
            if(!h1_next) break;
            h2 -> next = h1_next;
            h1 = h1_next;
            h2 = h2_next;
        }
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next_temp = nullptr;
        while(curr) {
            next_temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
};
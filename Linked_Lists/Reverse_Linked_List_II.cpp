/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* current = head;
        ListNode* previous = nullptr;

        for (int i = 0; i < left - 1 && current != nullptr; ++i) {
            previous = current;
            current = current -> next;
        }
        
        ListNode* before_sublist = previous;
        ListNode* last_of_sublist = current;

        for (int i = 0; i < right - left + 1 && current != nullptr; ++i) {
            ListNode* current_next = current -> next;
            current -> next = previous;
            previous = current;
            current = current_next;
        }

        if (before_sublist != nullptr) {
            before_sublist -> next = previous;
        } else {
            head = previous;
        }

        last_of_sublist -> next = current;

        return head;
    }
};


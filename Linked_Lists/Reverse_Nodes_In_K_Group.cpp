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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;
        ListNode* current = head;
        ListNode* previous = nullptr;
        while (true) {
            ListNode* node_before_sublist = previous;
            ListNode* last_node_of_sublist = current;
            ListNode* current_next = nullptr;
            ListNode* check = last_node_of_sublist;
            for (int i = 0; i < k; ++i) {
                if (check == nullptr) return head;
                check = check -> next;
            }
            for (int i = 0; current != nullptr && i < k; ++i) {
               current_next = current -> next;
               current -> next = previous;
               previous = current;
               current = current_next;
            }

            if (node_before_sublist != nullptr) {
                node_before_sublist -> next = previous;
            } else {
                head = previous;
            }
            
            last_node_of_sublist -> next = current;
            if (current == nullptr) break;

            previous = last_node_of_sublist;
        }
        return head;
    }
};


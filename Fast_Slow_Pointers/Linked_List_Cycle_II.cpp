/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (head == nullptr || head -> next == nullptr) return nullptr;
            ListNode* fast = head; 
            ListNode* slow = head;
            ListNode* find_cycle = head;
            while (fast -> next && fast -> next -> next) {
                fast = fast -> next -> next;
                slow = slow -> next;
                if (fast == slow) {
                    while (find_cycle != slow) {
                        find_cycle = find_cycle -> next;
                        slow = slow -> next;
                    }
                    return find_cycle;
                }
            }
            return nullptr;
        }
};

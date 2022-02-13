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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mp;
        for(ListNode* l : lists) {
            if(l) mp.insert(make_pair(l -> val, l));
        }
        ListNode head(-1);
        ListNode* tail = &head;
        while(!mp.empty()) {
            multimap<int, ListNode*>::iterator it = mp.begin();
            tail -> next = it -> second;
            tail = tail -> next;
            if(it -> second -> next) {
                mp.insert(make_pair(it->second->next->val, it->second->next));
            }
            mp.erase(it);
        }
        return head.next;
    }
};
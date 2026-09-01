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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* current = head;

        while(current != NULL) {
            n++;
            current = current->next;
        }

        if(n == 1)
            return NULL;

        current = head;
        ListNode* previous = NULL;

        for(int i = 0; i < n / 2; i++) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;

        return head;
    }
};
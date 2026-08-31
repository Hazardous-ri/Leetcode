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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> a;

        ListNode* p = head;
        ListNode* c = head->next;
        ListNode* n = c->next;

        int pos = 2;

        while(n != NULL) {

            if((c->val > p->val && c->val > n->val) ||
               (c->val < p->val && c->val < n->val)) {
                
                a.push_back(pos);
            }

            p = c;
            c = n;
            n = n->next;

            pos++;
        }

        if(a.size() < 2) {
            return {-1, -1};
        }

        int mn = INT_MAX;

        for(int i = 1; i < a.size(); i++) {
            mn = min(mn, a[i] - a[i - 1]);
        }

        int mx = a[a.size() - 1] - a[0];

        return {mn, mx};
    }
};
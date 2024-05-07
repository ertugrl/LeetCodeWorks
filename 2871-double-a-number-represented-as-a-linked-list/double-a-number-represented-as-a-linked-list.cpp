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
    ListNode* doubleIt(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* tmp;
        if (head->val >= 5){
            tmp = new ListNode(1);
            tmp->next = head;
            head = tmp;
            tmp = tmp->next;
        }

        while (tmp){
            tmp->val = (tmp->val * 2) % 10;
            if (!tmp->next) break;
            if (tmp->next->val >= 5){
                tmp->val++;
            }
            tmp = tmp->next;
        }

        return head;
    }
};
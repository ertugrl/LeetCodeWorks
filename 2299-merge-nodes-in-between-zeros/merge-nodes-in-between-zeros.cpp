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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tmp = head->next;
        vector<int> sums;

        int sum = 0;
        while (tmp) {
            sum += tmp->val;
            if (tmp->val == 0) {
                sums.push_back(sum);
                sum = 0;
            }
            tmp = tmp->next;
        }
        
        tmp = head;
        for (int i = 0; i < sums.size() - 1; ++i) {
            tmp->val = sums[i];
            tmp = tmp->next;
        }
        tmp->val = sums[sums.size() - 1];
        tmp->next = nullptr;

        return head;
    }
};
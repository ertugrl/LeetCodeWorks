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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* tmp = head;
        vector<int> nodes;
        while (tmp) {
            nodes.push_back(tmp->val);
            tmp = tmp->next;
        }

        int tmp2;
        for (int i = 1; i < nodes.size(); ++i) {
            int prev = i - 1;
            int curr = i;
            while (prev >= 0 && nodes[curr] < nodes[prev]) {
                tmp2 = nodes[curr];
                nodes[curr--] = nodes[prev];
                nodes[prev--] = tmp2;
            }
        }

        tmp = head;
        tmp2 = 0;
        while (tmp) {
            tmp->val = nodes[tmp2++];
            tmp = tmp->next;
        }

        return head;
    }
};
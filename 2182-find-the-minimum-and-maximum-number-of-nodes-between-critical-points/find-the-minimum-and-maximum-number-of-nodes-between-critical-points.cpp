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
        vector<int> result;
        int nth = 1;
        ListNode* cur = head->next, * prev = head; // wow!
        while (cur->next) {
            if (cur->val > cur->next->val && cur->val > prev->val) {
                result.push_back(nth);
            } else if (cur->val < cur->next->val && cur->val < prev->val) {
                result.push_back(nth);
            }
            prev = cur;
            cur = cur->next;
            nth++;
        }

        if (result.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < result.size(); ++i) {
            minDist = min(minDist, result[i] - result[i - 1]);
        }

        return {minDist, result[result.size() - 1] - result[0]};
    }
};
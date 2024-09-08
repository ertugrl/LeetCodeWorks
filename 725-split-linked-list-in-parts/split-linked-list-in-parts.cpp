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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int totalNode = 0;
        while (curr != nullptr) {
            curr = curr->next;
            totalNode++;
        }

        int remainder = totalNode % k;
        int numOfNode = totalNode / k;
        
        curr = head;
        ListNode* temp;
        vector<ListNode*> heads;
        for (int i = 0; i < remainder; ++i) {
            heads.push_back(curr);
            for (int j = 0; j < numOfNode; ++j) {
                curr = curr->next;
            }
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
        }

        if (totalNode < k) {
            for (int i = 0; i < k - totalNode; ++i) {
                heads.push_back(nullptr);
            }
        } else {
            for (int i = 0; i < k - remainder; ++i) {
                heads.push_back(curr);
                for (int j = 0; j < numOfNode - 1; ++j) {
                    curr = curr->next;
                }
                temp = curr;
                curr = curr->next;
                temp->next = nullptr;
            }
        }

        return heads;
    }
};
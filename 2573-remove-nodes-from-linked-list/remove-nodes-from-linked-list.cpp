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
    ListNode* removeNodes(ListNode* head) {
        deque<int> nodes;
        nodes.push_front(head->val);
        ListNode* tmp = head->next;
        while (tmp){
            while (!nodes.empty() && nodes.front() < tmp->val){
                nodes.pop_front();
            }
            nodes.push_front(tmp->val);
            tmp = tmp->next;
        }
        head->val = nodes.back();
        nodes.pop_back();

        tmp = head;
        while (!nodes.empty()){
            tmp->next->val = nodes.back();
            nodes.pop_back();
            tmp = tmp->next;
        }
        tmp->next = nullptr;

        return head;
    }
};
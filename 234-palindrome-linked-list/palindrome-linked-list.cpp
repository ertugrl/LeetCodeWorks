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
    bool isPalindrome(ListNode* head) {
        ListNode* tmp = head;
        int size = 0;
        vector<int> v;
        tmp = head;
        while (tmp){
            size++;
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        for (int i = 0; i < size / 2; ++i){
            if (head->val != v[size - (1 + i)]){
                return false;
            }
            head = head->next;
        }
        return true;
    }
};
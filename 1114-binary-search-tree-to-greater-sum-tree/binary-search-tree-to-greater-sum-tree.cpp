/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* curr = root;
        stack<TreeNode*> s;

        int sum = 0;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->right;
            }
            cout << s.top()->val << endl;
            curr = s.top();
            curr->val += sum;
            sum = curr->val;
            s.pop();
            curr = curr->left;
        }
        
        return root;
    }
};
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            curr = q.front();

            // inverting
            TreeNode* tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;

            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }

            q.pop();
        }

        return root;
    }
};
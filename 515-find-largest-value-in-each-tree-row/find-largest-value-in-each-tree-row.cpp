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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        vector<int> result;
        map<int, int> mp;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        TreeNode* temp;
        int depth;
        while (!q.empty()) {
            temp = q.front().first;
            depth = q.front().second;

            // Update max value for the row
            if (mp.find(depth) != mp.end()) {
                mp[depth] = max(q.front().first->val, mp[depth]);
            } else {
                mp[depth] = q.front().first->val;
            }

            if (temp->left) {
                q.push({temp->left, depth + 1});
            }
            if (temp->right) {
                q.push({temp->right, depth + 1});
            }

            q.pop();
        }
        
        for (auto i : mp) {
            result.push_back(i.second);
        }
        return result;
    }
};
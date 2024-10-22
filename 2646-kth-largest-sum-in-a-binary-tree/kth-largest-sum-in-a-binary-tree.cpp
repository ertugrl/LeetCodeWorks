/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, long long k) {
        unordered_map<long long, long long> mp;

        queue<pair<TreeNode*, long long>> q; // (depth, value)
        q.push(pair{root, 1});
        TreeNode* tmp = root;
        while (!q.empty()) {
            long long currDepth = q.front().second;
            TreeNode* currPtr = q.front().first;
            if (mp.find(currDepth) != mp.end()) {
                mp[currDepth] += currPtr->val;
            } else {
                mp[currDepth] = currPtr->val;
            }

            if (currPtr->left) {
                q.push({currPtr->left, currDepth + 1});
            } if (currPtr->right) {
                q.push({currPtr->right, currDepth + 1});
            }

            q.pop();
        }
        
        vector<long long> result;

        for (auto& it : mp) {
            result.push_back(it.second);
        }

        sort(result.begin(), result.end(), greater<long long>());

        return (k > result.size() ? -1 : result[k - 1]);
    }
};
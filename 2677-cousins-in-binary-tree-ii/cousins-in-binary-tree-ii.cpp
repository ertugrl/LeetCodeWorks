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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mp;

        queue<pair<TreeNode*, int>> sumQ; // (depth, value)
        sumQ.push(pair{root, 0});
        TreeNode* tmp = root;
        // To fill the map according to
        // key = level (~depth)
        // value = sum of all nodes with the same level
        while (!sumQ.empty()) {
            int currDepth = sumQ.front().second;
            TreeNode* currPtr = sumQ.front().first;
            if (mp.find(currDepth) != mp.end()) {
                mp[currDepth] += currPtr->val;
            } else {
                mp[currDepth] = currPtr->val;
            }

            if (currPtr->left) {
                sumQ.push({currPtr->left, currDepth + 1});
            } if (currPtr->right) {
                sumQ.push({currPtr->right, currDepth + 1});
            }

            sumQ.pop();
        }

        queue<pair<TreeNode*, int>> cousinsQ;
        tmp = root;
        cousinsQ.push({root, 0});
        while (!cousinsQ.empty()) {
            int currDepth = cousinsQ.front().second;
            TreeNode* currPtr = cousinsQ.front().first;

            int siblingSum = 0;
            int leftVal = 0;
            int rightVal = 0;

            bool leftExist = (currPtr->left != nullptr);
            bool rightExist = (currPtr->right != nullptr);
            if (leftExist) {
                leftVal = currPtr->left->val;
            }
            if (rightExist) {
                rightVal = currPtr->right->val;
            }
            siblingSum = leftVal + rightVal;
            
            // update the node values
            int nextDepth = currDepth + 1;
            if (leftExist) {
                currPtr->left->val = mp[nextDepth] - siblingSum;
            }
            if (rightExist) {
                currPtr->right->val = mp[nextDepth] - siblingSum;
            }

            if (leftExist) {
                cousinsQ.push({currPtr->left, nextDepth});
            }
            if (rightExist) {
                cousinsQ.push({currPtr->right, nextDepth});
            }

            cousinsQ.pop();
        }

        root->val = 0;
        return root;
    }
};
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

private:
    void rootToNode(TreeNode* root,int &n,int &m,string &temp,string &s,string &d){
        if(!root) return;

        if(root->val == n) s=temp;
        if(root->val == m) d=temp;
        
        temp.push_back('L');
        rootToNode(root->left, n, m, temp, s, d);
        temp.pop_back();

        temp.push_back('R');
        rootToNode(root->right, n, m, temp, s, d);
        temp.pop_back();
    }


public:
    string getDirections(TreeNode* root, int n, int m) {

        string s,d,temp;
        rootToNode(root,n,m,temp,s,d);

        int ind = 0;

        for(int i=0;i<s.size() && i<d.size();i++){
            if(s[i]==d[i]) ind=i+1;
            else break;
        }

        string ans;

        for(int i = ind;i<s.size();i++){
            ans.push_back('U');
        }

        for(int i = ind;i<d.size();i++){
            ans.push_back(d[i]);
        }

        return ans;
    }
};


// //  THIS IS MY SOLUTION TAKES MEMORY LIMIT EXCEED
// class Solution {
// public:
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         stack<pair<TreeNode*, string>> st;
//         st.push({root, ""});
//         pair<TreeNode*, string> curr;
//         int remainCount = 2;
//         string startStr;
//         string destStr;
//         while (!st.empty()) {
//             curr = st.top();
//             st.pop();
//             string path = curr.second;
//             TreeNode* node = curr.first;

//             if (curr.first->right != nullptr) {
//                 st.push(pair(node->right, path + 'R'));
//             }
//             if (node->left != nullptr) {
//                 st.push(pair(node->left, path + 'L'));                
//             }
            
//             if (startValue == node->val) {
//                 startStr = path;
//                 remainCount--;
//             } else if (destValue == node->val) {
//                 destStr = path;
//                 remainCount--;
//             }

//             if (remainCount == 0) break;
//             // cout << node->val << " " << path << endl;
//         }
//         // cout << node->val << " " << path << endl;


//         // To reach the node where start and dest nodes are separated
//         int idx = 0;
//         while (idx < min(startStr.size(), destStr.size())
//         && startStr[idx] == destStr[idx]) {
//             idx++;
//         }

//         string result = "";
//         // Go through parents
//         for (int i = 0; i < startStr.substr(idx).size(); ++i) {
//             result += 'U';
//         }

//         result += destStr.substr(idx);

//         return result;
//     }
// };
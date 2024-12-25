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
        queue<TreeNode*> q;
        if(root == NULL)   return {};
        q.push(root);
        vector<int> ans;

        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node -> left != NULL)  q.push(node->left);
                if(node->right != NULL)  q.push(node->right);
            }
            sort(level.begin(), level.end());
            reverse(level.begin(), level.end());

            cout << endl;
            ans.push_back(level[0]);
        }
        return ans;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int steps = 0;
        vector<vector<int>> ans;
        if(root == NULL)  return {};
        
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            steps++;
            for(int i=0;i<n;i++)
            {
                auto it = q.front();
                TreeNode* node = it;
                
                q.pop();

                if(node->left != NULL)  q.push(node->left);
                if(node->right != NULL)  q.push(node->right);
                level.push_back(node->val);
            }

            if(steps%2 == 0)  reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        return ans;

        
    }
};
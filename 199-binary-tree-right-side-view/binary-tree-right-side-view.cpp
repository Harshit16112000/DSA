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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if (!root) return {};
        q.push({root,0});
        vector<int> ans;

        map<int,int> mp;

        while(!q.empty())
        {
            auto it = q.front();
            int level = it.second;
            TreeNode* node = it.first;
            mp[level] = node->val;
            q.pop();
            if(node->left)  q.push({node->left, level + 1});
            if(node -> right)  q.push({node->right, level + 1});
        }
       
        for(auto [level,value]: mp)
        {
            ans.push_back(value);
        }
        return ans;
    }
};
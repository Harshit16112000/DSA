/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans, bool flag) {
        if(root == nullptr)  return;

        
        
        if(st.find(root->val) != st.end())
        {
                solve(root->left, st, ans,true);  
                solve(root->right, st, ans, true);    
        }
        else
        {
            if(flag)   ans.push_back(root);
            TreeNode* leftnode = root->left;
            TreeNode* rightnode = root->right;
            if(root->left)
            {
                if(st.find(root->left->val) != st.end())
                    root->left = nullptr; 
            }
            if(root->right)
            {
                if(st.find(root->right->val) != st.end())
                    root->right = nullptr; 
            }
            solve(leftnode, st, ans,false);
            solve(rightnode, st, ans,false);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        bool flag = false;
        for(auto it: to_delete)
        {
            st.insert(it);
        }
        solve(root, st, ans, true);
        return ans;
    }
};
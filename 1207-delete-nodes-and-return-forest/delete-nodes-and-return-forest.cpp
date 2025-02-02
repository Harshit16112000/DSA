class Solution {
public:
    TreeNode* solve(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        if (root == nullptr) return nullptr;

        root->left = solve(root->left, st, ans);
        root->right = solve(root->right, st, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            return nullptr;  // Delete this node by returning nullptr
        }
        
        return root;  // Keep this node
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        if (st.find(root->val) == st.end()) 
            ans.push_back(root);

        root = solve(root, st, ans);
        return ans;
    }
};

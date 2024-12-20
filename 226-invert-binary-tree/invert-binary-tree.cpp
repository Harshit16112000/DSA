class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr; // Base case: empty tree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            // Swap the left and right children
            swap(current->left, current->right);

            // Add non-null children to the queue
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        return root;
    }
};

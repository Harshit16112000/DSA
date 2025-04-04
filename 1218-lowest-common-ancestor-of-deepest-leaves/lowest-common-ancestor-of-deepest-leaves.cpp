class Solution {
public:
    // Step 1: Find the depth of the tree
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }

    // Step 2: Find LCA of the deepest leaves
    TreeNode* findLCA(TreeNode* root, int depth, int maxDepth) {
        if (!root) return nullptr;
        if (depth == maxDepth) return root; // If it's the deepest node, return it

        TreeNode* left = findLCA(root->left, depth + 1, maxDepth);
        TreeNode* right = findLCA(root->right, depth + 1, maxDepth);

        if (left && right) return root; // If both left and right have deepest nodes, return current node as LCA
        return left ? left : right; // Otherwise, return the non-null subtree
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = getDepth(root);
        return findLCA(root, 1, maxDepth);
    }
};

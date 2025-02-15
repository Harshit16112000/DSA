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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        diameter(root, res);
        return res-1;
    }

    int diameter(TreeNode *root, int& res)
    {
        if(root == NULL)  return 0;
        int left = diameter(root->left, res);
        int right = diameter(root->right, res);
          // It just passes the node to upper node
          int temp = 1 + max(left, right);

          // Can this node be ans
          int ans =  max(temp, 1 +  left + right);
          
          res = max(ans, res);
        return temp;
    }
};
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
    // TC is 0(N)
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        maxHeight(root, ans);
        return ans;
    }

    int maxHeight(TreeNode* root, bool &res)
    {
        if(root == NULL)  return 0;

        int lh = maxHeight(root-> left, res);
        int rh = maxHeight(root->right, res);
        
        int temp = 1 + max(lh, rh);

        if(abs(lh - rh) > 1) 
        {
            res = false;
            return -1;
        }

        return temp;   
    }
};
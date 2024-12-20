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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue< TreeNode*> q;
        int level = 0;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> vec;
            queue<TreeNode*> temp = q;
            for(int i=0 ;i<n;i++)
            {
                auto ele = q.front();
                q.pop();
                if(ele -> left)  {
                     q.push(ele->left);
                }
                if(ele-> right)   {
                    q.push(ele->right);
                }
                vec.push_back(ele->val);
            }
            if (level%2 != 0) {
                reverse(vec.begin(), vec.end());
                int i = 0;
                while (n--) {
                    auto it = temp.front();
                    temp.pop();
                    it->val = vec[i];
                    i++;
                }
            }
            level++;      
        }
        return root;   
    }
};
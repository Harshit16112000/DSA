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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        map<int, map<int, multiset<int> >> mpp;

        while(!q.empty())
        {
            auto it = q.front();
            TreeNode *node = it.first;
            int vertixes = it.second.first;
            int level = it.second.second;
            mpp[vertixes][level].insert(node->val);
            q.pop();
            if(node-> left) {
                q.push({node->left, {vertixes-1, level + 1}});
            }
            if(node -> right )
            {
                q.push({node->right, {vertixes+1, level + 1}});
            }
            
        }

        for(auto &[key,value] : mpp)
        {   
            cout << key << " ";
            for(auto &[key1, values1]: value)
            {
                cout << key1 << " ";
                for(auto it: values1)
                {
                    cout << it << " ";
                }
            }
            cout << endl;
        }

        for(auto it: mpp)
        {
            vector<int> col;
            for(auto i : it.second)
            {
                
                col.insert(col.end(), i.second.begin(), i.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
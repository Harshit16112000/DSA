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
    
     void DFS(TreeNode* root, vector<int> & st)
    {
        if(root == NULL)  return;
        DFS(root->left, st);
        st.push_back(root->val);
        DFS(root->right, st);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        DFS(root, nums);
        

        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            cout << nums[i] << " ";
        }

        for(auto query: queries)
        {
            auto lower = lower_bound(nums.begin(), nums.end(), query);
            
            int smaller = (lower == nums.begin()) ? -1 : *(lower - 1);
            int greater = (lower == nums.end()) ? -1 : *lower;

            if (greater == query) { 
                // If query matches exactly.
                ans.push_back({query, query});
            } else {
                // Push the closest smaller and greater values.
                ans.push_back({smaller, greater});
            }
        }
        
        return ans;
    }
};

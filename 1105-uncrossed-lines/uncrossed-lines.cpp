class Solution {
public:
    int solve(int id1, int id2, vector<int>& nums1, vector<int>& nums2,
              vector<vector<int>>& dp) 
    {
        if(id1 >= nums1.size() || id2 >= nums2.size())  return 0;

        if(dp[id1][id2] != -1)  return dp[id1][id2];

        int left = 0;
        int right = 0;
        if(nums1[id1] == nums2[id2])
            dp[id1][id2] =  1 + solve(id1+1, id2+1,nums1, nums2, dp);
        else {
             left = solve(id1+1, id2, nums1, nums2, dp);
             right = solve(id1, id2+1, nums1,nums2, dp);
        }

        dp[id1][id2] = max({dp[id1][id2], left, right});
        return dp[id1][id2];
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, nums1, nums2, dp);
    }
};
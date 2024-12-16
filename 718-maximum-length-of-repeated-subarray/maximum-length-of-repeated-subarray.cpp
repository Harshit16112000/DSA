class Solution {
public:
    int ans = 0;
     int solve(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2,
    vector<vector<int>> &dp)
    {
        if(idx1 >= nums1.size() || idx2 >= nums2.size()) return 0;
        
        if(dp[idx1][idx2] != -1)  return dp[idx1][idx2];

        if(nums1[idx1] == nums2[idx2])
           dp[idx1][idx2] = 1 + solve(nums1,nums2, idx1+1,idx2+1, dp);
        else
            dp[idx1][idx2] = 0;
        ans = max(ans, dp[idx1][idx2]);

        solve(nums1,nums2,idx1+1,idx2,dp);
        solve(nums1,nums2,idx1,idx2+1,dp);
        return dp[idx1][idx2];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
      
      

        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        solve(nums1, nums2,0,0,dp);
        return ans;
    }
};
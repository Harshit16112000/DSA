class Solution {
public:
    int ans = 0;
    int solve(int indx, vector<int>&nums, int cnt, int target, vector<unordered_map<int,int>> &dp)
    {
           
        if(indx == nums.size() ) 
        {
            return cnt == target ? 1 : 0;     
        }

        if(dp[indx].count(cnt))   return dp[indx][cnt];

        int minus = solve(indx+1,nums,cnt - nums[indx],target, dp);
        int add = solve(indx+1, nums, cnt + nums[indx], target, dp);
        return dp[indx][cnt] = add + minus;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt = 0;
        vector<unordered_map<int,int>> dp(nums.size());
        return solve(0,nums, cnt, target, dp);
        
    }
};
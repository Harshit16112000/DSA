class Solution {
public:
    int houseRouber(int index, vector<int>&dp, vector<int>& nums)
    {
        if(index >= nums.size())  return 0;

        if(dp[index] != -1)
        {
            return dp[index];
        }

        int pick = nums[index] + houseRouber(index+2, dp, nums);
        int non_pick = houseRouber(index+1, dp, nums);

        return dp[index] = max(pick, non_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);

        return houseRouber(0,dp, nums);

    }
};
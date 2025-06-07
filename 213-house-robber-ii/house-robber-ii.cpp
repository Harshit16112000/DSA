class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp (nums.size() -1, -1);
        if(nums.size() == 1)  return nums[0];
        dp[0] = nums[0];
        for(int i=1;i<=nums.size()-2;i++)
        {
            int pick = nums[i];
            if(i > 1)
            {
                pick += dp[i-2];
            }

            int nonPick = dp[i-1];

            dp[i] = max(pick, nonPick);
        }


        vector<int>dp2 (nums.size() -1, -1);
        dp2[0] = nums[1];
        for(int i=1;i<=nums.size()-2;i++)
        {
            int pick = nums[i+1];
            if(i > 1)
            {
                pick += dp2[i-2];
            }

            int nonPick = dp2[i-1];

            dp2[i] = max(pick, nonPick);
        }


        return max(dp[nums.size() - 2], dp2[nums.size() - 2]);
    }
};
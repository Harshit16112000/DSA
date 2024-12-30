class Solution {
public:
    vector<int> dp;
    int mod = 1e9+7;
    int solve(int low, int high, int zero, int one, int len)
    {
        if(len > high)   return 0;
        if(dp[len] != -1)  return dp[len];
        int check = 0;
        if(len >= low && len <= high)
        {
            check = 1;
        }
        
        int addZero = solve(low, high, zero, one, len + zero);
        int addOne = solve(low, high, zero, one, len+ one);
        return dp[len] = (check + addZero + addOne)%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        
        dp.assign(100001, -1);
        return solve(low,high, zero,one,0);    
    }
};
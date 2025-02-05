#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxi = INT_MAX;  // Store minimum number of clips

    void solve(int startIndex, int lastIndex, vector<vector<int>> &nums, int cnt, int time, vector<int>& dp) {
        if (lastIndex >= time) {  
            maxi = min(maxi, cnt);
            return;
        }

        if (dp[lastIndex] != -1 && dp[lastIndex] <= cnt) return;

        dp[lastIndex] = cnt; 
    

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][1] > lastIndex && nums[i][0] > startIndex && nums[i][0] <= lastIndex) {
                cnt = cnt + 1;
                solve(nums[i][0], nums[i][1], nums,cnt , time, dp);
                cnt--;  
            }
        }
    }

    int videoStitching(vector<vector<int>>& nums, int time) {
        sort(nums.begin(), nums.end());
        vector<int> dp(time +1, -1);
        if (nums[0][0] != 0) return -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][0] == 0) {
                solve(nums[i][0], nums[i][1], nums, 1, time, dp);
            }
        }

        return (maxi == INT_MAX) ? -1 : maxi;
    }
};


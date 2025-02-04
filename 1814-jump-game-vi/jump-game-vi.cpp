#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i < n; i++) {
            // Remove indices that are out of the window size `k`
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            // The max value from `dp[dq.front()]` gives the best path sum
            dp[i] = nums[i] + dp[dq.front()];

            // Maintain the deque in decreasing order (monotonic queue)
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return dp[n - 1];
    }
};

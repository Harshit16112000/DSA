class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> pSum(nums.size() + 1, 0);
        
        // Compute prefix sums
        for (int i = 1; i <= nums.size(); i++) {
            pSum[i] = pSum[i - 1] + nums[i - 1];
        }

        map<int, long long> mp;
        long long ans = LLONG_MIN;

        mp[0] = 0; // Initialize with base case

        for (int i = 1; i <= nums.size(); i++) {
            int mod = i % k;

            if (mp.find(mod) != mp.end()) {
                ans = max(ans, pSum[i] - mp[mod]);
            }

            if (mp.find(mod) == mp.end()) {
                mp[mod] = pSum[i];
            } else {
                mp[mod] = min(mp[mod], pSum[i]);
            }
        }

        return ans;
    }
};

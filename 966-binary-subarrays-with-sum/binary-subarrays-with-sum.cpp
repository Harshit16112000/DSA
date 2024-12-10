class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        
        for(auto it : nums)
        {
            prefixSum += it;

            if(freq.find(prefixSum - goal) != freq.end())
                ans += freq[prefixSum - goal];
            freq[prefixSum]++;
        }

        return ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0;
        int r = 0;
        long long ans = 0;
        long long sum = 0;
        long long cnt = 0;
        while(r < nums.size())
        {
            sum += nums[r];
            long long multi = sum * (r- l + 1);
            
            while(multi >= k)
            {
                sum = sum - nums[l];
                l++;
                multi = sum * (r - l + 1);
                
            }
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }
};
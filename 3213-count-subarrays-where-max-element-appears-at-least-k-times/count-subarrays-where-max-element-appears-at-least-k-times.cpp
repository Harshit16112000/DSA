class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max((long long)nums[i], maxi);
        }

        long long l = 0;
        long long r = 0;
        long long cnt = 0;
        long long temp = 0;
        while(r < nums.size())
        {
            if(nums[r] == maxi) 
            temp++; 
            while(temp >= k)
            {
                cnt += (nums.size() - r);
                
                if(nums[l] == maxi) temp--;
                l++;
            }

            r++; 
        }
        return cnt;
    }
};
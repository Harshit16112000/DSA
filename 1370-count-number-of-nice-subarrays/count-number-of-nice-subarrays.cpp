class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;

        int pSum = 0;
        
        mp[0] = 1;
        int ans = 0;

        for(int i=0;i<nums.size();i++)
        {
            pSum += nums[i] % 2;
            if(mp.contains(pSum - k))
              ans += mp[pSum - k];

            
            mp[pSum]++;
        }

        

        return ans;
    }
};
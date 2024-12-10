class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // https://leetcode.com/problems/continuous-subarray-sum/solutions/5276981/prefix-sum-hashmap-patterns-7-problems/
        map<int,int> mp;
        mp[0] = 0;
        int sum = 0;

        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int ans = sum%k;
            

            if(!mp.contains(ans))
                mp[ans] = i + 1;
            else {
                if(i - mp[ans] + 1 >= 2)  return true;
            }
        }
        return false;
    }
};
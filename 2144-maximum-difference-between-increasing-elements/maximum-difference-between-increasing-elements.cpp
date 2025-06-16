class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        vector<int> maxi(nums.size(), 0);
        maxi[nums.size()-1] = nums[nums.size() -1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            int maxim = max(nums[i], maxi[i+1]);
            maxi[i] = maxim;
        }



        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            ans = max(maxi[i] - nums[i] , ans);
        }
        if(ans == 0)  return -1;
        return ans;
    }
};
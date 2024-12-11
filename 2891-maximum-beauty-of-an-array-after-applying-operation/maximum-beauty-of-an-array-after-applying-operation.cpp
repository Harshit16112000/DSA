class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            int ele = nums[i];
            mp[ele-k]++;
            mp[ele+k+1]--;
        }

        int cnt = 0;
        int sum = 0;
        for(auto &[key,value] : mp)
        {
            sum += value;
            cnt = max(cnt, sum);
        }
        return cnt;
    }
};
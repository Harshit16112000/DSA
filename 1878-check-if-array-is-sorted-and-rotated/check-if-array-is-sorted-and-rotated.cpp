class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return true;
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        int cnt = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] >= nums[i-1])
               cnt++;   
            else
               cnt = 1;
            //cout << cnt << " ";
            if(cnt == n) return true;
        }
        return false;
    }
};
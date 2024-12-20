class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = pattern.size() + 1;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(j-i+1 != n)  continue;
                int l = 0;
                bool match = true;
                for(int k=0;k<pattern.size();k++)
                {
                    if(pattern[k] == 0 && nums[i+l] == nums[i+l+1])  l++;
                    else if(pattern[k] == 1 && nums[i+l] < nums[i+l+1]) l++;
                    else if(pattern[k] == -1 && nums[i+l] > nums[i+l+1]) l++;
                    else match = false;
                }
                if(match)  ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int inccount = 0;
        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }

        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] <= nums[i+1])
            {
                inccount++;
                maxi = max(maxi, inccount);
            }
            else {
                inccount = 0;
            }
        }
        //cout << maxi;
        if(maxi >= n-1)  return true;
        return false;
        

        
    }
};
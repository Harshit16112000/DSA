class Solution {
public:

    bool check(int mid,vector<int>nums,int maxOperation)
    {
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            // Done as 5 is deivided into 2,3 where cnt is 2, but here we need the cnt as 1.          
            // As, 7/5 result in 1. To need floating value. we need to do (double)

            cnt +=  ceil((double)nums[i]/mid);
            cnt--;
            
            // Other way to do it 
            // cnt += (nums[i] -1)/mid;
            if(cnt > maxOperation)  return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = 0;
        cout << 7/5 << " " << 17/5 << " ";
        for(int i=0;i<nums.size();i++) 
        {
            r = max(r, nums[i]);
        }
        int ans = 0;
        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(check(mid,nums,maxOperations))   
            {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
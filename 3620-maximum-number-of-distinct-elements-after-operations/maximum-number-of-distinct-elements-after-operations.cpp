class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
     sort(nums.begin(), nums.end());
     int cnt = 0;
     int end = INT_MIN;    
     for(int i=0;i<nums.size();i++)
     {
        int l = nums[i] - k;
        int r = nums[i] + k;

        if(end < l)
           {
            end = l;
            cnt++;
           }
        else if(end < r) 
        {
           end++;
           cnt++;
        }
     }   

    return cnt;
    }
};
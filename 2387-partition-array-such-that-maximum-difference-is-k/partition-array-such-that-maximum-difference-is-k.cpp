class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
     int cnt = 0;
     sort(nums.begin(), nums.end());

     int index = 0;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i] - nums[index] > k)
        {
            index = i;
            cnt++;
        }   
    }
    
    return cnt + 1;
    }
};
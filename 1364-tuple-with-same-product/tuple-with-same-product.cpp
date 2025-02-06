class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n  = nums.size();
     sort(nums.begin(), nums.end());
     
     unordered_map<int,int> mpp;
     for(int i=0;i<nums.size();i++)
     {
        for(int j=i+1;j<nums.size();j++)
        {
            int product = nums[i] * nums[j];
            mpp[product]++;
        }
     }

    int cnt = 0;
     for(auto [key,value]: mpp)
     {
          if(value > 1)
             cnt += (value * (value - 1) / 2) * 8;
     }

     return cnt;
    }
};
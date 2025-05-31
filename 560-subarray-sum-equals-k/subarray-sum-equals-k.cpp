class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> mpp;

      mpp[0] = 1;
      int cnt = 0;
      int sum = 0;
      for(auto it: nums)
      {
            sum += it;
          if(mpp.contains(sum - k))
          {
                cnt += mpp[sum-k];
          }
          
          mpp[sum]++;

          
      } 

    

      return cnt;
    }
};
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
      set<int> st;
      for(int i=0;i<nums.size();i++)
      {
        st.insert(nums[i]);
      }

      int l = 0;
      int r = 0;
      int n = nums.size();
      int k = st.size();
      unordered_map<int,int> mpp;
      int cnt = 0;  
      while(r < n)
      {
            mpp[nums[r]]++;
            while(mpp.size() == st.size())
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                  mpp.erase(nums[l]);
                l++;
                cnt = cnt + (n-r);
            }
            
            r++;
      }
      return cnt;  
    }
};
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
       int n = nums.size();

       vector<int> increasingFromLeft(n,0);
       vector<int> decreasingFromRight(n,0);

       increasingFromLeft[0] = 0;
       for(int i=1;i<increasingFromLeft.size();i++)
       {
            if (nums[i] <= nums[i - 1]) {
                increasingFromLeft[i] = increasingFromLeft[i - 1] + 1;
            }
       }

       
       for(int i=n-2;i>=0;i--)
       {
           if(nums[i] <= nums[i+1])
           {
            decreasingFromRight[i] = decreasingFromRight[i+1] + 1;
           }
        
       }

        vector<int> ans;
       for(int i=time;i<n-time;i++)
       {
            if(decreasingFromRight[i] >= time && increasingFromLeft[i] >= time)
              ans.push_back(i);
       }

       return ans;

    }
};
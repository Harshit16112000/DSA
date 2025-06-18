class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i=i+3)
        {
            if(nums[i+2] - nums[i] > k)
            {
                return {};
            }
        }

        vector<vector<int>> ans;

        vector<int> result;
        result.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            
            if(i%3 ==0 )  {
                ans.push_back(result);
                result.clear();
                result.push_back(nums[i]);    
            }
            else {      
            result.push_back(nums[i]);
            }
        }
        ans.push_back(result);
        return ans;
    }
};
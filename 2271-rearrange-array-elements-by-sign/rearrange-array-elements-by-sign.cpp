class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> negativenums;
        vector<int> positivenums;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= 0)  positivenums.push_back(nums[i]);
            else  negativenums.push_back(nums[i]);
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i%2 == 0)   ans.push_back(positivenums[i/2]);
            else  ans.push_back(negativenums[i/2]);
        }

        return ans;

    }
};
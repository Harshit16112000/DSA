class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        if(nums.size() == 0 )  return result;
        int lowerInd = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lowerInd < nums.size()) {
            if (nums[lowerInd] == target)
                result[0] = lowerInd;
        }

        int upperInd = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(upperInd > 0 && nums[upperInd -1] == target)   result[1] = upperInd-1;

        return result;
    }
};
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--)
        {
            int smallerElement = nums[0];
            int index = 0;
            for(int i=1;i<nums.size();i++)
            {
                 if(smallerElement > nums[i])
                 {
                    smallerElement = nums[i];
                    index = i;
                 }
            }

            nums[index] = smallerElement * multiplier;
        }

        return nums;
    }
};
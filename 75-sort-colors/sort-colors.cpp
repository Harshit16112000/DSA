class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Int Low to get first value of Zero
        int low = 0;
        // Int mid to get first value of One
        int mid = 0;
        // Int high to get first value of Zero
        int high = nums.size() -1 ;

        while(mid <= high)
        {
            if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 0)
            {
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
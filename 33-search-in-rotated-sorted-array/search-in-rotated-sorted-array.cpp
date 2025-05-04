class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            cout << nums[mid] << " ";
            if(nums[mid] == target)  return mid;
            if(nums[low] <= nums[mid])  // left side is sorted
            {
                if(nums[low] <= target && target <= nums[mid]) 
                // Target is within the sorted range.
                // if(nums[low] <= target <= nums[mid])  
                // Equivalent to this
                {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else { // Right Side is sorted
                // Target is within the sorted range
                // if(nums[mid] <= target <= nums[high])
                if(nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
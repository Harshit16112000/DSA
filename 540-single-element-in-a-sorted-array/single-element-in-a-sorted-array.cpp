class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid = low + (high-low)/2;
            
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(mid%2 == 0)
            {
                if(mid >0 && nums[mid] == nums[mid-1])
                {
                    high = mid - 1;    
                }
                else {
                    low = mid + 1;
                }
            }else {
                if(mid > 0 && nums[mid] == nums[mid-1])
                {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
            return nums[low-1];   
        
    }
};
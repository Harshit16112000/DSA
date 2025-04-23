class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int temp = k;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                    temp--;
                
            }  
            while (temp < 0) {
                if (nums[l] == 0) temp++;  // recover a flip
                l++;
            }
            
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        //if (n < 3) return 0; // A triplet is not possible

        vector<int> i(n,0);
        vector<int> k(n,0);  // Max values from j+1 to n-1

        // Compute i[j]: max value from index 0 to j-1
        i[0] = nums[0];
        for (int j = 1; j < n; j++) {
            i[j] = max(i[j - 1], nums[j - 1]);
        }

        // Compute k[j]: max value from index j+1 to n-1
        k[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            k[j] = max(k[j + 1], nums[j + 1]);
        }

        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {        
            long long sum = (long long)(i[j] - nums[j]) * k[j];
            ans = max(ans, sum);
            
        }

        return ans;
    }
};

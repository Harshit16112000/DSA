class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            primes(nums[i], st);
        }
        return st.size();
    }

    void primes(int n, set<int>& st) {
                // Handle factor 2
        

        // Handle odd factors from 3 to sqrt(n)
        for (int i = 2; i  <= n; i += 1) {
            while (n % i == 0) {
                st.insert(i);
                n /= i;
            }
        }

        if (n > 2) {
            st.insert(n);
        }
    }
};
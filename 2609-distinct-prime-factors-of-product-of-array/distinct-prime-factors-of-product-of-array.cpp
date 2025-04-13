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
        for (int i = 2; i * i <= n; i ++) {
            while (n % i == 0) {
                st.insert(i);
                n /= i;
            }
        }

        if (n != 1) st.insert(n);
    }
};
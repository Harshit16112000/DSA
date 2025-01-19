#define ll long long
const int MOD = 1e9 + 7;
vector<ll> fact, invFact;

// With the help of Fermi Therom, we are calculating InverseFactorial
// InvFac(i) = invfac(i+1) * (i+1)

// base power exp == 1%mod
ll modPow(ll base, ll exp, int mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % mod;
        base = base * base % mod;
        exp = exp >> 1;
    }
    cout << result << " ";
    return result;
}

void computeFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = invFact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[n] = modPow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 1; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r > n || r < 0)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        computeFactorials(n);
        ll result = 0;
         for (int size = 1; size <= k; size++) {
        for (int i = 0; i < n; i++) {
            
                ll minContribution = nums[i] * nCr(n - i - 1, size - 1) % MOD;
                ll maxContribution = nums[i] * nCr(i, size - 1) % MOD;
                result = (result + minContribution + maxContribution) % MOD;
            }
        }
        return (int)result;
    }
};